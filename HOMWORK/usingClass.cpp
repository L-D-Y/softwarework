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
	// �������¼�
	msg = 0;
	MOUSEMSG m = GetMouseMsg();
	// �����������
	msx = m.x;
	msy = m.y;
	// ��������¼�����msg��ֵ
	if (m.uMsg == WM_LBUTTONDOWN) {
		msg = 1; // �������
	}
	else if (m.uMsg == WM_LBUTTONUP) {
		msg = 2; // ���̧��
	}
	else {
		msg = 0; // û������¼�
	}
}

int checkAndReturnKBStatus(char& kbval) {
	// ����Ƿ��м�������
	if (_kbhit()) {
		// ��ȡ����ֵ������ȫ�ֱ���kbval
		kbval = _getch();
	}
	// ���kbval����ESC����ASCII�루27��������3
	if (kbval == 27) {
		return 3;
	}
	// ���򷵻�0������ֵ
	return 0;
}