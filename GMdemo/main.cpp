#include "Game.h"
#include "specialButton.h"

int sum = 5;
bool is_game_started = false;
bool running = true;

//��������
Animation one = Animation("./sucaiku/player/����a/����a%d.png", 8, 300);
player p1 = player(100, 400, 20, 3, -40);
player p2 = player(1080, 400, 20, 3, -40);
IMAGE img_menu;


#pragma comment(lib,"winmm.lib")

//��Ϸ��ʼ������
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
	// ��ʼ����Ϸ����
	initgame();
	// ��ʼ�������ƣ����ٽ�����˸
	BeginBatchDraw();

	//���뱳��bgm
	mciSendString(_T("open mus/bgm.mp3 alias bgm"), NULL, 0, NULL);
	//���빥����Ч
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

	StartGameButton btn_start_game = StartGameButton(region_btn_start_game, _T("./sucaiku/ui/��ʼ/2.png"), _T("./sucaiku/ui/��ʼ/3.png"), _T("./sucaiku/ui/��ʼ/4.png"));
	QuitGameButton btn_quit_game = QuitGameButton(region_btn_quit_game, _T("./sucaiku/ui/�ر�/1.png"), _T("./sucaiku/ui/�ر�/2.png"), _T("./sucaiku/ui/�ر�/3.png"));
	loadimage(&img_menu, _T("./sucaiku/ui/01.png"));
	while (running) {
		static int counter = 0;
		counter++;
		ExMessage msg;
		cleardevice();

		// ��ȡ�����Ϣ
		MOUSEMSG mouseMsg;
		while (MouseHit()) {
			mouseMsg = GetMouseMsg();
			// ���������Ϣ
			if (!is_game_started) {
				btn_start_game.ProcessEvent(mouseMsg);
				btn_quit_game.ProcessEvent(mouseMsg);
			}
		}

		//��Ϸ��ʼ
		if (is_game_started) {
			background();
			p1.move(&one, &p1, counter, 60, ' ', 'S', 'A', 'D', 'J');
			p2.move(&one, &p2, counter, 60, VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT, '2');
			if (counter % 10 == 0) {
				isattacked(&p1, &p2);
			}
			if (p2.health == 0) {
				while (1);
			}
			printf_s("%d", p2.health);
		}
		//��Ϸδ��ʼ������
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
