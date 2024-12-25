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
char arr[][20] = { "��ʼ��Ϸ","ҩ�Ĳɼ�","ҩ������","����","����","����" };
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
extern const char* const judge[4] = { "���ֻش������","���Ǻ��ˣ����ܾ��ò��þ�����","�Ҹо���̫�ԡ�","��û�ˣ�����" };
extern char phenomenon[][100] = { "�񺮷��ȣ�ͷ����ʹ���޺���������̦���ף���������"};
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
	// ��ʼ��ͼ�δ���
	initgraph(1280, 720);
	loadR();
	// ����˫�����ͼģʽ
	BeginBatchDraw();
	int mode = 0;
	auto lastTime = std::chrono::high_resolution_clock::now();
	while (true)
	{
		
		//��ҳ
		if (mode == 0)
		{
			cleardevice();
			while (true) {
				page = 0;
				begin(lastTime, msx, msy, msg, kbval);
				// ���û�ͼ����
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
				// ����˫�����ͼģʽ����ʾ����������
				FlushBatchDraw();

			}
		}
		//ѡ��ҳ
		else if (mode == 11) {
			cleardevice();
			while (true)
			{
				begin(lastTime, msx, msy, msg, kbval);
				page = drawTransparentLayer(kbval, msx, msy, msg);
				if (page == 1) {
					//����Ϸ
					kbval = 0;
					mode = 1;
					break;
				}
				else if (page == 2) {
					//�ص���ҳ
					kbval = 0;
					mode = 0;
					break;
				}
				else if (page == 3) {
					//�˻�����
					kbval = 0;
					mode = 999;
					break;
				}
				else if (page == 4) {
					//ҩ�Ĳɼ�
					kbval = 0;
					mode = 2;
					break;
				}
				FlushBatchDraw();
			}
		}
		//����Ϸҳ
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
		//ҩ�Ĳɼ�ҳ
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
