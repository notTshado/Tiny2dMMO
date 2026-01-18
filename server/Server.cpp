#include "Server.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>


int numplayers = 2;


void Server::run() {
	
	std::cout << "Enter number of players to simulate (up to 50):";
	std::cin >> numplayers;
if (numplayers < 2)
	numplayers = 2;
	if (numplayers > 50)
		numplayers = 50;

for (int i = 1; i <= numplayers; i++) {
		InputPacket startPackets{};
		startPackets.playerid = i;
		startPackets.movex = static_cast<float>((std::rand() % 201) - 100); // Random start position between -100 and 100
		startPackets.movey = static_cast<float>((std::rand() % 201) - 100); 
		jessicaalba.applyinput(startPackets); // Initialize player positions
}
	std::srand(std::time(nullptr)); // seed random number generator
	while (true) {
		tick();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // 1 tick per second
	}
}

void Server::tick() {
	tickcount++;
	//simulate receiving an input packet
	for (int i = 1; i <= numplayers; i++) {
		InputPacket input{};
		input.playerid = i;
		input.movex = static_cast<float>((std::rand() % 201) - 100); /// Random start position between -100 and 100
		input.movey = static_cast<float>((std::rand() % 201) - 100); 
		jessicaalba.applyinput(input);
	}

jessicaalba.checkcollisions();

for (int i = 1; i <= numplayers; i++) {
	const Player& player = jessicaalba.getplayer(i);
	std::cout << "Player " << i << " Position: (" << player.position.x << ", " << player.position.y << ")\n";
}

}