#include <iostream>
#include "corge.h"

int
main(int argc, char* argv[])
{
    std::cout << "corgerator called with ";
    if (argc == 0) {
        std::cout << "no command-line arguments\n";
    } else {
        std::cout << "command-line arguments:";
        for (int i = 0; i < argc; ++i) {
            std::cout << " \"" << argv[i] << "\"";
        }
        std::cout << "\n";
    }
    std::cout << "corgegating..\n";
    Corge corge;
    corge.corgegate();
    std::cout << "done.\n";
    return 0;
}
