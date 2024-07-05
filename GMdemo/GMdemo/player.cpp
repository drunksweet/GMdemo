#include "Game.h"


player::player(int x, int y, int speed, int downspeed, int VVspeed):
isjumping(0), play_pos({0,0}),speed(0),downspeed(0),VVspeed(0),face(0),health(20),
Vspeed(0),leattack(0),riattack(0),isdown(0){
	play_pos.x = x;
	play_pos.y = y;
	this->downspeed = downspeed;
	this->speed = speed;
	this->VVspeed = VVspeed;
};
player::~player() {};

void player::move(Animation* two, player* p, int counter, int interval, char up, char down, char left, char right, char attack) {
	enum GAMEINPUT
	{
		NOINPUT = 0X0,
		UPINPUT = 0X1,
		DOWNINPUT = 0X2,
		LEFTINPUT = 0X4,
		RIGHTINPUT = 0X8,
		FIREINPUT = 0X10,
		ATTACK = 0X20
	};
	int input = NOINPUT;


	if (GetAsyncKeyState(up) & 0x8000)
	{
		input |= UPINPUT;
	}
	if (GetAsyncKeyState(down) & 0x8000)
	{
		input |= DOWNINPUT;
	}
	if (GetAsyncKeyState(left) & 0x8000)
	{
		input |= LEFTINPUT;
	}
	if (GetAsyncKeyState(right) & 0x8000)
	{
		input |= RIGHTINPUT;
	}
	if (GetAsyncKeyState(attack) & 0x8000)
	{
		input |= ATTACK;
	}
	if ((input & UPINPUT) && (p->play_pos.y >= 0))
	{
		if (!(p->isjumping)) {
			p->Vspeed = p->VVspeed;
			p->isjumping = true;

		}
	}
	if (p->isjumping) {
		p->Vspeed += p->downspeed;
		p->play_pos.y += p->Vspeed;

	}

	if ((input & LEFTINPUT) && (p->play_pos.x >= 0))
	{
		p->play_pos.x -= p->speed;
		p->face = 1;
	}
	if ((input & RIGHTINPUT) && (p->play_pos.x <= 1180))
	{
		p->play_pos.x += p->speed;
		p->face = 0;
	}
	if (p->play_pos.y > 390) {
		p->play_pos.y = 400;
		p->isjumping = false;
	}
	if (input & DOWNINPUT)
	{	
		if (p->isjumping) {
			two->drawAnimatiom(p->play_pos.x, p->play_pos.y, counter, interval);
		}
		else {
			p->play_pos.y = p->play_pos.y + 100;
			p->isdown = true;
			two->down_drawAnimatiom(p->play_pos.x, p->play_pos.y, counter, interval);
		}
		
	}
	else {
		p->isdown = 0;
		two->drawAnimatiom(p->play_pos.x, p->play_pos.y, counter, interval);
	}
	if (input & ATTACK)
		if (input & ATTACK)
		{
			if (!p->face) {
				rectangle(p->play_pos.x + 100, p->play_pos.y + 20, p->play_pos.x + 250, p->play_pos.y + 80);
				p->riattack = true;
			}
			else {
				rectangle(p->play_pos.x, p->play_pos.y + 20, p->play_pos.x - 150, p->play_pos.y + 80);
				p->leattack = true;
			}
		}
		else {
			p->leattack = 0;
			p->riattack = 0;

	}


}