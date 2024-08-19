#ifndef SIGNALS_H
#define SIGNALS_H

// Gracefully shuts down the server, closing all open connections
// and releasing any resources that were allocated during its operation.
void shutdownServer();

// Handles OS signals like SIGINT (Ctrl+C) to shut down the server gracefully.
// This ensures that the server can exit cleanly when receiving a termination signal.
void handleSignal(int signal);

//Check if an exit signal has been received to exit the main loop
bool exitRequested();


#endif // SIGNALS_H
