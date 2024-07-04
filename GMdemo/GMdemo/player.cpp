#include "Game.h"


player::player(int x, int y, int speed, int downspeed, int VVspeed) {
	play_pos.x = x;
	play_pos.y = y;
	this->downspeed = downspeed;
	this->speed = speed;
	this->VVspeed = VVspeed;
};
player::~player() {};