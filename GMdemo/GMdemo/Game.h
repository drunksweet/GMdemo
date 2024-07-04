#pragma once

#include "basic.h"

// 声明 Animation 类
class Animation {
public:
    Animation(LPCTSTR path, int num, int interval);
    ~Animation();
    void drawAnimatiom(int x, int y, int counter, int delta);
    void putimage_alpha(int x, int y, IMAGE* img);
private:
    int interval_ms;
    int cur;
    int timer;
    std::vector<IMAGE*> frame_list;
};

// 声明 player 类
class player {
public:
    player(int x, int y, int speed, int downspeed, int VVspeed);
    ~player();
    bool isjumping;
    POINT play_pos;
    int speed;
    int downspeed;
    double VVspeed;
    double Vspeed;
    bool face;
};

// 声明函数
void move(Animation* one, player* p, int counter, int interval, char up, char down, char left, char right);
void attack(player* P, char k);


