//#include "sup.h"
//#include<easyx.h>
//#include<conio.h>
//#include <iostream>
//#include <iostream>
//#include <string>
//#include <fstream>
//#include <easyx.h>
//#include <graphics.h>
//#include <codecvt>
//#include <locale>
//////extern LPCTSTR Pic_Src[10];
////extern std::string Txt_Src[10];
//extern std::string Name[100] = { "���","��֦","����","�˸ʲ�" };
//extern const char* const picture[] = {
//	"./resource/mahuang.jpeg",
//	"./resource/guizhi.jpeg",
//	"./resource/xinren.jpeg",
//	"./resource/gancao.jpeg",
//};
//extern const char* const txt[] = {
//	"./txt./mahuang.txt"
//};
//
//extern const char* const Data[] = {
//	"./resource/data1.jpeg"
//};
//
//void displayTxt(std::string s, int x, int y) {
//	std::ifstream file(s);
//	std::string line;
//	if (file.is_open()) {
//		while (std::getline(file, line)) {
//			outtextxy(20, y, line.c_str());
//			y += 50; // ������һ���ı��Ĵ�ֱλ��
//		}
//		file.close();
//	}
//	else {
//		outtextxy(100, 100, "�޷����ļ�");
//	}
//}
//
//Medicine::Medicine(int ind) {
//	index = ind;
//	name = Name[index];
//	loadimage(pic, picture[index], 300, 400);
//}
//
////