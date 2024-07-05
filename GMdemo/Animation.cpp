#include "Game.h"

//动画模块

Animation::Animation(LPCTSTR path, int num, int interval):
	Size_X(100),Size_Y(200),interval_ms(0),cur(0),timer(0){
	interval_ms = interval;
	TCHAR path_file[256];
	for (size_t i = 1; i <= num; i++) {
		sprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file, Size_X, Size_Y, true);
		frame_list.push_back(frame);
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

void Animation::drawAnimation(int x, int y, int counter, int delta) {
		timer += delta;
		if (timer >= interval_ms) {
			cur = (cur + 1) % frame_list.size();
			timer = 0;
		}
		putimage_alpha(x, y, frame_list[cur]);

	}
void Animation::lodAnimation1(LPCTSTR path, int num, int interval) {
	interval_ms = interval;
	TCHAR path_file[256];
	for (size_t i = 8; i <= 23; i++) {
		sprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file, Size_X, Size_Y, true);
		frame_list1.push_back(frame);
	}

}
void Animation::lodAnimation2(LPCTSTR path, int num, int interval) {
	interval_ms = interval;
	TCHAR path_file[256];
	for (size_t i = 1; i <= 10; i++) {
		sprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file, Size_X, Size_Y, true);
		frame_list2.push_back(frame);
	}

}
void Animation::lodAnimation3(LPCTSTR path, int num, int interval) {
	interval_ms = interval;
	TCHAR path_file[256];
	for (size_t i = 1; i <= 8; i++) {
		sprintf_s(path_file, path, i);
		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file, Size_X, Size_Y, true);
		frame_list3.push_back(frame);
	}

}
void Animation::drawAnimation1(int x, int y, int counter, int delta) {
	timer += delta;
	if (timer >= interval_ms) {
		cur = (cur + 1) % 5;//frame_list1.size();
		timer = 0;
	}
	putimage_alpha(x, y, frame_list1[cur]);

}
void Animation::drawAnimation2(int x, int y, int counter, int delta) {
	timer += delta;
	if (timer >= interval_ms) {
		cur = (cur + 1) % 5;//frame_list2.size();
		timer = 0;
	}
	putimage_alpha(x, y, frame_list2[cur]);

}
void Animation::drawAnimation3(int x, int y, int counter, int delta) {
	timer += delta;
	if (timer >= interval_ms) {
		cur = (cur + 1) % 5;//frame_list3.size();
		timer = 0;
	}
	putimage_alpha(x, y, frame_list3[cur]);

}
