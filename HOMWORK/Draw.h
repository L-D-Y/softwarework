#pragma once
#include "sup.h"
#include "Setting.h"
#include "resource.h"
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

//˫�����ͼ
//esc ����ѡ��ͼ
int drawTransparentLayer(char key, int msx, int msy, int msg);
int option(int msx, int msy, int msg, IMAGE btn);
//3.����ӵ��ҩ����ͼ���仯��ͬʱ���ڸú�������Ҫ���Ƿ�����ͼƬ�����жϣ��񷵻� -1 ���Ƿ��ض�Ӧ��player::myassets�±�
int drawImage(player pl, int index);
//4.����¼�/�����¼�������ת
//����ҩ�Ĳɼ�����
int drawSlct(player pl);
//6.���Ʋ���
void drawDisease(int index);
//7.
void check(std::chrono::steady_clock::time_point lastTime);

//8.
//9.
//10.
