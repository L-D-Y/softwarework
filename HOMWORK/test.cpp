//#include<easyx.h>
//#include<conio.h>
//#include <graphics.h>
//#include <conio.h>
//#include <fstream>
//#include <string>
//using namespace std;
//#include "sup.h"
//#include "usingClass.cpp"
//#pragma comment(lib,"MSIMG32.LIB")
//
//IMAGE bg;
//IMAGE btn;
//IMAGE bg1;
//IMAGE bgd;
//IMAGE back;
//int isin[4] = { 0,0,0,0 };
//int mx;
//int my;
//int d = 0;
//int ty = 200;
//char filePath[]  = "./resource/bg.png";
//char arr[][20] = { "����Ϸ","ҩ�Ĳɼ�","ҩ������","����","����","����" };
////extern const char* const picture[];
////extern const char* const txt[];
//void loadR() {
//	loadimage(&bg,filePath , getwidth(), getheight());
//	loadimage(&btn, "./resource/btn.png", 200, 50);
//	loadimage(&bg1, "./resource/bg1.jpg", getwidth(), getheight());
//	loadimage(&back, "./resource/back.jpeg", 100, 100);
//}
//
//bool contain(int rx, int ry, int m_x, int m_y) {
//	if (m_x > rx - 30 && m_x<rx + 170 && m_y>ry && m_y < ry + 50) {
//		return true;
//	}
//	return false;
//}
//
//bool isIn(int x, int y, int size, int sx, int sy) {
//	if (sx >= x && sx <= x + size && sy >= y && sy <= y + size)return  true;
//	return false;
//}
//
//void drawPng(int x, int y, IMAGE* img) {
//	//��ȡ����͸��
//	HDC dstDc = GetImageHDC(NULL);
//	//��ȡͼ��͸��
//	HDC srcDc = GetImageHDC(img);
//	int w = img->getwidth();
//	int h = img->getheight();
//
//	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
//	AlphaBlend(dstDc, x, y, w, h, srcDc, 0, 0, w, h, bf);
//}
//
//void draw() {
//	putimage(0, 0, &bg);
//
//	settextcolor(RGB(250, 200, 200));
//	settextstyle(30, 0, "����");
//
//	outtextxy(100, 50, "���ݸ�Ŀ");
//	int th = textheight("���ݸ�Ŀ");
//	setfillcolor(WHITE);
//	solidrectangle(0, th + 55, 200, 60 + th);
//
//	settextstyle(20, 0, "����");
//	outtextxy(100, 70 + th, "������");
//
//	settextcolor(WHITE);
//	settextstyle(30, 0, "���Ŀ���");
//}
//
//void mouseEvent() {//��׽�������
//	ExMessage msg;
//	if (peekmessage(&msg, EX_MOUSE)) {
//		mx = msg.x;
//		my = msg.y;
//	}
//}
//
//int main()
//{
//	// ��ʼ��ͼ�δ���
//	initgraph(1280, 720);
//	// ������ͼ������
//	IMAGE buffer(1280, 720);
//	cleardevice();
//
//	// ���ر���ͼƬ
//	IMAGE background;
//	loadR();
//
//	// ������קͼƬ
//
//	// ��ȡͼƬ��С
//	int width = btn.getwidth();
//	int height = btn.getheight();
//
//	// ͼƬ��ʼλ��
//	int x = 100;
//	int y = 100;
//
//	// ���״̬
//	bool isDragging = false;
//	int offsetX = 0;
//	int offsetY = 0;
//	setbkmode(0);
//	//IMAGE buffer(1280, 720);
//	BeginBatchDraw();
//
//	while (TRUE) {
//		cleardevice();
//		draw();
//
//		for (int i = 0; i < 6; i++) {
//			//�����ͣ
//			ExMessage msg;
//			if (peekmessage(&msg, EX_MOUSE)) {
//				mx = msg.x;
//				my = msg.y;
//			}
//			if (contain(100, ty + i * 50, mx, my)) {
//				//drawPng(70, ty + i * 50-10, &btn);
//				putimage(70, ty + i * 50 - 10, &btn);
//				settextcolor(BLACK);
//				outtextxy(100, ty + 50 * i, arr[i]);
//				if (contain(100, ty, mx, my)) {
//					if (msg.message == WM_LBUTTONDOWN) {
//						cleardevice();
//						goto newgame;
//					}
//				}
//				else if (contain(100, ty + 50 * 2, mx, my)) {
//					settextcolor(BROWN);
//					if (msg.message == WM_LBUTTONDOWN) {
//						cleardevice();
//
//
//					}
//				}
//
//				settextcolor(WHITE);
//				continue;
//			}
//
//			//Ĭ����ʾ
//			outtextxy(100, ty + 50 * i, arr[i]);
//		}
//
//		FlushBatchDraw();
//	}
//
//newgame:
//	while (!_kbhit())
//	{
//		cleardevice();
//		IMAGE mds[4];
//		for (int i = 0; i < 4; i++) {
//			loadimage(&mds[i], picture[i], 200, 150);
//		}
//
//		//��ȡ���״̬
//		MOUSEMSG msg = GetMouseMsg();
//		switch (msg.uMsg)
//		{
//		case WM_LBUTTONDOWN:
//			// �ж�����Ƿ���ͼƬ��Χ��
//			if (msg.x >= x && msg.x <= x + width && msg.y >= y && msg.y <= y + height)
//			{
//				isDragging = true;
//				offsetX = msg.x - x;
//				offsetY = msg.y - y;
//			}
//			break;
//		case WM_MOUSEMOVE:
//			if (isDragging)
//			{
//				// ����ͼƬλ��
//				x = msg.x - offsetX;
//				y = msg.y - offsetY;
//			}
//			break;
//		case WM_LBUTTONUP:
//			isDragging = false;
//			break;
//		}
//
//		//�ڻ������ϻ��Ʊ���ͼƬ
//		putimage(0, 0, &bg1);
//
//		// �ڻ������ϻ�����קͼƬ
//
//		setlinecolor(RED);
//		std::string t[] = { "��","��","ʹ","��" };
//		for (int i = 0; i < 4; i++) {
//			fillrectangle(165 + 250 * i, 200, 365 + 250 * i, 350);
//			outtextxy(185 + 250 * i, 250, t[i].c_str());
//			if (msg.x >= 165 + 250 * i && msg.x <= 365 + 250 * i && msg.y >= 400 && msg.y <= 550) {
//				if (msg.uMsg == WM_LBUTTONDOWN)isin[i] = 1;
//			}
//		}
//		for (int i = 0; i < 4; i++) {
//			if (isin[i] == 0)putimage(165 + 250 * i, 400, &mds[i]);
//			else putimage(165 + 250 * i, 200, &mds[i]);
//		}
//		if (isin[0] == 1 && isin[1] == 1 && isin[2] == 1 && isin[3] == 1)
//		{
//			settextcolor(RED);
//			outtextxy(300, 500, "���ֻش������");
//		}
//
//		putimage(x, y, &btn);
//		putimage(100, 100, &back);
//
//		//if (isIn(100, 100, 100, msg.x, msg.y)) {
//		//    putimage(100+20, 100+20, &back);
//		//    settextcolor(BLACK);
//		//    outtextxy(100,200, arr[2]);
//		//    continue;
//		//}
//		//putimage(100, 100, &back);
//
//		//putimage(0, 0, &buffer);
//		// ˢ����Ļ
//		FlushBatchDraw();
//	}
//
////data:
////	while (TRUE) {
////		//IMAGE buffer2(1280, 720);
////		loadimage(&bgd, Data[d], getwidth(), getheight());
////		// �ڻ������ϻ��Ʊ���ͼƬ
////		putimage(0, 0, &bgd);
////		//putimage(100, 100, &back),
////
////		// �ڻ������ϻ�����קͼƬ
////		// ˢ����Ļ
////		FlushBatchDraw();
////	}
////	EndBatchDraw();
//
//	// �ر�ͼ�δ���
//	closegraph();
//
//	return 0;
//}
//