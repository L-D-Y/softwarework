#pragma once
#include "Draw.h"
#include "usingClass.h"
#include <graphics.h>
#include <easyx.h>
#include <chrono>

#include <Windows.h>
#include <thread>
IMAGE La;
IMAGE Ra;
IMAGE la1;
IMAGE ra1;
extern int msx;
extern int msy;
extern int msg;
extern int index;
extern char phenomenon[][100];
extern const char* const mName[100];
extern const char* const judge[4];
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

void drawDisease(int n) {
	settextcolor(WHITE);
	outtextxy(500, 450, "症状：");
	outtextxy(500, 500, phenomenon[n]);
	outtextxy(500, 600, "用药：");
}
void drawUseMdc(int a1, int a2, int a3, int a4)
{
	settextcolor(WHITE);
	if (a1 != -1) {
		outtextxy(500, 650, "君药：");
		outtextxy(575, 650, mName[a1]);
	}
	if (a2 != -1) {
		outtextxy(650, 650, "臣药：");
		outtextxy(725, 650, mName[a2]);
	}
	if (a3 != -1) {
		outtextxy(800, 650,"使药：");
		outtextxy(875, 650, mName[a3]);
	}
	if (a4 != -1) {
		outtextxy(950, 650, "佐药：");
		outtextxy(1025, 650, mName[a4]);
	}
}
void drawResult( player* pl,int correct,int count)
{
	if (correct==1111)
	{
		outtextxy(500, 300, judge[0]);
		if(count==0)
			pl->point += 1000;
	}
	else if (correct ==1100||correct==1101||correct==1110)
	{
		outtextxy(500, 300, judge[1]);
		if (count == 0)
			pl->point += 100;
	}
	else if (correct == 1000 || correct == 1001 || correct == 1010)
	{
		outtextxy(500, 300, judge[2]);
		if (count == 0)
			pl->point += 10;
	}
	else if (correct <1000)
	{
		outtextxy(500, 300, judge[3]);
		if (count == 0)
			pl->point -= 1000;
	}
}
;

int drawTransparentLayer(char key, int msx, int msy, int msg)
{
	setfillcolor(BROWN);
	if (key == 27)
	{
		IMAGE bg333;
		settextcolor(YELLOW);
		loadimage(&bg333, "./resource/R-C.jpeg", getwidth(), getheight());
		putimage(0, 0, &bg333);
		if (msx > 700 && msx < 800 && msy>200 && msy < 300) {
			settextcolor(WHITE);
			solidrectangle(700, 200, 800, 230);
			outtextxy(700, 200, "继续游戏");
			settextcolor(YELLOW);
			if (msg == 1) {
				cleardevice();
				return 1;
			}
		}
		else
			outtextxy(700, 200, "继续游戏");
		if (msx > 700 && msx < 800 && msy>300 && msy < 400) {
			settextcolor(WHITE);
			solidrectangle(700, 300, 800, 330);
			outtextxy(700, 300, "回到主页");
			settextcolor(YELLOW);
			if (msg == 1) {
				cleardevice();
				return 2;
			}
		}
		else
			outtextxy(700, 300, "回到主页");
		if (msx > 700 && msx < 800 && msy>400 && msy < 500) {
			settextcolor(WHITE);
			solidrectangle(700, 400, 800, 430);
			outtextxy(700, 400, "退回桌面");
			settextcolor(YELLOW);
			if (msg == 1) {
				cleardevice();
				return 3;
			}
		}
		else
			outtextxy(700, 400, "退回桌面");
		if (msx > 700 && msx < 800 && msy>500 && msy < 600) {
			settextcolor(WHITE);
			solidrectangle(700, 500, 800, 530);
			outtextxy(700, 500, "药材采集");
			settextcolor(YELLOW);
			if (msg == 1) {
				cleardevice();
				return 4;
			}
		}
		else
			outtextxy(700, 500, "药材采集");
		if (msx > 700 && msx < 800 && msy>600 && msy < 700) {
			settextcolor(WHITE);
			solidrectangle(700, 600, 800, 630);
			outtextxy(700, 600, "关于");

			settextcolor(YELLOW);
			if (msg == 1) {
				ShellExecute(NULL, "open", "https://www.baidu.com", NULL, NULL, SW_SHOWNORMAL);
			}
		}
		else
			outtextxy(700, 600, "关于");
	}
	return 0;
}

