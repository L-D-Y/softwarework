#pragma once
#include "sup.h"
using namespace std;

#include "Setting.h"
#include "resource.h"
#include "usingClass.h"
#include <iostream>
#include <codecvt>
#include <conio.h>
using namespace std;
#include <fstream>
#include <string>
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
//2.绘制选项按钮
//3.绘制子图及变化
void drawImage(player pl, int index);
//4.鼠标事件/键盘事件决定跳转
//绘制药材采集界面
void drawSlct(player pl);
//6.
//7.
//8.
//9.
//10.
