#ifndef STATE_H
#define STATE_H

#include <string>
#include <nlohmann/json.hpp>

// Loads the realms from the specified JSON file, instantiating the current state from disk.
// If the file is not found or cannot be read, appropriate errors are logged, and it tries again.
void loadRealms(const std::string& filePath);

// Returns a JSON string representing the current state of the realms.
// This is used to respond to client requests for realm data.
std::string stateJson();

// Periodically updates the state of the realms.
// This function applies any game logic or actions that need to be executed regularly.
void updateRealmState();

// Reads the current state from the realms.json file.
// Returns a JSON object representing the current state.
nlohmann::json readState();

// Writes the updated state to the realms.json file.
// This function should ensure the write operation is atomic to avoid corruption.
void writeState(const nlohmann::json& state);

// Attempts to perform an action (e.g., move a player) based on the provided parameters.
// Reads the current state, checks if the action is possible, updates the state if valid,
// and returns the updated state. If the action is not possible, returns the original state.
nlohmann::json attemptAction(const std::string& action, const nlohmann::json& parameters);

// Utility function to handle the atomic write to the realms.json file.
// This function writes to a temporary file first and then renames it to ensure atomicity.
void atomicWriteState(const std::string& filePath, const nlohmann::json& state);

#endif // STATE_H
