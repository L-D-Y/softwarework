#pragma once
#include "sup.h"
#include "Draw.h"
#include "Setting.h"
#include "resource.h"
#include "usingClass.h"
#include <easyx.h>
#include <iostream>
#include <graphics.h>
#include <codecvt>
#include <locale>
#include <conio.h>
#include <fstream>
using namespace std;
#include <string>
#pragma comment(lib,"MSIMG32.LIB")
#include <chrono>
#include <thread>
#include <cstring>
char arr[][20] = { "新游戏","药材采集","药材资料","设置","帮助","关于" };
//检测键盘输入
char kbval = 0;
// 定义全局变量
int msg = 0; // 0表示没有鼠标事件，1表示左键按下，2表示左键抬起
int msx = 0; // 鼠标x坐标
int msy = 0; // 鼠标y坐标
int index = 0;
disease dis[10];
extern const char* const mName[100] = { "麻黄","桂枝","杏仁","炙甘草" ,"当归","半夏"};
extern const char* const picture[] = {
	"./resource/mahuang.jpeg",
	"./resource/guizhi.jpeg",
	"./resource/xinren.jpeg",
	"./resource/gancao.jpeg",
};
const char* const player::imgRoad[] = {
	"./resource/mahuang.jpeg",
	"./resource/guizhi.jpeg",
	"./resource/xinren.jpeg",
	"./resource/gancao.jpeg",
	"./resource/danggui.jpg",
	"./resource/banxia.jpeg",
};
int page = 0;
IMAGE bg;
IMAGE bg1;
IMAGE btn;

// 函数声明
void checkMouseStatus(int& msx, int& msy);
int checkAndReturnKBStatus();
void draw();
void loadR() {
	loadimage(&bg, "./resource/bg.png", getwidth(), getheight());
	loadimage(&bg1, "./resource/bg1.jpg", getwidth(), getheight());
	loadimage(&btn, "./resource/btn.png", 200, 50);
}
void check(std::chrono::steady_clock::time_point lastTime);
bool contain(int rx, int ry, int m_x, int m_y);
int changePage(int msx, int msy, int msg);
void printPoint(player pl);
void begin(std::chrono::steady_clock::time_point lastTime);

int main() {
	player myPlayer;
	dis[0].discribe = "外感风寒表实证。恶寒发热，头身疼痛，无汗而喘，舌苔薄白，脉浮紧。";
	myPlayer.loadMdc();
	loadArrow();
	// 初始化图形窗口
	initgraph(1280, 720);
	// 开启双缓冲绘图模式
	BeginBatchDraw();
	auto lastTime = std::chrono::high_resolution_clock::now();
start:
	loadR();

	while (true) {
		begin(lastTime);
		char arr[][20] = { "新游戏","药材采集","药材资料","设置","帮助","关于" };
		// 调用绘图函数
		draw();
		page = changePage(msx, msy, msg);
		if (page == 1)goto ng1;
		else if (page == 2)goto select;
		printPoint(myPlayer);
		// 结束双缓冲绘图模式并显示缓冲区内容
		FlushBatchDraw();
	}
option:
	loadR();

	while (true)
	{
		begin(lastTime);
		page = drawTransparentLayer(kbval, msx, msy, msg);
		if (page == 1)goto ng1;
		else if (page == 2)goto start;
		else if (page == 3) goto end;
		else if (page == 4) goto select;
		FlushBatchDraw();
	}



ng1:
	while (1)
	{
		begin(lastTime);
		putimage(0, 0, &bg1);
		drawRectangle();

		drawArrow();

		drawImage(myPlayer, index);
		printPoint(myPlayer); 
		if ( kbval== 27)goto option;

		FlushBatchDraw();
	}
select:
	while (3)
	{
		begin(lastTime);
		printPoint(myPlayer);
		drawSlct(myPlayer);
		if (kbval == 27)goto option;
		FlushBatchDraw();

	}
end:
	return 0;
}

void begin(std::chrono::steady_clock::time_point lastTime) {
	setbkmode(TRANSPARENT);
	check(lastTime);
	// 调用函数检查鼠标状态并更新鼠标坐标
	checkMouseStatus(msx, msy);
	checkAndReturnKBStatus();
	// 清空缓冲区
	cleardevice();
}

