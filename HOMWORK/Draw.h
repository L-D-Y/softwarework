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

//1.���Ʊ���ͼ
//�ж�Ӧ����ͼ
void drawRectangle();
//��߳�������ͼƬ���������������Σ����
int drawArrow();
void loadArrow();
//esc ����ѡ��ͼ
int drawTransparentLayer(char key, int msx, int msy, int msg);
//3.����ӵ��ҩ����ͼ���仯��ͬʱ���ڸú�������Ҫ���Ƿ�����ͼƬ�����жϣ��񷵻� -1 ���Ƿ��ض�Ӧ��player::myassets�±�
int drawImage(player pl, int index);
//����ҩ�Ĳɼ�����
int drawSlct(player pl);
//6.���Ʋ���
void drawDisease(int index);
void drawUseMdc(int a1, int a2, int a3, int a4);
void drawResult(player* pl, int correct, int count);
void check(std::chrono::steady_clock::time_point lastTime);
