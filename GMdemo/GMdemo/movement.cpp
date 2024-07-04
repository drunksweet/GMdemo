#include "Game.h"

//¹¥»÷
void attack(player* P, char k) {
	enum GAMEINPUT
	{
		NOINPUT = 0X0,
		UPINPUT = 0X1,
	};
	int input = NOINPUT;
	if (GetAsyncKeyState(k) & 0x8000)
	{
		input |= UPINPUT;
	}
	if (input & UPINPUT)
	{
		if (!P->face) {
			rectangle(P->play_pos.x + 100, P->play_pos.y + 50, P->play_pos.x + 250, P->play_pos.y + 175);
		}
		else {
			rectangle(P->play_pos.x, P->play_pos.y + 50, P->play_pos.x - 150, P->play_pos.y + 175);
		}
	}
}