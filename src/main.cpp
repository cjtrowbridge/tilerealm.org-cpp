#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <nlohmann/json.hpp>
#include <fstream>
#include <unistd.h>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

// Include module headers
#include "load_configuration.h"
#include "server.h"
#include "signals.h"
#include "logging.h"
#include "helpers.h"
#include "state.h"
#include "help.h"

#include "generate_default_realm.h"

// These need their own thread
#include "discover_local_peers.h"
#include "discover_remote_peers.h"


// Function prototypes
void displayHelp();

// Main function
int main(int argc, char* argv[]) {
    std::string bindAddress = "127.0.0.1";  // Default bind address
    int port = 8080;  // Default port
    std::string realmsFilePath = "./realms.json";  // Default path to realms.json

    // Process command line arguments
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--bind" && i + 1 < argc) {
            bindAddress = argv[++i];
        } else if (arg == "--port" && i + 1 < argc) {
            port = std::stoi(argv[++i]);
        } else if (arg == "--realms" && i + 1 < argc) {
            realmsFilePath = argv[++i];
        } else {
            std::cerr << "Unknown argument: " << arg << std::endl;
            displayHelp();
            return 1;
        }
    }

    
    // Check if the realms file exists; if not, generate a default one
    std::ifstream fileCheck(realmsFilePath);
    if (!fileCheck.good()) {
        std::cerr << "Realms file not found at " << realmsFilePath << ". Generating default realms file..." << std::endl;
        generateDefaultRealm(realmsFilePath);
    } else {
        fileCheck.close();
    }

    // Initialize the server
    initializeServer(bindAddress, port, realmsFilePath);


    // Main loop (can be expanded as needed)
    while (true) {
        int clientSocket = 0; // Placeholder for client socket
        handleClientRequest(clientSocket);

        // Update the state of the realms periodically
        updateRealmState();

        // Manage log size
        manageLogSize();

        //Check if we need to exit
        if (exitRequested()) {
            break;
        }
    }

    // Shutdown the server gracefully
    shutdownServer();

    return 0;
}

