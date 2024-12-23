#pragma once
#include "sup.h"
#include "Setting.h"
#include "resource.h"
#include "usingClass.h"
#include <iostream>
#include <codecvt>
#include <conio.h>
using namespace std;
#include <fstream>
#include <string>
#include <chrono>

#pragma comment(lib,"MSIMG32.LIB")

//1.绘制背景图
//有对应背景图
void drawRectangle();
//左边出现三个图片，上下两个三角形，点击
int drawArrow();
void loadArrow();

//双缓冲绘图
//esc 出现选项图
int drawTransparentLayer(char key, int msx, int msy, int msg);
int option(int msx, int msy, int msg, IMAGE btn);
//3.绘制拥有药材子图及变化，同时，在该函数中需要对是否点击了图片进行判断，否返回 -1 ，是返回对应的player::myassets下标
int drawImage(player pl, int index);
//4.鼠标事件/键盘事件决定跳转
//绘制药材采集界面
int drawSlct(player pl);
//6.绘制病情
void drawDisease(int index);
//7.
void check(std::chrono::steady_clock::time_point lastTime);

//8.
//9.
//10.
