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

int main(int argc, char* argv[]) {
    unsigned tableSize = 10;
    unsigned blockSize = 3;
    int fd_code = 1;   // dispersión por defecto
    int fe_code = 1;   // exploración por defecto
    std::string hashType = "close";

    // Parsear argumentos
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-ts" && i+1 < argc) tableSize = std::stoi(argv[++i]);
        else if (arg == "-bs" && i+1 < argc) blockSize = std::stoi(argv[++i]);
        else if (arg == "-fd" && i+1 < argc) fd_code = std::stoi(argv[++i]);
        else if (arg == "-fe" && i+1 < argc) fe_code = std::stoi(argv[++i]);
        else if (arg == "-hash" && i+1 < argc) hashType = argv[++i];
    }

    // Crear función de dispersión
    std::unique_ptr<DispersionFunction<int>> fd;
    switch(fd_code) {
        case 1: fd = std::make_unique<ModuloDispersion<int>>(tableSize); break;
        case 2: fd = std::make_unique<SumDispersion<int>>(tableSize); break;
        case 3: fd = std::make_unique<RandomDispersion<int>>(tableSize); break;
        default: fd = std::make_unique<ModuloDispersion<int>>(tableSize); break;
    }

    // Crear función de exploración (solo para hash cerrado)
    std::unique_ptr<ExplorationFunction<int>> fe;
    if(hashType == "close") {
        switch(fe_code) {
            case 1: fe = std::make_unique<LinealExploration<int>>(); break;
            case 2: fe = std::make_unique<CuadraticExploration<int>>(); break;
            case 3: fe = std::make_unique<DobleDispersionExploration<int>>(*fd); break;
            case 4: fe = std::make_unique<RedispersionExploration<int>>(); break;
            default: fe = std::make_unique<LinealExploration<int>>(); break;
        }
    }

    // Crear la tabla hash
    if(hashType == "close") {
        HashTable<int> hashClosed(tableSize, *fd, *fe, blockSize);
        hashClosed.insert(10);
        hashClosed.insert(20);
        hashClosed.insert(30);
        hashClosed.insert(40);
        hashClosed.insert(99);
        hashClosed.print();
    } else { // open
        HashTable<int, DinamicSequence<int>> hashOpen(tableSize, *fd);
        hashOpen.insert(10);
        hashOpen.insert(20);
        hashOpen.insert(30);
        hashOpen.insert(40);
        hashOpen.insert(99);
        hashOpen.print();
    }

    return 0;
}