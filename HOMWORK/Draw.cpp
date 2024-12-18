#pragma once
#include "Draw.h"
#include "usingClass.h"
#include <graphics.h>
#include <easyx.h>
#include <Windows.h>
IMAGE La;
IMAGE Ra;
IMAGE la1;
IMAGE ra1;
extern int msx;
extern int msy;
extern int msg;
extern int index;
void loadArrow() {
	loadimage(&La, "./resource/Larrow.png", 50, 50);
	loadimage(&Ra, "./resource/Rarrow.png", 50, 50);
	loadimage(&la1, "./resource/la1.png", 50, 50);
	loadimage(&ra1, "./resource/ra1.png", 50, 50);
}
void drawRectangle()
{
	setfillcolor(RGB(200, 150, 100));
	fillroundrect(75, 100, 250, 700, 20, 20);
}

int drawArrow() {
	putimage(25, 300, &La);
	putimage(250, 300, &Ra);
	if (msx > 25 && msx < 75 && msy>300 && msy < 350) {
		putimage(25, 300, &la1);
		if (msg == 1 && index != 0)index--;
	}
	if (msx > 250 && msx < 300 && msy>300 && msy < 350) {
		putimage(250, 300, &ra1);
		if (msg == 1 && index != 3)index++;
	}
	return 0;
}

int drawTransparentLayer(char key, int msx, int msy, int msg)
{
	setfillcolor(BROWN);
	if (key == 27)
	{
		IMAGE bg;
		settextcolor(YELLOW);
		loadimage(&bg, "./resource/R-C.jpeg", getwidth(), getheight());
		putimage(0, 0, &bg);
		if (msx > 700 && msx < 800 && msy>200 && msy < 300) {
			settextcolor(WHITE);
			solidrectangle(700, 200, 800, 230);
			outtextxy(700, 200, "继续游戏");
			settextcolor(YELLOW);
			if (msg == 1) return 1;
		}
		else
			outtextxy(700, 200, "继续游戏");
		if (msx > 700 && msx < 800 && msy>300 && msy < 400) {
			settextcolor(WHITE);
			solidrectangle(700, 300, 800, 330);
			outtextxy(700, 300, "回到主页");
			settextcolor(YELLOW);
			if (msg == 1) return 2;
		}
		else
			outtextxy(700, 300, "回到主页");
		if (msx > 700 && msx < 800 && msy>400 && msy < 500) {
			settextcolor(WHITE);
			solidrectangle(700, 400, 800, 430);
			outtextxy(700, 400, "退回桌面");
			settextcolor(YELLOW);
			if (msg == 1) return 3;
		}
		else
			outtextxy(700, 400, "退回桌面");
		if (msx > 700 && msx < 800 && msy>500 && msy < 600) {
			settextcolor(WHITE);
			solidrectangle(700, 500, 800, 530);
			outtextxy(700, 500, "药材采集");
			settextcolor(YELLOW);
			if (msg == 1) return 4;
		}
		else
			outtextxy(700, 500, "药材采集");
		if (msx > 700 && msx < 800 && msy>600 && msy < 700) {
			settextcolor(WHITE);
			solidrectangle(700, 600, 800, 630);
			outtextxy(700, 600, "关于");

			settextcolor(YELLOW);
			if (msg == 1) return 5;
		}
		else
			outtextxy(700, 600, "关于");
	}
	return 0;
}

void drawImage(player pl, int index)
{
	settextcolor(BLACK);
	IMAGE a1;
	loadimage(&a1, "./resource/back.jpeg", 100, 100);
	pl.loadMdcd(150, 200);
	putimage(87.5, 125, &pl.myimg[0 + index * 3]);
	if (msx > 87 && msx < 238 && msy>125 && msy < 325) {
		outtextxy(100, 225, mName[0 + index * 3]);
	}
	putimage(87.5, 325, &pl.myimg[1 + index * 3]);
	if (msx > 87 && msx < 238 && msy>325 && msy < 525) {
		outtextxy(100, 425, mName[1 + index * 3]);
	}
	putimage(87.5, 525, &pl.myimg[2 + index * 3]);
	if (msx > 87 && msx < 238 && msy>525 && msy < 725) {
		outtextxy(100, 625, mName[2 + index * 3]);
	}
}

void drawSlct(player pl)
{
	cleardevice();
	pl.loadMdcd(300,300);
	int margin = 5; // 边距和图之间的间距
	int rects[9][4] = {
	  {margin, margin, 400 + margin, 400 - margin},   // 左边矩形方块
	  {400 + margin, margin, 800 + margin, 400 - margin},  // 中间左边矩形方块
	  {800 + margin, margin, 1200 - margin, 400 - margin}, // 中间右边矩形方块
	  {margin, 400 + margin, 400 + margin, 800 - margin},  // 左边上方矩形方块
	  {400 + margin, 400 + margin, 800 + margin, 800 - margin}, // 中间上方矩形方块
	  {800 + margin, 400 + margin, 1200 - margin, 800 - margin},// 中间下方矩形方块
	  {margin, 800 + margin, 400 + margin, 1200 - margin},  // 左边下方矩形方块
	  {400 + margin, 800 + margin, 800 + margin, 1200 - margin}, // 中间下方矩形方块
	  {800 + margin, 800 + margin, 1200 - margin, 1200 - margin} // 右边下方矩形方块
	};

	// 使用循环绘制9张图
	for (int i = 0; i < 9; ++i)
	{
		putimage(rects[i][0], rects[i][1], &pl.myimg[i]);
	}

}

bool containOP(int rx, int ry, int m_x, int m_y) {
	if (m_x > rx - 30 && m_x<rx + 70 && m_y>ry && m_y < ry + 50) {
		return true;
	}
	return false;
}

int option(int msx, int msy, int msg, IMAGE btn);
void DrawTextAtPosition(int x, int y, const std::string& text, int maxWidth);