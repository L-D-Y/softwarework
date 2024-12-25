#pragma once
#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <chrono>

using namespace std;
#include <fstream>
#include <string>

extern const char* const mName[];
extern const char* const picture[];

//3.图表类（杂项图）
class Medicine {
public:
	// 数值
	int token;
	int num;
	Medicine() {};
	Medicine(int t) {
		this->token = t;
		num = 0;
	}
};//4.资料类

//5.数值判定类
class player {
public:
	int point;
	Medicine myassets[10];
	IMAGE myimg[10];
	static const char* const imgRoad[];
	player() {
		point = 0;
		for (int i = 0; i < 6; i++) {
			myassets[i] = Medicine(i+1);
			loadMdc();
		}
	}
	void loadMdc();
	void loadMdcd(int x, int y);
};

void checkMouseStatus(int& msx, int& msy, int& msg);
int checkAndReturnKBStatus(char& kbval);

//6.页面大类（集成背景图、出现的病情数值、病情的文字资料）
//7.资源类（到山上采集获得的药材资源）
