#pragma once

#include "basic.h"


// ���� Animation ��
class Animation {
public:
    Animation(LPCTSTR path, int num, int interval);
    void drawAnimation(int x, int y, int counter, int delta);
    void lodAnimation1(LPCTSTR path, int num, int interval);
    void lodAnimation2(LPCTSTR path, int num, int interval);
    void lodAnimation3(LPCTSTR path, int num, int interval);
    void putimage_alpha(int x, int y, IMAGE* img);
	void drawAnimation1(int x, int y, int counter, int delta);
	void drawAnimation2(int x, int y, int counter, int delta);
	void drawAnimation3(int x, int y, int counter, int delta);

private:
    int Size_X ;
    int Size_Y ;
    int interval_ms ;
    int cur ;
    int timer ;
    std::vector<IMAGE*> frame_list;
    std::vector<IMAGE*> down_frame_list;
    std::vector<IMAGE*> frame_list1;
    std::vector<IMAGE*> frame_list2;
    std::vector<IMAGE*> frame_list3;
};

// ���� player ��
class player {
public:
	int health ;
	bool isjumping ;
	POINT play_pos ;
	int speed ;
	int downspeed ;
	double VVspeed ;
	double Vspeed ;
	bool face ;
	bool riattack ;
	bool leattack ;
	bool isdown ;
	bool isattacking;

	player(int x, int y, int speed, int downspeed, int VVspeed);
	~player();
	void move(Animation* two, player* p, int counter, int interval, char up, char down, char left, char right, char attack);
};


//
void isattacked(player* p1, player* p2);
void drawButton(IMAGE img_menu);