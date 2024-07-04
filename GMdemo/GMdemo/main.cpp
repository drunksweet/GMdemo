#include "Game.h"

int sum = 5;

Animation one = Animation("./sucaiku/player/%d.png", 1, 60);
player p1 = player(600, 200, 20, 5, -60);
player p2 = player(600, 400, 20, 5, -60);

void initgame() {
	initgraph(1280, 720);
}
void background() {
	IMAGE img;
	loadimage(&img, "./sucaiku/background/00.png", 1280, 720, true);
	putimage(0, 0, &img);
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10);
	line(0, 600, 1280, 600);
}
void point() {



}
int main()
{
	initgame();
	BeginBatchDraw();
	while (1) {
		static int counter = 0;
		counter++;
		ExMessage msg;
		cleardevice();
		background();
		move(&one,&p2, counter, 60, 'W', 'S', 'A', 'D');
		attack(&p2, 'J');
		FlushBatchDraw();
	}
	EndBatchDraw();
	closegraph();
}
