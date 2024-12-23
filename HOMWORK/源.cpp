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
char arr[][20] = { "����Ϸ","ҩ�Ĳɼ�","ҩ������","����","����","����" };
//����������
char kbval = 0;
// ����ȫ�ֱ���
int msg = 0; // 0��ʾû������¼���1��ʾ������£�2��ʾ���̧��
int msx = 0; // ���x����
int msy = 0; // ���y����
int index = 0;
extern const char* const mName[100] = { "���","��֦","����","�˸ʲ�" ,"����","����" };
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
extern const char* const judge[4][100] = { "���ֻش������","���Ǻ��ˣ����ܾ��ò��þ�����","�Ҹо���̫�ԡ�","��û�ˣ�����" };
extern char phenomenon[][100] = { "�񺮷��ȣ�ͷ����ʹ���޺���������̦���ף���������","��֦","����","�˸ʲ�" ,"����","����" };

int page = 0;
IMAGE bg;
IMAGE bg1;
IMAGE btn;
IMAGE bag2;
void draw();
void loadR() {
	loadimage(&bg, "./resource/bg.png", getwidth(), getheight());
	loadimage(&bg1, "./resource/bg1.jpg", getwidth(), getheight());
	loadimage(&btn, "./resource/btn.png", 200, 50);
	loadimage(&bag2, "./resource/bg2.jpeg", getwidth(), getheight());

}
bool contain(int rx, int ry, int m_x, int m_y);
int changePage(int msx, int msy, int msg);
void printPoint(player pl);
void begin(std::chrono::steady_clock::time_point lastTime, int& msx, int& msy, int& msg, char& kbval);

int mainPage(player pl, std::chrono::steady_clock::time_point lastTime, int& msx, int& msy, int& msg, char& kbval);
int newGame(int num, player pl, int index, std::chrono::steady_clock::time_point lastTime, int& msx, int& msy, int& msg, char& kbval);
int Option(std::chrono::steady_clock::time_point lastTime, int& msx, int& msy, int& msg, char& kbval);
int select(int num, player pl, int index, std::chrono::steady_clock::time_point lastTime, int& msx, int& msy, int& msg, char& kbval);

int main() {
	player myPlayer;
	myPlayer.point = 0;
	int num = 0;
	int token = 1;
	
	loadArrow();
	// ��ʼ��ͼ�δ���
	initgraph(1280, 720);
	// ����˫�����ͼģʽ
	BeginBatchDraw();
	int mode = 0;
	auto lastTime = std::chrono::high_resolution_clock::now();
	/*while (1)
	{
		if (mode == 0) {
			mode = mainPage(myPlayer, lastTime, msx, msy, msg, kbval);
		}
		else if (mode == 1) {
			mode = newGame(num, myPlayer, index, lastTime, msx, msy, msg, kbval);
		}
		else if (mode == 4) {
			mode = Option(lastTime, msx, msy, msg, kbval);
		}
		else if (mode == 2) {
			mode = select(num, myPlayer, index, lastTime, msx, msy, msg, kbval);
		}
		else if (mode == 999) {
			return 0;
		}
	}*/
start:
	loadR();

	while (true) {
		begin(lastTime, msx, msy, msg, kbval);
		char arr[][20] = { "����Ϸ","ҩ�Ĳɼ�","ҩ������","����","����","����" };
		// ���û�ͼ����
		draw();
		page = changePage(msx, msy, msg);
		if (page == 1)goto ng1;
		else if (page == 2)goto select;
		else if (page == 6 && msg == 1)ShellExecute(NULL, "open", "https://www.baidu.com", NULL, NULL, SW_SHOWNORMAL);
		printPoint(myPlayer);
		// ����˫�����ͼģʽ����ʾ����������
		FlushBatchDraw();
	}
option:
	cleardevice();
	while (true)
	{
		begin(lastTime, msx, msy, msg, kbval);
		page = drawTransparentLayer(kbval, msx, msy, msg);
		if (page == 1)goto ng1;
		else if (page == 2)goto start;
		else if (page == 3) goto end;
		else if (page == 4) goto select;
		FlushBatchDraw();
	}

ng1:
	cleardevice();
	while (1)
	{
		begin(lastTime, msx, msy, msg, kbval);
		putimage(0, 0, &bg1);
		drawRectangle();

		drawArrow();

		int i = drawImage(myPlayer, index);
		if (i != -1)myPlayer.myassets[i].num++;
		printPoint(myPlayer);
		drawDisease(num);

		if (kbval == 27)goto option;

		FlushBatchDraw();
	}
select:

	while (3)
	{
		begin(lastTime, msx, msy, msg, kbval);
		putimage(0, 0, &bag2);

		printPoint(myPlayer);
		drawSlct(myPlayer);
		if (kbval == 27)goto option;
		FlushBatchDraw();
	}
end:
	return 0;
}

void begin(std::chrono::steady_clock::time_point lastTime, int& msx, int& msy, int& msg, char& kbval) {
	setbkmode(TRANSPARENT);
	check(lastTime);
	// ���ú���������״̬�������������
	checkMouseStatus(msx, msy, msg);
	checkAndReturnKBStatus(kbval);
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
	delete[] buffer;
};
//��ҳת��ҳ��
int changePage(int msx, int msy, int msg) {
	for (int i = 0; i < 6; i++) {
		//�����ͣ
		if (contain(100, 200 + i * 50, msx, msy)) {
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

int mainPage(player pl, std::chrono::steady_clock::time_point lastTime, int& msx, int& msy, int& msg, char& kbval) {
	loadR();

	while (true) {
		begin(lastTime, msx, msy, msg, kbval);
		char arr[][20] = { "����Ϸ","ҩ�Ĳɼ�","ҩ������","����","����","����" };
		// ���û�ͼ����
		draw();
		page = changePage(msx, msy, msg);
		if (page == 1)return 1;
		else if (page == 2)return 2;
		else if (page == 3)return 3;
		else if (page == 6 && msg == 1)ShellExecute(NULL, "open", "https://www.baidu.com", NULL, NULL, SW_SHOWNORMAL);
		printPoint(pl);
		// ����˫�����ͼģʽ����ʾ����������
		FlushBatchDraw();
	}
}

int Option(std::chrono::steady_clock::time_point lastTime, int& msx, int& msy, int& msg, char& kbval) {
	loadR();

	while (true)
	{
		begin(lastTime, msx, msy, msg, kbval);
		page = drawTransparentLayer(kbval, msx, msy, msg);
		if (page == 1)return 1;
		else if (page == 2)return 0;
		else if (page == 3) return 999;
		else if (page == 4) return 2;
		FlushBatchDraw();
	}
}

int newGame(int num, player pl, int index, std::chrono::steady_clock::time_point lastTime, int& msx, int& msy, int& msg, char& kbval) {
	loadR();
	while (1)
	{
		begin(lastTime, msx, msy, msg, kbval);
		putimage(0, 0, &bg1);
		drawRectangle();

		drawArrow();

		drawImage(pl, index);
		printPoint(pl);
		drawDisease(num);

		if (kbval == 27)return 4;

		FlushBatchDraw();
	}
}

int select(int num, player pl, int index, std::chrono::steady_clock::time_point lastTime, int& msx, int& msy, int& msg, char& kbval) {
	while (3)
	{
		begin(lastTime, msx, msy, msg, kbval);
		printPoint(pl);
		drawSlct(pl);
		if (kbval == 27)return 4;
		FlushBatchDraw();
	}
}