#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "sup.h"
#include "Draw.h"
#include "Setting.h"
#include "resource.h"
#include "usingClass.h"
#include <easyx.h>
#include <iostream>
#include <graphics.h>
#include <codecvt>
#include <chrono>
#include <locale>
#include <conio.h>
#include <fstream>
using namespace std;
#include <string>
#pragma comment(lib,"MSIMG32.LIB")
#include <chrono>
#include <thread>
#include <cstring>

void player::loadMdc() {
	for (int i = 0; i < 6; i++) {
		loadimage(&this->myimg[i], player::imgRoad[i], 150, 150);
	}
};

void player::loadMdcd(int x, int y) {
	for (int i = 0; i < 6; i++) {
		loadimage(&this->myimg[i], player::imgRoad[i], x, y);
	}
};

void checkMouseStatus(int& msx, int& msy, int& msg) {
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

int checkAndReturnKBStatus(char& kbval) {
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