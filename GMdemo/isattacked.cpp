#include "Game.h"

void isattacked(player* p1, player* p2) {
	if (p1->leattack) {
		if ((p1->play_pos.x - p2->play_pos.x) < 250 && (p1->play_pos.x - p2->play_pos.x) > 0 && (p1->play_pos.y - p2->play_pos.y) <= 100 && (p1->play_pos.y - p2->play_pos.y) > -100) {
			(p2->health)--;
		}
	}
	if (p1->riattack) {
		if ((p2->play_pos.x - p1->play_pos.x) < 250 && (p2->play_pos.x - p1->play_pos.x) > 0 && (p1->play_pos.y - p2->play_pos.y) <= 100 && (p1->play_pos.y - p2->play_pos.y) > -100) {
			(p2->health)--;
		}
	}
}