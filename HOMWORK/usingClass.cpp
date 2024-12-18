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