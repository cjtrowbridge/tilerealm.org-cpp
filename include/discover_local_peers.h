#ifndef DISCOVER_LOCAL_PEERS_H
#define DISCOVER_LOCAL_PEERS_H

#include <vector>
#include <string>

// Discovers other peers on the local network that are running the game.
// This function returns a list of discovered peers.
std::vector<std::string> discoverLocalPeers();

#endif // DISCOVER_LOCAL_PEERS_H
