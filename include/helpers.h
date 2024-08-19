#ifndef HELPERS_H
#define HELPERS_H

#include <string>

// Validates the input to ensure it meets the expected format or constraints.
// This function is used to prevent security vulnerabilities.
bool validateInput(const std::string& input);

// Reads the contents of a file from the specified path and returns it as a string.
// This function is useful for serving static files or loading data.
std::string readFile(const std::string& filePath);

// Trims whitespace from the beginning and end of a string.
// This is useful for cleaning up user input or request data.
std::string trim(const std::string& str);

// Converts a string to lowercase.
// This is useful for case-insensitive comparisons or processing.
std::string toLowerCase(const std::string& str);

#endif // HELPERS_H
