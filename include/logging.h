#ifndef LOGGING_H
#define LOGGING_H

#include <string>

// Logs a general activity or event in the server's operation.
// This is useful for tracking what the server is doing at any given time.
void logActivity(const std::string& activity);

// Logs an error that occurs during the server's operation.
// This function should provide details about what went wrong.
void logError(const std::string& error);

// Manages the size of the log files to ensure they don't grow too large.
// This function may rotate logs or truncate them if necessary.
void manageLogSize();

#endif // LOGGING_H
