#include "Game.h"
#include "specialButton.h"

int sum = 5;
bool is_game_started = false;
bool running = true;

//创建对象
Animation one = Animation("./sucaiku/player/玛丽走/%d.png",10, 300);
player p1 = player(100, 400, 20, 3, -40);
player p2 = player(1080, 400, 20, 3, -40);
IMAGE img_menu;


#pragma comment(lib,"winmm.lib")

//游戏初始化载入
void initgame() {
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
}
void background() {
	IMAGE img;
	loadimage(&img, "./sucaiku/background/00.png", WINDOW_WIDTH, WINDOW_HEIGHT, true);
	putimage(0, 0, &img);
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10);
	line(0, 600, WINDOW_WIDTH, 600);
}
void point() {



}
int main()
{
	// 初始化游戏界面
	initgame();
	// 开始批量绘制，减少界面闪烁
	BeginBatchDraw();
	one.lodAnimation1("./sucaiku/player/玛丽蹲/玛丽蹲%d.png", 26, 600);
	one.lodAnimation2("./sucaiku/player/玛丽走镜像/%d.png", 10, 300);
	//one.lodAnimation3("./sucaiku/player/玛丽走镜像/%d.png", 10, 300);
	one.lodAnimation3("./sucaiku/player/玛丽a/玛丽a%d.png", 8, 300);

	//引入背景bgm
	mciSendString(_T("open mus/bgm.mp3 alias bgm"), NULL, 0, NULL);
	//引入攻击音效
	mciSendString(_T("open mus/hit.mp3 alias hit"), NULL, 0, NULL);

	RECT region_btn_start_game, region_btn_quit_game;
	region_btn_start_game.left = (WINDOW_WIDTH - BUTTON_WIDTH) / 2;
	region_btn_start_game.right = region_btn_start_game.left + BUTTON_WIDTH;
	region_btn_start_game.top = 430;
	region_btn_start_game.bottom = region_btn_start_game.top + BUTTON_HEIGHT;

	region_btn_quit_game.left = (WINDOW_WIDTH - BUTTON_WIDTH) / 2;
	region_btn_quit_game.right = region_btn_quit_game.left + BUTTON_WIDTH;
	region_btn_quit_game.top = 550;
	region_btn_quit_game.bottom = region_btn_quit_game.top + BUTTON_HEIGHT;

	StartGameButton btn_start_game = StartGameButton(region_btn_start_game, _T("./sucaiku/ui/2.png"), _T("./sucaiku/ui/3.png"), _T("./sucaiku/ui/4.png"));
	QuitGameButton btn_quit_game = QuitGameButton(region_btn_quit_game, _T("./sucaiku/ui/2.png"), _T("./sucaiku/ui/3.png"), _T("./sucaiku/ui/4.png"));
	loadimage(&img_menu, _T("./sucaiku/ui/01.png"));
	char a1[5] = { 0 };
	char a2[5] = { 0 };
	while (running) {
		static int counter = 0;
		counter++;
		ExMessage msg;
		cleardevice();

		// 获取鼠标消息
		MOUSEMSG mouseMsg;
		while (MouseHit()) {
			mouseMsg = GetMouseMsg();
			// 处理鼠标消息
			if (!is_game_started) {
				btn_start_game.ProcessEvent(mouseMsg);
				btn_quit_game.ProcessEvent(mouseMsg);
			}
		}

		//游戏开始
		if (is_game_started) {
				background();
				p1.move(&one, &p1, counter, 60, ' ', 'S', 'A', 'D', 'J');
				p2.move(&one, &p2, counter, 60, VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT, '2');

				isattacked(&p2, &p1);
				isattacked(&p1, &p2);

				snprintf(a1, sizeof(a1), "%d", p1.health);
				snprintf(a2, sizeof(a2), "%d", p2.health);

				outtextxy(0, 650, a1);
				outtextxy(1100, 650, a2);

				if (p2.health == 0) {
					printf_s("%s ", "p1win");
					MessageBox(GetHWnd(), _T("dong寄了，要再打一遍吗"), _T("游戏结束"), MB_YESNO | MB_ICONQUESTION);
					while (1);
				}
				if (p1.health == 0) {
					MessageBox(GetHWnd(), _T("yang寄了，要再打一遍吗"), _T("游戏结束"), MB_YESNO | MB_ICONQUESTION);
					printf_s("%s", "p2win");
					while (1);
				}
		}
		//游戏未开始主界面
		else {
			putimage(0, 0, &img_menu);
			btn_start_game.Draw();
			btn_quit_game.Draw();
		}
		
		FlushBatchDraw();
	}
	EndBatchDraw();
	closegraph();
}
