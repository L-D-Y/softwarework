#pragma once
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
//esc 出现选项图
int drawTransparentLayer(char key, int msx, int msy, int msg);
//3.绘制拥有药材子图及变化，同时，在该函数中需要对是否点击了图片进行判断，否返回 -1 ，是返回对应的player::myassets下标
int drawImage(player pl, int index);
//绘制药材采集界面
int drawSlct(player pl);
//6.绘制病情
void drawDisease(int index);
void drawUseMdc(int a1, int a2, int a3, int a4);
void drawResult(player* pl, int correct, int count);
void check(std::chrono::steady_clock::time_point lastTime);
