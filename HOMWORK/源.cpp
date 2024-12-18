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
char arr[][20] = { "����Ϸ","ҩ�Ĳɼ�","ҩ������","����","����","����" };
//����������
char kbval = 0;
// ����ȫ�ֱ���
int msg = 0; // 0��ʾû������¼���1��ʾ������£�2��ʾ���̧��
int msx = 0; // ���x����
int msy = 0; // ���y����
int index = 0;
disease dis[10];
extern const char* const mName[100] = { "���","��֦","����","�˸ʲ�" ,"����","����"};
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

// ��������
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
	dis[0].discribe = "��з纮��ʵ֤���񺮷��ȣ�ͷ����ʹ���޺���������̦���ף���������";
	myPlayer.loadMdc();
	loadArrow();
	// ��ʼ��ͼ�δ���
	initgraph(1280, 720);
	// ����˫�����ͼģʽ
	BeginBatchDraw();
	auto lastTime = std::chrono::high_resolution_clock::now();
start:
	loadR();

	while (true) {
		begin(lastTime);
		char arr[][20] = { "����Ϸ","ҩ�Ĳɼ�","ҩ������","����","����","����" };
		// ���û�ͼ����
		draw();
		page = changePage(msx, msy, msg);
		if (page == 1)goto ng1;
		else if (page == 2)goto select;
		printPoint(myPlayer);
		// ����˫�����ͼģʽ����ʾ����������
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
	// ���ú���������״̬�������������
	checkMouseStatus(msx, msy);
	checkAndReturnKBStatus();
	// ��ջ�����
	cleardevice();
}

//��ӡ����
void printPoint(player pl) {
	// �����ı���ɫ�ͱ���ģʽ
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);

	// ���������С
	settextstyle(24, 0, _T("Arial"));

	// ��intת��Ϊ�ַ���
	int length = snprintf(nullptr, 0, "%d", pl.point);
	char* buffer = new char[length + 1]; // �����㹻���ڴ����洢�ַ������������
	// ������ת��Ϊ�ַ��������洢��buffer��
	snprintf(buffer, length + 1, "%d", pl.point);
	// �����ı��Ŀ�Ⱥ͸߶�
	int tw = 200;
	int th = 200;

	// �����Ͻǻ����ı�
	outtextxy(1280 - tw - 10, 10, "Point");

	outtextxy(1280 - tw - 10, 30, buffer);
};
//��ҳת��ҳ��
int changePage(int msx, int msy, int msg) {
	for (int i = 0; i < 6; i++) {
		//�����ͣ
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

		//Ĭ����ʾ
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

//�Ż�֡����˸
void check(std::chrono::steady_clock::time_point lastTime) {
	// �������ϴ�ѭ��������ʱ���
	auto currentTime = std::chrono::high_resolution_clock::now();
	auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastTime).count();

	// ���ʱ���С�������ʱ������������
	if (elapsedTime < 1000 / 30) {
		std::this_thread::sleep_for(std::chrono::milliseconds((1000 / 30) - elapsedTime));
	}

	// �����ϴ�ѭ��ʱ��
	lastTime = std::chrono::high_resolution_clock::now();
};
//��ҳ��ͼ
void draw() {
	putimage(0, 0, &bg);
	settextcolor(RGB(250, 200, 200));
	settextstyle(30, 0, "����");
	outtextxy(100, 50, "���ݸ�Ŀ");
	int th = textheight("���ݸ�Ŀ");
	setfillcolor(WHITE);
	solidrectangle(0, th + 55, 200, 60 + th);
	settextstyle(20, 0, "����");
	outtextxy(100, 70 + th, "������");
	settextcolor(WHITE);
	settextstyle(30, 0, "���Ŀ���");
}

//��ȡ�����Ϣ
void checkMouseStatus(int& msx, int& msy) {
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

//��ȡ������Ϣ
int checkAndReturnKBStatus() {
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