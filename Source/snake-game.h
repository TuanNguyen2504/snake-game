#pragma once
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include <mmsystem.h> //Thư viện dùng để chèn nhạc

#pragma comment (lib, "winmm.lib") //chèn thư viện phát nhạc

using namespace std;

#define xConsole 50
#define yConsole 25

// tao kieu du lieu moi
enum control { Up, Down, Left, Right };

struct toaDo {
	int x;
	int y;
};

struct snake {

	toaDo hinhdang[100]; //số đốt tối đa của con rắn là 100
	control move;
	int len; //số đốt của con rắn
	int point;
	int mangSong;
	string name;
	int tocDo;
	int level;
};

struct food {
	toaDo toado;
};

struct vatCan {
	toaDo hinhDang[100];
	int chieuDai;
};

//các hàm sử dụng

void gotoXY(int, int);

void clrscr();

void ShowConsoleCursor(bool);

void TextColor(int);

void khoiTao(snake&, food&, vatCan&, int);

void veManHinh();

void veVatCan(snake, vatCan&);

void hienThi(snake, food, toaDo&, toaDo&);

void move_Control_snake(snake&);

void thaoTac(snake&, food&, vatCan);

int gameOver(snake&, vatCan);

void main_Game(snake&, food&);

void menu(snake&, food&);

void thaoTac_autoSnake(snake&, food&, vatCan);

void timCot(snake&, food);

void timHang(snake&, food);

void autoControlSnake(snake&, food);

void main_Game_2(snake&, food&);

void huongDan();


