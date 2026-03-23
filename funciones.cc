#include <iostream>
void help(){
  std::cout << "=== USO DEL PROGRAMA ===\n\n";
            std::cout << "Opciones de línea de comandos:\n";
            std::cout << "  -ts <s>        Tamaño de la tabla (s es un número entero)\n";
            std::cout << "  -bs <s>        Tamaño del bloque (solo hash cerrado)\n";
            std::cout << "  -fd <f>        Función de dispersión a usar (f es un código)\n";
            std::cout << "  -fe <f>        Función de exploración a usar (solo hash cerrado)\n";
            std::cout << "  -hash <open|close>  Tipo de dispersión (abierta o cerrada)\n";
            std::cout << "  -h | -help     Muestra esta ayuda\n\n";

            std::cout << "Funciones de dispersión:\n";
            std::cout << "  modulo : 1\n";
            std::cout << "  sum    : 2\n";
            std::cout << "  random : 3\n\n";

            std::cout << "Funciones de exploración (solo hash cerrado):\n";
            std::cout << "  lineal           : 1\n";
            std::cout << "  cuadratica       : 2\n";
            std::cout << "  dobleDispersion  : 3\n";
            std::cout << "  redispersion     : 4\n";
    std::exit(0);
}