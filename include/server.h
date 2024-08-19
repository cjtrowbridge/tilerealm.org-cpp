#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <unordered_map>

// Initializes the server with the given bind address, port, and realms path.
// This function sets up the necessary resources and configurations
// to prepare the server for accepting incoming connections.
void initializeServer(const std::string& bindAddress, int port, const std::string& realmsFilePath);

// Handles an individual client request after a connection has been accepted.
// This function reads the request, processes it, and sends an appropriate response.
void handleClientRequest(int clientSocket);

// Sends a response back to the client over the specified socket.
// The response is typically an HTTP response string.
void sendResponse(int clientSocket, const std::string& response);

// Sends an error response back to the client.
// This is used when an error occurs while processing the client's request.
void sendErrorResponse(int clientSocket, int errorCode, const std::string& errorMessage);

// Handles API calls by routing the request to the appropriate handler
// based on the route specified in the client's request.
void handleApiCall(const std::string& route, int clientSocket);

// Handles requests to the root route ("/").
// This function typically returns the web front-end or a welcome message.
std::string handleRootRoute();

// Handles requests to the "/realms" route, returning realm data.
// This function typically returns the current state of the realms as JSON.
std::string handleRealmRoute();

// Handles requests to the "/peers" route, returning peer information.
// This function returns a list of peers on the local network and over the internet.
std::string handlePeersRoute();

// Parses the HTTP request method (e.g., GET, POST) from the client's request.
// This function returns the method as a string.
std::string parseRequestMethod(const std::string& request);

// Parses the request path from the client's request.
// This function returns the path as a string (e.g., "/realms").
std::string parseRequestPath(const std::string& request);

// Parses the HTTP headers from the client's request and returns them
// as a key-value map. This is used to process the request headers.
std::unordered_map<std::string, std::string> parseRequestHeaders(const std::string& request);

// Parses the body of the client's request.
// This function returns the body as a string.
std::string parseRequestBody(const std::string& request);

#endif // SERVER_H
