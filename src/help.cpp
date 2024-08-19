#include "help.h"
#include <iostream>

// Implementation of the displayHelp function
void displayHelp() {
    std::cout << "TileRealm Server\n";
    std::cout << "Usage: tilerealm_server [options]\n";
    std::cout << "Options:\n";
    std::cout << "  --bind <address>      Bind the server to the specified address (default: 127.0.0.1)\n";
    std::cout << "  --port <port>         Use the specified port (default: 8080)\n";
    std::cout << "  --realms <file>       Path to the realms.json file (default: ./realms.json)\n";
    std::cout << "  --help, -h            Display this help message and exit\n";
}
