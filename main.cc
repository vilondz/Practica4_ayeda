#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <cstdlib>

#include "HashTable.h"
#include "DispersionFunction.h"
#include "ModuloDispersion.h"
#include "ExplorationFunction.h"
#include "LinealExploration.h"
#include "CuadraticExploration.h"
#include "DobleDispersionExploration.h"
#include "RedispersionExploration.h"
#include "SumDispersion.h"
#include "RandomDispersion.h"
#include "nif.h"
#include "funciones.cc"

int main(int argc, char *argv[])
{
	using key_type = nif;
	unsigned tableSize = 10;
	unsigned blockSize = 3;
	int fd_code = 1; // dispersión por defecto
	int fe_code = 1; // exploración por defecto
	std::string hashType = "close";

	// Parsear argumentos
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		if(arg == "-h" || arg == "-help")
			help(); 
		else if (arg == "-ts" && i + 1 < argc)
			tableSize = std::stoi(argv[++i]);
		else if (arg == "-bs" && i + 1 < argc)
			blockSize = std::stoi(argv[++i]);
		else if (arg == "-fd" && i + 1 < argc)
			fd_code = std::stoi(argv[++i]);
		else if (arg == "-fe" && i + 1 < argc)
			fe_code = std::stoi(argv[++i]);
		else if (arg == "-hash" && i + 1 < argc)
			hashType = argv[++i];
	}

	// Crear función de dispersión
	std::unique_ptr<DispersionFunction<key_type>> fd;
	switch (fd_code)
	{
	case 1:
		fd = std::make_unique<ModuloDispersion<key_type>>(tableSize);
		break;
	case 2:
		fd = std::make_unique<SumDispersion<key_type>>(tableSize);
		break;
	case 3:
		fd = std::make_unique<RandomDispersion<key_type>>(tableSize);
		break;
	default:
		fd = std::make_unique<ModuloDispersion<key_type>>(tableSize);
		break;
	}

	// Crear función de exploración (solo para hash cerrado)
	std::unique_ptr<ExplorationFunction<key_type>> fe;
	if (hashType == "close")
	{
		switch (fe_code)
		{
		case 1:
			fe = std::make_unique<LinealExploration<key_type>>();
			break;
		case 2:
			fe = std::make_unique<CuadraticExploration<key_type>>();
			break;
		case 3:
			fe = std::make_unique<DobleDispersionExploration<key_type>>(*fd);
			break;
		case 4:
			fe = std::make_unique<RedispersionExploration<key_type>>();
			break;
		default:
			fe = std::make_unique<LinealExploration<key_type>>();
			break;
		}
	}

	if (hashType == "close")
	{
		HashTable<key_type> hashClosed(tableSize, *fd, *fe, blockSize);

		int opcion = 0;
		do
		{
			std::cout << "\n=== MENÚ HASH CERRADA ===\n";
			std::cout << "1. Insertar clave\n";
			std::cout << "2. Buscar clave\n";
			std::cout << "3. Mostrar tabla\n";
			std::cout << "4. Introducir aleatorio\n";
			std::cout << "0. Salir\n";
			std::cout << "Opción: ";
			std::cin >> opcion;

			if (opcion == 1)
			{
				nif valor;
				std::cout << "Introduce clave a insertar: ";
				std::cin >> valor;
				if (hashClosed.insert(valor))
					std::cout << "Clave insertada correctamente.\n";
				else
					std::cout << "No se pudo insertar la clave.\n";
			}
			else if (opcion == 2)
			{
				nif valor;
				std::cout << "Introduce clave a buscar: ";
				std::cin >> valor;
				if (hashClosed.search(valor))
					std::cout << "Clave encontrada.\n";
				else
					std::cout << "Clave no encontrada.\n";
			}
			else if (opcion == 3)
			{
				hashClosed.print();
			}
			else if (opcion == 4)
			{
				nif aleatorio;
				std::cout << "introduciendo :" << aleatorio <<std::endl;
				hashClosed.insert(aleatorio);
			}
		} while (opcion != 0);
	}
	else
	{ // open
		HashTable<key_type, DinamicSequence<key_type>> hashOpen(tableSize, *fd);

		int opcion = 0;
		do
		{
			std::cout << "\n=== MENÚ HASH ABIERTA ===\n";
			std::cout << "1. Insertar clave\n";
			std::cout << "2. Buscar clave\n";
			std::cout << "3. Mostrar tabla\n";
			std::cout << "4. Introducir aleatorio\n";
			std::cout << "0. Salir\n";
			std::cout << "Opción: ";
			std::cin >> opcion;

			if (opcion == 1)
			{
				nif valor;
				std::cout << "Introduce clave a insertar: ";
				std::cin >> valor;
				if (hashOpen.insert(valor))
					std::cout << "Clave insertada correctamente.\n";
				else
					std::cout << "No se pudo insertar la clave.\n";
			}
			else if (opcion == 2)
			{
				nif valor;
				std::cout << "Introduce clave a buscar: ";
				std::cin >> valor;
				if (hashOpen.search(valor))
					std::cout << "Clave encontrada.\n";
				else
					std::cout << "Clave no encontrada.\n";
			}
			else if (opcion == 3)
			{
				hashOpen.print();
			}
			else if (opcion == 4)
			{
				nif aleatorio;
				std::cout << "introduciendo :" << aleatorio <<std::endl;
				hashOpen.insert(aleatorio);
			}
		} while (opcion != 0);
	}
	return 0;
}