#include "generate_default_realm.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

// Generates a default realms JSON file at the specified path.
// This function is called if no realms file is found at startup.
void generateDefaultRealm(const std::string& filePath) {
    // Create a default realms.json file with basic initial data.
    nlohmann::json defaultRealm = {
        {"name", "default"},
        {"description", "This is the default realm."},
        {"grid", std::vector<std::vector<int>>(10, std::vector<int>(10, 0))}
    };
    std::ofstream outFile(filePath);
    if (outFile) {
        outFile << defaultRealm.dump(4);  // Write with indentation of 4 spaces
        outFile.close();
    } else {
        std::cerr << "Error: Could not create default realms file at " << filePath << std::endl;
    }
}
