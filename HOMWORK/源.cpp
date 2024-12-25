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
#include <windows.h>
#include <fstream>
using namespace std;
#include <string>
#pragma comment(lib,"MSIMG32.LIB")
#include <chrono>
#include <thread>
#include <cstring>
char arr[][20] = { "开始游戏","药材采集","药材资料","设置","帮助","关于" };
//检测键盘输入
char kbval = 0;
// 定义全局变量
int msg = 0; // 0表示没有鼠标事件，1表示左键按下，2表示左键抬起
int msx = 0; // 鼠标x坐标
int msy = 0; // 鼠标y坐标
int index = 0;
extern const char* const mName[100] = { "麻黄","桂枝","杏仁","炙甘草" ,"当归","半夏" };
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
extern const char* const judge[4] = { "妙手回春啊大夫！","好是好了，但总觉得不得劲儿。","我感觉不太对。","人没了（）。" };
extern char phenomenon[][100] = { "恶寒发热，头身疼痛，无汗而喘，舌苔薄白，脉浮紧。"};
extern int method[][4] = { {0,1,2,3} };

int page = 0;
IMAGE bg;
IMAGE bg1;
IMAGE btn;
IMAGE bag2;
void draw();
static void loadR() {
	loadimage(&bg, "./resource/bg.png", getwidth(), getheight());
	loadimage(&bg1, "./resource/bg1.jpg", getwidth(), getheight());
	loadimage(&btn, "./resource/btn.png", 200, 50);
	loadimage(&bag2, "./resource/bg2.jpeg", getwidth(), getheight());

}
bool contain(int rx, int ry, int m_x, int m_y);
int changePage(int msx, int msy, int msg);
void printPoint(player pl);
void begin(std::chrono::steady_clock::time_point lastTime, int& msx, int& msy, int& msg, char& kbval);

int main() {
	player myPlayer;
	myPlayer.point = 0;
	int num = 0;
	int token = 1;
	loadArrow();
	// 初始化图形窗口
	initgraph(1280, 720);
	loadR();
	// 开启双缓冲绘图模式
	BeginBatchDraw();
	int mode = 0;
	auto lastTime = std::chrono::high_resolution_clock::now();
	while (true)
	{
		
		//主页
		if (mode == 0)
		{
			cleardevice();
			while (true) {
				page = 0;
				begin(lastTime, msx, msy, msg, kbval);
				// 调用绘图函数
				draw();
				page = changePage(msx, msy, msg);
				if (page == 1) {
					mode = 1;
					break;
				}
				else if (page == 2) {
					mode = 2;
					break;
				}
				else if (page == 5 && msg == 1)ShellExecute(NULL, "open", "http://www.cntcm.com.cn/", NULL, NULL, SW_SHOWNORMAL);
				else if (page == 6 && msg == 1)
					ShellExecute(NULL, "open", "https://www.baidu.com", NULL, NULL, SW_SHOWNORMAL);
				printPoint(myPlayer);
				// 结束双缓冲绘图模式并显示缓冲区内容
				FlushBatchDraw();

			}
		}
		//选项页
		else if (mode == 11) {
			cleardevice();
			while (true)
			{
				begin(lastTime, msx, msy, msg, kbval);
				page = drawTransparentLayer(kbval, msx, msy, msg);
				if (page == 1) {
					//新游戏
					kbval = 0;
					mode = 1;
					break;
				}
				else if (page == 2) {
					//回到主页
					kbval = 0;
					mode = 0;
					break;
				}
				else if (page == 3) {
					//退回桌面
					kbval = 0;
					mode = 999;
					break;
				}
				else if (page == 4) {
					//药材采集
					kbval = 0;
					mode = 2;
					break;
				}
				FlushBatchDraw();
			}
		}
		//新游戏页
		else if (mode == 1)
		{
			int dis_token = 0;
			int w = 1000;
			int correct = 0;
			int count = 0;
			int a[4] = { -1,-1,-1,-1 };
			cleardevice();
			myPlayer.loadMdc();
			while (1)
			{
				begin(lastTime, msx, msy, msg, kbval);
				if (dis_token > 3&&msg==1)break;

				putimage(0, 0, &bg1);
				drawRectangle();
				drawArrow();

				int i = drawImage(myPlayer, index);

				printPoint(myPlayer);
				drawDisease(num);
				drawUseMdc(a[0], a[1], a[2], a[3]);

				if (dis_token <= 3&&msg==1&&i!=-1 && myPlayer.myassets[i].num > 0) {
					a[dis_token] = i;
					if (method[num][dis_token] == i) {
						correct += w;			
					}
					w /= 10;
					dis_token++;
					myPlayer.myassets[i].num--;

				}
				if (dis_token == 4) {
					drawResult(&myPlayer, correct,count);
					count = 1;
				}
				if (kbval == 27) {
					mode = 11;
					break;
				}
				FlushBatchDraw();
				cleardevice();
			}
		}
		//药材采集页
		else if (mode == 2) {

			cleardevice();
			while (3)
			{
				begin(lastTime, msx, msy, msg, kbval);
				putimage(0, 0, &bag2);
				printPoint(myPlayer);
				int j = drawSlct(myPlayer);
				if (j != -1)myPlayer.myassets[j].num++;
				if (kbval == 27) {
					mode = 11;
					break;
				}
				FlushBatchDraw();
			}
		}
		else if (mode == 999)return 0;
	}
	return 0;
}

void begin(std::chrono::steady_clock::time_point lastTime, int& msx, int& msy, int& msg, char& kbval) {
	setbkmode(TRANSPARENT);
	check(lastTime);
	// 调用函数检查鼠标状态并更新鼠标坐标
	checkMouseStatus(msx, msy, msg);
	checkAndReturnKBStatus(kbval);
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
	delete[] buffer;
};
//主页转换页面
int changePage(int msx, int msy, int msg) {
	for (int i = 0; i < 6; i++) {
		//检测悬停
		if (contain(100, 200 + i * 50, msx, msy)) {
			putimage(70, 200 + i * 50 - 10, &btn);
			settextcolor(BLACK);
			outtextxy(100, 200 + 50 * i, arr[i]);
			if (contain(100, 200, msx, msy)) {
				if (msg == 1) {
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
