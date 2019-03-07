#include<conio.h>
#include<graphics.h>
#include<Windows.h>
#include<stdio.h>
#pragma comment(lib,"Winmm.lib")


#define Height 480
#define Width 640
#define Up_KEY 0x57
#define Down_KEY 0x53
#define Left_KEY 0x41
#define Right_KEY 0x44
#define ESC_GAME 0x1B
#define Speed 3


IMAGE img_bg, img_most, img_mostYM;
int most_x, most_y, seed, m_imgy;

void startup() {
	initgraph(Width, Height);
	loadimage(&img_bg, _T("E:\\C_code\\Project2\\Project2\\picture\\bg.jpg"));
	loadimage(&img_most, _T("E:\\C_code\\Project2\\Project2\\picture\\most2.jpg"));
	loadimage(&img_mostYM, _T("E:\\C_code\\Project2\\Project2\\picture\\most2_YM.jpg"));
	most_x = 0;
	most_y = 0;
	m_imgy = 0;
	seed = 0;
	BeginBatchDraw();
}

void gameOver() {
	EndBatchDraw();
	closegraph();
	printf_s("game over£¡");
}

void show() {
	putimage(0, 0, &img_bg);
	putimage(most_x, most_y, 32, 32, &img_mostYM, 0, m_imgy, NOTSRCERASE);
	putimage(most_x, most_y, 32, 32, &img_most, 0, m_imgy, SRCINVERT);
	FlushBatchDraw();

	Sleep(60);
}

void updataWithoutInput() {
	if (seed == 1) {
		seed = -1;
	}
	seed++;
	m_imgy = seed * 32;
}

void updataWithInput() {
	if (_kbhit()) {
		if (GetAsyncKeyState(Left_KEY)) {
			if (most_x > 0) {
				most_x -= Speed;
			}
		}
		if (GetAsyncKeyState(Right_KEY)) {
			if (most_x < 640) {
				most_x += Speed;
			}
		}
		if (GetAsyncKeyState(Up_KEY)) {
			if (most_y > 0) {
				most_y -= Speed;
			}
		}
		if (GetAsyncKeyState(Down_KEY)) {
			if (most_y < 480) {
				most_y += Speed;
			}
		}
		if (GetAsyncKeyState(ESC_GAME)) {
			gameOver();
		}
	}
}


int main() {
	startup();
	while (1)
	{
		show();
		updataWithoutInput();
		updataWithInput();
	}

	return 0;
}