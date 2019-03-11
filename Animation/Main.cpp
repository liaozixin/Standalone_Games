#include<graphics.h>
#include<conio.h>

IMAGE bg, img;
int x = 0, y = 0, seed = 0;

void animation() {

	putimage(320, 240, 32, 32, &img, x, y);
	FlushBatchDraw();

	if ((seed != 0) && (seed % 50 == 0) && (x != 96))
	{
		x += 32;
	}
}


int main() {
	initgraph(640, 480);

	loadimage(&bg, _T("E:\\C_code\\Project2\\IMG\\bg.jpg"));
	loadimage(&img, _T("E:\\C_code\\Project2\\IMG\\1.bmp"));
	BeginBatchDraw();
	putimage(0, 0, &bg);


	while (1)
	{
		animation();
		seed++;
		Sleep(20);
	}

	system("pause");
	closegraph();
	return 0;
}