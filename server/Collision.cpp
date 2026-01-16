#include "Collision.h"
bool Collison::CheckDistancebrodie(vec2 pos1, vec2 pos2, float distance) { //collison math logic
	float dx = pos1.x - pos2.x;
	float dy = pos1.y - pos2.y;
	float distSquared = dx * dx + dy * dy;
	return distSquared <= distance * distance;
}
