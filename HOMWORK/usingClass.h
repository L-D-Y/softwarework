#pragma once
#include <iostream>
#include <conio.h>
#include <graphics.h>

using namespace std;
#include <fstream>
#include <string>

extern const char* const mName[];
extern const char* const picture[];

class disease {
public:
	int token;
	string name;
	string discribe;
};
//3.ͼ���ࣨ����ͼ��
class Medicine {
public:
	// ��ֵ
	int token;
	int num;
	Medicine() {};
	Medicine(int token) {
		token = token;
		num = 0;
	}
};//4.������

//5.��ֵ�ж���
class player {
public:
	int point;
	Medicine myassets[10];
	IMAGE myimg[10];
	static const char* const imgRoad[];
	player() {
		point = 0;
		for (int i = 0; i < 6; i++) {
			myassets[i] = Medicine(i);
		}
	}
	void loadMdc();
	void loadMdcd(int x, int y);
};

//6.ҳ����ࣨ���ɱ���ͼ�����ֵĲ�����ֵ��������������ϣ�
//7.��Դ�ࣨ��ɽ�ϲɼ���õ�ҩ����Դ��
