#pragma once
#include "sup.h"
using namespace std;

#include "Setting.h"
#include "resource.h"
#include "usingClass.h"
#include <iostream>
#include <codecvt>
#include <conio.h>
using namespace std;
#include <fstream>
#include <string>
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
//2.����ѡ�ť
//3.������ͼ���仯
void drawImage(player pl, int index);
//4.����¼�/�����¼�������ת
//����ҩ�Ĳɼ�����
void drawSlct(player pl);
//6.
//7.
//8.
//9.
//10.
