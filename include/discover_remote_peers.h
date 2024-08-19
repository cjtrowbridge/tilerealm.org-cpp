#ifndef DISCOVER_REMOTE_PEERS_H
#define DISCOVER_REMOTE_PEERS_H

#include <vector>
#include <string>

// Discovers remote peers that are accessible over the internet.
// This function returns a list of discovered peers.
std::vector<std::string> discoverRemotePeers();

#endif // DISCOVER_REMOTE_PEERS_H