int drawImage(player pl, int index)
{
	settextcolor(WHITE);
	setfillcolor(GREEN);
	IMAGE a1;
	loadimage(&a1, "./resource/back.jpeg", 100, 100);
	pl.loadMdcd(150, 200);
	putimage(87, 125, &pl.myimg[0 + index * 3]);

	if (msx > 87 && msx < 238 && msy>125 && msy < 325) {
		solidrectangle(90, 220, 200, 270);
		outtextxy(100, 225, mName[0 + index * 3]);

		// 将int转换为字符串
		int length = snprintf(nullptr, 0, "%d", pl.myassets[0 + index * 3].num);
		char* buffer = new char[length + 1]; // 分配足够的内存来存储字符串及其结束符
		// 将整数转换为字符串，并存储在buffer中
		snprintf(buffer, length + 1, "%d", pl.myassets[0 + index * 3].num);
		outtextxy(100, 250, buffer);
		if (msg == 1) return 0 + index * 3;
	}
	putimage(87, 325, &pl.myimg[1 + index * 3]);
	if (msx > 87 && msx < 238 && msy>325 && msy < 525) {
		solidrectangle(90, 420, 200, 470);
		outtextxy(100, 425, mName[1 + index * 3]);
		// 将int转换为字符串
		int length = snprintf(nullptr, 0, "%d", pl.myassets[1 + index * 3].num);
		char* buffer = new char[length + 1]; // 分配足够的内存来存储字符串及其结束符
		// 将整数转换为字符串，并存储在buffer中
		snprintf(buffer, length + 1, "%d", pl.myassets[1 + index * 3].num);
		outtextxy(100, 450, buffer);
		if (msg == 1) return 1 + index * 3;
	}
	putimage(87, 525, &pl.myimg[2 + index * 3]);
	if (msx > 87 && msx < 238 && msy>525 && msy < 725) {
		solidrectangle(90, 620, 200, 670);

		outtextxy(100, 625, mName[2 + index * 3]);
		// 将int转换为字符串
		int length = snprintf(nullptr, 0, "%d", pl.myassets[2 + index * 3].num);
		char* buffer = new char[length + 1]; // 分配足够的来存储字符串及其结束符
		// 将整数转换为字符串，并存储在buffer中
		snprintf(buffer, length + 1, "%d", pl.myassets[2 + index * 3].num);
		outtextxy(100, 650, buffer);
		if (msg == 1) return 2 + index * 3;
	}
	return -1;
}

int drawSlct(player pl)
{
	int margin = 5; // 边距和图之间的间距
	settextcolor(WHITE);
	setfillcolor(GREEN);
	// 使用循环绘制9张图
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++) {
			putimage(margin + j * 400, margin + i * 400, &pl.myimg[i * 3 + j]);
			if (msx > margin + j * 400 && msx < margin + (j+1) * 400 && msy>margin + i * 400 && msy < margin + (i+1) * 400) {
				solidrectangle(margin + j * 400, margin + 400*i, margin + j * 400+100, margin + 400 * i+70);
				outtextxy(margin + j * 400+50, margin + 400 * i+30, mName[i*3+j]);

				// 将int转换为字符串
				int length = snprintf(nullptr, 0, "%d", pl.myassets[i * 3 + j ].num);
				char* buffer = new char[length + 1]; // 分配足够的内存来存储字符串及其结束符
				// 将整数转换为字符串，并存储在buffer中
				snprintf(buffer, length + 1, "%d", pl.myassets[i * 3 + j].num);
				outtextxy(margin + j * 400+50, margin + 400 * i+50, buffer);
				if (msg == 1) return i * 3 + j;
			}
		}

	}
	return -1;
}

bool containOP(int rx, int ry, int m_x, int m_y) {
	if (m_x > rx - 30 && m_x<rx + 70 && m_y>ry && m_y < ry + 50) {
		return true;
	}
	return false;
}

void check(std::chrono::steady_clock::time_point lastTime) {
	// 计算自上次循环以来的时间差
	auto currentTime = std::chrono::high_resolution_clock::now();
	auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastTime).count();

	// 如果时间差小于所需的时间间隔，则休眠
	if (elapsedTime < 1000 / 30) {
		std::this_thread::sleep_for(std::chrono::milliseconds((1000 / 30) - elapsedTime));
	}

	// 更新上次循环时间
	lastTime = std::chrono::high_resolution_clock::now();
};
