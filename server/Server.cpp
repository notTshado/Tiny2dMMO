#include "Server.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

void Server::run() {
	std::srand(std::time(nullptr)); // seed random number generator
	while (true) {
		tick();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	}

void Server::tick() {
	tickcount++;
	//simulate receiving an input packet
	InputPacket input{};
	input.playerid = 1; 
	input.movex = static_cast<float>(std::rand() % 21 - 10); //random value between -10 and 10
	input.movey = static_cast<float>(std::rand() % 21 - 10);

	jessicaalba.applyinput(input);
	
	input.playerid = 2;
	input.movex = static_cast<float>(std::rand() % 21 - 10);

	jessicaalba.applyinput(input);


	
jessicaalba.checkcollisions();

	const Player&p = jessicaalba.getplayer(1);
	const Player&p2 = jessicaalba.getplayer(2);
	

	
	std::cout << "Tick " << tickcount 
		<< " | Player 1 position: (" 
		<< p.position.x << ", " 
		<< p.position.y << ")"<<std::endl;

	std::cout << "Tick " << tickcount
		<< " | Player 2 position: ("
		<< p2.position.x << ", "
		<< p2.position.y << ")" << std::endl;
}
