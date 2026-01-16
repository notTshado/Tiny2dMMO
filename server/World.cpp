#include "World.h"
#include "Collision.h"

#include <iostream>

void World::applyinput(const InputPacket& input) {
Player& player = players[input.playerid];
	player.position.x += input.movex*0.1f;
	player.position.y += input.movey*0.1f;
}
const Player& World::getplayer(uint32_t id) const {
	return players.at(id);
}
void World::checkcollisions() {
	if (players.size() < 2) return; // Need at least two players pal
	float collisionDistance = 1.0f; //(this is like ehhh the calculated distance in between both of platyers x and y's so like if that distance is achieved its a collision )
	for (auto& baka1 : players) {
		Player& player1 = baka1.second;
	
		for (auto& baka2 : players) {

			if (baka1.first == baka2.first) continue; // Skip self
			Player& player2 = baka2.second;

			if (Collison::CheckDistancebrodie(player1.position, player2.position, collisionDistance)) {
				std::cout << "Collision detected between Player " << baka1.first << " and Player " << baka2.first << "!\n";

			}

		}
	}
}
