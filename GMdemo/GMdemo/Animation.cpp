#include "Game.h"

//动画模块

Animation::Animation(LPCTSTR path, int num, int interval) {
		interval_ms = interval;
		TCHAR path_file[256];
		for (size_t i = 1; i <= num; i++) {
			sprintf_s(path_file, path, i);
			IMAGE* frame = new IMAGE();
			loadimage(frame, path_file, 100, 200, true);
			frame_list.push_back(frame);
		}
	};

Animation::~Animation() {
		for (size_t i = 1; i <= frame_list.size(); i++) {
			delete frame_list[i];
		}
	};

	#pragma comment(lib,"MSIMG32.LIB")
//alpha通道输出
void Animation::putimage_alpha(int x, int y, IMAGE* img)
	{
		int w = img->getwidth();
		int h = img->getheight();
		AlphaBlend(GetImageHDC(NULL), x, y, w, h,
			GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
	}

void Animation::drawAnimatiom(int x, int y, int counter, int delta) {
		timer += delta;
		if (timer >= interval_ms) {
			cur = (cur + 1) % frame_list.size();
			timer = 0;
		}
		putimage_alpha(x, y, frame_list[cur]);

	}

//移动函数 实现移动效果
void move(Animation* one, player* p, int counter, int interval, char up, char down, char left, char right) {
	enum GAMEINPUT
	{
		NOINPUT = 0X0,
		UPINPUT = 0X1,
		DOWNINPUT = 0X2,
		LEFTINPUT = 0X4,
		RIGHTINPUT = 0X8,
		FIREINPUT = 0X10
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
	if ((input & DOWNINPUT) && (p->play_pos.y <= 400))
	{
		p->play_pos.y += p->speed;
		if (p->play_pos.y > 390) {

			p->play_pos.y = 400;
		}
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
	one->drawAnimatiom(p->play_pos.x, p->play_pos.y, counter, interval);

}