//打印分数
void printPoint(player pl) {
	// 设置文本颜色和背景模式
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);

	// 设置字体大小
	settextstyle(24, 0, _T("Arial"));

	// 将int转换为字符串
	int length = snprintf(nullptr, 0, "%d", pl.point);
	char* buffer = new char[length + 1]; // 分配足够的内存来存储字符串及其结束符
	// 将整数转换为字符串，并存储在buffer中
	snprintf(buffer, length + 1, "%d", pl.point);
	// 计算文本的宽度和高度
	int tw = 200;
	int th = 200;

	// 在右上角绘制文本
	outtextxy(1280 - tw - 10, 10, "Point");

	outtextxy(1280 - tw - 10, 30, buffer);
};
//主页转换页面
int changePage(int msx, int msy, int msg) {
	for (int i = 0; i < 6; i++) {
		//检测悬停
		if (contain(100, 200 + i * 50, msx, msy)) {
			//drawPng(70, 200 + i * 50-10, &btn);
			putimage(70, 200 + i * 50 - 10, &btn);
			settextcolor(BLACK);
			outtextxy(100, 200 + 50 * i, arr[i]);
			if (contain(100, 200, msx, msy)) {
				if (msg == 1) {
					cleardevice();
					return 1;
				}
			}
			else if (contain(100, 200 + 50 * 1, msx, msy)) {
				settextcolor(BROWN);
				if (msg == 1) {
					cleardevice();
					return 2;
				}
			}
			else if (contain(100, 200 + 50 * 2, msx, msy)) {
				settextcolor(BROWN);
				if (msg == 1) {
					cleardevice();
					return 3;
				}
			}
			else if (contain(100, 200 + 50 * 3, msx, msy)) {
				settextcolor(BROWN);
				if (msg == 1) {
					cleardevice();
					return 4;
				}
			}
			else if (contain(100, 200 + 50 * 4, msx, msy)) {
				settextcolor(BROWN);
				if (msg == 1) {
					cleardevice();
					return 5;
				}
			}
			else if (contain(100, 200 + 50 * 5, msx, msy)) {
				settextcolor(BROWN);
				if (msg == 1) {
					cleardevice();
					return 6;
				}
			}
			settextcolor(WHITE);
			continue;
		}

		//默认显示
		outtextxy(100, 200 + 50 * i, arr[i]);
	}
};
bool contain(int rx, int ry, int m_x, int m_y)
{
	if (m_x > rx - 30 && m_x<rx + 170 && m_y>ry && m_y < ry + 50) {
		return true;
	}
	return false;
	return false;
}

//优化帧率闪烁
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
//主页绘图
void draw() {
	putimage(0, 0, &bg);
	settextcolor(RGB(250, 200, 200));
	settextstyle(30, 0, "宋体");
	outtextxy(100, 50, "本草纲目");
	int th = textheight("本草纲目");
	setfillcolor(WHITE);
	solidrectangle(0, th + 55, 200, 60 + th);
	settextstyle(20, 0, "宋体");
	outtextxy(100, 70 + th, "金银花");
	settextcolor(WHITE);
	settextstyle(30, 0, "华文楷体");
}

//获取鼠标信息
void checkMouseStatus(int& msx, int& msy) {
	// 检测鼠标事件
	msg = 0;
	MOUSEMSG m = GetMouseMsg();
	// 更新鼠标坐标
	msx = m.x;
	msy = m.y;
	// 根据鼠标事件更新msg的值
	if (m.uMsg == WM_LBUTTONDOWN) {
		msg = 1; // 左键按下
	}
	else if (m.uMsg == WM_LBUTTONUP) {
		msg = 2; // 左键抬起
	}
	else {
		msg = 0; // 没有鼠标事件
	}
}

//获取键盘信息
int checkAndReturnKBStatus() {
	// 检测是否有键盘输入
	if (_kbhit()) {
		// 获取按键值并更新全局变量kbval
		kbval = _getch();
	}
	// 如果kbval等于ESC键的ASCII码（27），返回3
	if (kbval == 27) {
		return 3;
	}
	// 否则返回0或其他值
	return 0;
}