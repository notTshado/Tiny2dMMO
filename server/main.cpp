#include "Server.h"
#include <iostream>
int main() {
	Server server;
	std::cout << "Starting server..." << std::endl;
	server.run();
	return 0;
}