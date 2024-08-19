#ifndef GENERATE_DEFAULT_REALM_H
#define GENERATE_DEFAULT_REALM_H

#include <string>

// Generates a default realms JSON file at the specified path.
// This function is called if no realms file is found at startup.
void generateDefaultRealm(const std::string& filePath);

#endif // GENERATE_DEFAULT_REALM_H
