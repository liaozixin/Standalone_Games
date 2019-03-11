#include<graphics.h>
#include<conio.h>
#include<stdio.h>

#pragma comment(lib,"MSIMG32.LIB")

void transparentimage(IMAGE *dstimg, int x, int y, IMAGE *srcimg, UINT transparentcolor)
{
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	int w = srcimg->getwidth();
	int h = srcimg->getheight();


	TransparentBlt(dstDC, x, y, w, h, srcDC, 0, 0, w, h, transparentcolor);    
}


int main() {
	initgraph(640, 480);
	IMAGE src;
	IMAGE bg;
	loadimage(&bg, _T("E:\\C_code\\Project2\\Project2\\picture\\bg.jpg"));
	loadimage(&src, _T("E:\\C_code\\Project2\\Piskel\\Cat.gif"));

	BeginBatchDraw();

	putimage(0, 0, &bg);
	transparentimage(NULL, 0, 0, &src, RGB(255,255,255));
	FlushBatchDraw();
	_getch();
	closegraph();
	return 0;
}