#pragma once
#include "Types.h"
#include <cstdint>

struct InputPacket { // here we just define an inpujt packet 
	uint32_t playerid;
	float movex;
	float movey;
};
struct StatePacket { // state packet w player id and position type shi
	uint32_t playerid;
	vec2 position;
};