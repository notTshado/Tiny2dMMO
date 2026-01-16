#pragma once
#include <unordered_map>
#include "../common/Types.h"
#include "../common/NetPackets.h"

struct Player {
	vec2 position;
};

class World {
public:
	void applyinput(const InputPacket& input);
	const Player& getplayer(uint32_t id) const;
	void checkcollisions();
	

private:
	std::unordered_map<uint32_t,Player>players;
};