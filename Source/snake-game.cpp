#include "snake-game.h"

//Đưa đến vị trí tọa độ (x,y)
void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//ham xoa con tro
void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

//Hàm xóa màn hình thay cho system("cls")

void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

//Đổi màu

void TextColor(int x)
{
	HANDLE Color;

	Color = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(Color, x);
}

//Khởi tạo rắn và thức ăn

void khoiTao(snake& ran, food& thucan, vatCan& a, int dokho)
{
	//Khởi tạo con rắn
	ran.len = 2;
	ran.hinhdang[0].x = 1;
	ran.hinhdang[0].y = 1;
	ran.move = Down;

	//Khởi tạo thức ăn
	thucan.toado.x = xConsole / 2 + 4;
	thucan.toado.y = yConsole / 2;

	//Khởi tạo điểm
	ran.point = 0;

	//khởi tạo mạng sống
	ran.mangSong = 3;

	//Khởi tạo tốc độ con rắn
	ran.tocDo = dokho;

	//Khởi tạo level

	ran.level = 1;

	//khởi tạo vật cản
	a.chieuDai = 0;

}

//Vẽ màn hình

void veManHinh()
{
	//In ra 2 biên

	for (int i = 0; i < yConsole; ++i)
	{
		gotoXY(xConsole, i);
		TextColor(13);
		putchar(179);

	}
	for (int i = 0; i < xConsole; ++i)
	{
		gotoXY(i, yConsole - 1);
		TextColor(13);
		putchar('_');

	}
}

//Vẽ vật cản

void veVatCan(snake ran, vatCan& a)
{
	if (ran.level == 2)
	{
		a.chieuDai = 0;

		//Vẽ vật cản a

		for (int k = 0; k < 10; ++k)
		{
			gotoXY(10 + k, 10);
			TextColor(13);
			putchar(4);
			a.hinhDang[k].x = 10 + k;
			a.hinhDang[k].y = 10;
			++a.chieuDai;
		}

		for (int k = 10; k < 20; ++k)
		{
			gotoXY(2 + k, 15);
			TextColor(13);
			putchar(4);
			a.hinhDang[k].x = 2 + k;
			a.hinhDang[k].y = 15;
			++a.chieuDai;
		}

		for (int k = 20; k < 30; ++k)
		{
			gotoXY(k + 10, 10);
			TextColor(13);
			putchar(4);
			a.hinhDang[k].x = k + 10;
			a.hinhDang[k].y = 10;
			++a.chieuDai;
		}

		for (int k = 30; k < 40; ++k)
		{
			gotoXY(2 + k, 15);
			TextColor(13);
			putchar(4);
			a.hinhDang[k].x = 2 + k;
			a.hinhDang[k].y = 15;
			++a.chieuDai;
		}

	}

	if (ran.level == 3)
	{
		//Khởi tạo tọa độ vât cản a
		a.chieuDai = 0;

		//vẽ vật cản a

		for (int k = 0; k < 10; ++k)
		{
			gotoXY(10 + k, 5);
			TextColor(13);
			putchar(4);
			a.hinhDang[k].x = 10 + k;
			a.hinhDang[k].y = 5;
			++a.chieuDai;
		}

		for (int k = 10; k < 25; ++k)
		{
			gotoXY(15 + k, 5);
			TextColor(13);
			putchar(4);
			a.hinhDang[k].x = 15 + k;
			a.hinhDang[k].y = 5;
			++a.chieuDai;
		}

		for (int k = 25; k < 30; ++k)
		{
			gotoXY(40, k - 20);
			TextColor(13);
			putchar(4);
			a.hinhDang[k].x = 40;
			a.hinhDang[k].y = k - 20;
			++a.chieuDai;
		}

		for (int k = 30; k < 36; ++k)
		{
			gotoXY(40, k - 15);
			TextColor(13);
			putchar(4);
			a.hinhDang[k].x = 40;
			a.hinhDang[k].y = k - 15;
			++a.chieuDai;
		}

		for (int k = 36; k < 45; ++k)
		{
			gotoXY(10, k - 25);
			TextColor(13);
			putchar(4);
			a.hinhDang[k].x = 10;
			a.hinhDang[k].y = k - 25;
			++a.chieuDai;
		}

		for (int k = 45; k < 65; ++k)
		{
			gotoXY(k - 35, 20);
			TextColor(13);
			putchar(4);
			a.hinhDang[k].x = k - 35;
			a.hinhDang[k].y = 20;
			++a.chieuDai;
		}

		for (int k = 65; k < 70; ++k)
		{
			gotoXY(k - 30, 20);
			TextColor(13);
			putchar(4);
			a.hinhDang[k].x = k - 30;
			a.hinhDang[k].y = 20;
			++a.chieuDai;
		}

		for (int k = 70; k < 90; ++k)
		{
			gotoXY(k - 55, 13);
			TextColor(13);
			putchar(4);
			a.hinhDang[k].x = k - 55;
			a.hinhDang[k].y = 13;
			++a.chieuDai;
		}

		for (int k = 90; k < 98; ++k)
		{
			gotoXY(25, k - 80);
			TextColor(13);
			putchar(4);
			a.hinhDang[k].x = 25;
			a.hinhDang[k].y = k - 80;
			++a.chieuDai;
		}
	}
}

//Hiển thị rắn và thức ăn

void hienThi(snake ran, food thucan, toaDo& cuoi, toaDo& keCuoi)
{
	//hiển thị đầu rắn

	gotoXY(ran.hinhdang[0].x, ran.hinhdang[0].y);
	putchar(2);

	//hiển thị các đốt của con rắn

	srand((unsigned)time(NULL));
	for (int i = 1; i < ran.len; ++i)
	{
		gotoXY(ran.hinhdang[i].x, ran.hinhdang[i].y);
		TextColor(rand() % 14 + 1);
		putchar(236);

	}

	//Lưu lại vị trí 2 đốt cần xóa sau khi di chuyển rắn (đốt cuối, kế cuối)

	keCuoi = ran.hinhdang[ran.len - 2]; //vị trí kế cuối
	cuoi = ran.hinhdang[ran.len - 1]; //vị trí cuối

	//Hiển thị thức ăn
	srand((unsigned)time(NULL));
	gotoXY(thucan.toado.x, thucan.toado.y);
	TextColor(rand() % 14 + 1);
	putchar(6);


	//Hiển thị tên

	gotoXY(xConsole + 2, 1);
	TextColor(11);
	cout << "Ten: ";
	TextColor(rand() % 14 + 1);
	cout << ran.name;

	//Hiển thị điểm.

	gotoXY(xConsole + 2, 3);
	TextColor(10);
	cout << "Diem: ";
	TextColor(rand() % 14 + 1);
	cout << ran.point;

	//Hiển thị mạng sống

	gotoXY(xConsole + 2, 5);
	TextColor(9);
	cout << "Mang Song <3 : ";
	TextColor(rand() % 14 + 1);
	cout << ran.mangSong;

	//Hiển thị Level

	gotoXY(xConsole + 2, 7);
	TextColor(8);
	cout << "Level: ";
	TextColor(rand() % 14 + 1);
	cout << ran.level;

	//Hiển thị điểm cần để lên level

	gotoXY(xConsole + 2, 9);
	switch (ran.level)
	{
	case 1:
		TextColor(6);
		cout << "Level Up can: " << 1000;
		break;
	case 2:
		TextColor(6);
		cout << "Level Up can: " << 2000;
		break;
	case 3:
		TextColor(6);
		cout << "Chien thang can: " << 4000;
		break;
	}

	//hien thi chu thich
	srand((unsigned)time(NULL));
	gotoXY(xConsole + 3, 11);
	TextColor(rand() % 14 + 1);
	cout << "=========o0o=========";



	gotoXY(xConsole + 9, 13);
	TextColor(rand() % 14 + 1);
	cout << "Nhan Tab";
	gotoXY(xConsole + 2, 15);
	cout << "de xem huong dan day du ne.";

	gotoXY(xConsole + 7, 17);
	TextColor(rand() % 14 + 1);
	cout << "Nhan E mo nhac";
	gotoXY(xConsole + 4, 19);
	cout << "Nhan Z de tat nhac ne.";

	gotoXY(xConsole + 3, 21);
	TextColor(rand() % 14 + 1);
	cout << "Nhan Space de tam dung.";
	gotoXY(xConsole + 5, 23);
	cout << "Nhan Q de tang mang.";

}

//Điều khiển và di chuyển rắn

void move_Control_snake(snake& ran)
{
	vatCan a;

	//thay đổi các vị trí thân con rắn

	for (int i = ran.len - 1; i > 0; --i)
	{
		ran.hinhdang[i].x = ran.hinhdang[i - 1].x;
		ran.hinhdang[i].y = ran.hinhdang[i - 1].y;
	}

	// kbhit() hàm bắt được phím nhập vào trong thư viện windows.h

	fflush(stdin);

	if (_kbhit())
	{
		//phím nhâp vào
		char key = _getch();

		//Các phím điều khiển
		switch (key)
		{
		case 'A': case 'a': case  75:
		{
			if (ran.move != Right)
				ran.move = Left;
			break;
		}
		case 'D': case 'd': case  77:
		{
			if (ran.move != Left)
				ran.move = Right;
			break;
		}
		case 'W': case 'w': case  72:
		{
			if (ran.move != Down)
				ran.move = Up;
			break;
		}
		case 'S': case 's': case  80:
		{
			if (ran.move != Up)
				ran.move = Down;
			break;
		}

		//Tạm dừng màn hình (phim space)

		case 32:
		{
			gotoXY(xConsole / 2 - 20, yConsole / 2);
			cout << "TAM DUNG. (nhan phim bat ki de tiep tuc)\n";
			_getch();
			clrscr();
			veManHinh();
			if (ran.level >= 2)
				veVatCan(ran, a);
			break;
		}

		//nhan Q de tang mang song

		case 'Q': case 'q':
		{
			++ran.mangSong;
			break;
		}

		//Mo huong dan (Tab)

		case 9:
		{
			clrscr();
			huongDan();
			gotoXY(80 / 2 - 20, 25 / 2 + 10);
			TextColor(rand() % 14 + 1);
			cout << "(nhan phim bat ki de tiep tuc)\n";
			_getch();
			clrscr();
			veManHinh();
			if (ran.level >= 2)
				veVatCan(ran, a);
			break;
		}

		//Play music

		case 'E': case 'e':
		{
			PlaySound(TEXT("Game_Music"), NULL, SND_ASYNC);
			break;
		}

		//Tat nhac

		case 'Z': case 'z':
		{
			PlaySound(TEXT(NULL), NULL, SND_ASYNC);
			break;
		}
		}
	}

	//Di Chuyển
	if (ran.move == Left)
		--ran.hinhdang[0].x;
	else if (ran.move == Right)
		++ran.hinhdang[0].x;
	else if (ran.move == Up)
		--ran.hinhdang[0].y;
	else if (ran.move == Down)
		++ran.hinhdang[0].y;

}

//Các thao tác xử lí trên game

void thaoTac(snake& ran, food& thucan, vatCan a)
{
	//Ăn thức ăn

	if (ran.hinhdang[0].x == thucan.toado.x && ran.hinhdang[0].y == thucan.toado.y)
	{
		//Phát âm thanh

		PlaySound(TEXT("anMoi"), NULL, SND_ASYNC);

		//rắn dài thêm

		for (int i = ran.len; i > 0; --i)
		{
			ran.hinhdang[i].x = ran.hinhdang[i - 1].x;
			ran.hinhdang[i].y = ran.hinhdang[i - 1].y;
		}
		++ran.len;

		if (ran.move == Left)
			--ran.hinhdang[0].x;
		else if (ran.move == Right)
			++ran.hinhdang[0].x;
		else if (ran.move == Up)
			--ran.hinhdang[0].y;
		else if (ran.move == Down)
			++ran.hinhdang[0].y;

		//Tăng tốc rắn

		if (ran.tocDo > 40)
			ran.tocDo -= 5;

		//Thức ăn đến chỗ khác

		srand((unsigned)time(NULL));
		thucan.toado.x = rand() % (xConsole - 5) + 2;
		thucan.toado.y = rand() % (yConsole - 5) + 2;

		//Dời vị trí thức ăn nếu trùng với vật cản

		if (ran.level >= 2)
			for (int i = 0; i < a.chieuDai; ++i)
			{
				if (thucan.toado.x == a.hinhDang[i].x && thucan.toado.y == a.hinhDang[i].y)
				{
					thucan.toado.x = rand() % (xConsole - 5) + 2;
					thucan.toado.y = rand() % (yConsole - 5) + 2;
				}
			}

		//Cộng điểm:
		ran.point += 100;

		if (ran.point == 1000)
			ran.level = 2;

		if (ran.point == 2000)
			ran.level = 3;
	}
}

//Kết thúc game, trả về 1 nếu bị chết

int gameOver(snake& ran, vatCan a)
{
	food thucAn;

	int point = ran.point; //Lưu điểm sau mỗi lần chết
	int level = ran.level; //lưu level sau mỗi lần chết
	int soMang = ran.mangSong; //lưu số mạng số

	//Kiểm tra chạm biên
	if (ran.hinhdang[0].x < 0 || ran.hinhdang[0].y < 0 || ran.hinhdang[0].x >= xConsole || ran.hinhdang[0].y >= yConsole)
	{
		PlaySound(TEXT("Boom_Sound"), NULL, SND_ASYNC);
		--soMang;
		khoiTao(ran, thucAn, a, ran.tocDo);
		Sleep(300);
		ran.mangSong = soMang;
		ran.point = point;
		ran.level = level;
		clrscr();
		veManHinh();
		if (ran.level == 2 || ran.level == 3)
			veVatCan(ran, a);
		return 1;

	}

	//Kiểm tra tự cắn mình

	for (int i = 1; i < ran.len; ++i)
		if (ran.hinhdang[0].x == ran.hinhdang[i].x && ran.hinhdang[0].y == ran.hinhdang[i].y)
		{
			PlaySound(TEXT("Boom_Sound"), NULL, SND_ASYNC);
			--soMang;
			khoiTao(ran, thucAn, a, ran.tocDo);
			Sleep(300);
			ran.point = point;
			ran.level = level;
			ran.mangSong = soMang;
			clrscr();
			veManHinh();
			if (ran.level == 2 || ran.level == 3)
				veVatCan(ran, a);
			return 1;
		}

	//Kiểm tra chạm vật cản
	if (ran.level >= 2)
	{
		for (int i = 0; i < a.chieuDai; ++i)
		{
			if (ran.hinhdang[0].x == a.hinhDang[i].x && ran.hinhdang[0].y == a.hinhDang[i].y)
			{
				PlaySound(TEXT("Boom_Sound"), NULL, SND_ASYNC);
				--soMang;
				khoiTao(ran, thucAn, a, ran.tocDo);
				Sleep(300);
				ran.point = point;
				ran.level = level;
				ran.mangSong = soMang;
				clrscr();
				veManHinh();
				if (ran.level == 2 || ran.level == 3)
					veVatCan(ran, a);
				return 1;
			}
		}
	}

	return 0;
}

//phần chính game khi chơi 1 mình

void main_Game(snake& Snake, food& thucAn)
{
	//Chọn tốc độ bắt đầu game.

	do
	{
		gotoXY(xConsole / 2 - 20, yConsole / 2 - 2);
		cout << "chon toc do bat dau (>0) (cang nho cang nhanh 50->500): ";
		cin >> Snake.tocDo;

		if (Snake.tocDo <= 0)
		{
			clrscr();
			gotoXY(xConsole / 2 - 5, yConsole / 2 - 2);
			cout << "Nhap lai: ";
		}

	} while (Snake.tocDo <= 0);

	int tocDo = Snake.tocDo;

	clrscr();

	vatCan vatcan;

	khoiTao(Snake, thucAn, vatcan, Snake.tocDo);

	toaDo cuoi, keCuoi;

	//Chạy game

	veManHinh();

	while (Snake.level == 1)
	{
		//Hiển thị con rắn
		hienThi(Snake, thucAn, cuoi, keCuoi);

		//Điều khiển con rắn

		move_Control_snake(Snake);

		//Thao tac game
		thaoTac(Snake, thucAn, vatcan);

		//Game Over
		gameOver(Snake, vatcan);

		if (Snake.mangSong == 0)
		{
			clrscr();
			PlaySound(TEXT("Game_Over"), NULL, SND_ASYNC);
			gotoXY((xConsole) / 2 + 3, yConsole / 2);
			cout << left << setw(10) << "GAME OVER :\"<.";
			gotoXY((xConsole - 17) / 2 - 4, yConsole / 2 + 2);
			cout << left << setw(15) << "Nhan Enter de thoat. Nhan Space de quay lai Menu.";
			char key;
			do
			{
				key = _getch();
				if (key == 13)
					return;
				if (key == 32)
				{
					clrscr();
					menu(Snake, thucAn);
				}
			} while (key != 13 || key != 32);
		}

		//Nhịp Game
		Sleep(Snake.tocDo);

		//xóa 2 vị trí đã lưu ở trên

		gotoXY(keCuoi.x, keCuoi.y);
		cout << " ";
		gotoXY(cuoi.x, cuoi.y);
		cout << " ";
	}

	int tamDiem = Snake.point; //lưu điểm

	//tăng level 2

	PlaySound(TEXT("Oh_Yeah"), NULL, SND_ASYNC);

	gotoXY(xConsole / 2 - 2, yConsole / 2);
	cout << "LEVEL UP";

	khoiTao(Snake, thucAn, vatcan, tocDo);
	Snake.level = 2;
	Snake.point = tamDiem;

	//Dừng màn hình lại xem
	Sleep(1000);

	clrscr();

	veManHinh();

	veVatCan(Snake, vatcan);

	while (Snake.level == 2)
	{
		//Hiển thị con rắn
		hienThi(Snake, thucAn, cuoi, keCuoi);

		//Điều khiển con rắn

		move_Control_snake(Snake);

		//Thao tac game
		thaoTac(Snake, thucAn, vatcan);

		//Game Over
		gameOver(Snake, vatcan);

		if (Snake.mangSong == 0)
		{
			clrscr();
			PlaySound(TEXT("Game_Over"), NULL, SND_ASYNC);
			gotoXY((xConsole) / 2 + 3, yConsole / 2);
			cout << left << setw(10) << "GAME OVER :\"<.";
			gotoXY((xConsole - 17) / 2 - 4, yConsole / 2 + 2);
			cout << left << setw(15) << "Nhan Enter de thoat. Nhan Space de quay lai Menu.";
			char key;
			do
			{
				key = _getch();
				if (key == 13)
					return;
				if (key == 32)
				{
					clrscr();
					menu(Snake, thucAn);
				}
			} while (key != 13 || key != 32);
		}

		//Nhịp Game
		Sleep(Snake.tocDo);

		//xóa 2 vị trí đã lưu ở trên

		gotoXY(keCuoi.x, keCuoi.y);
		cout << " ";
		gotoXY(cuoi.x, cuoi.y);
		cout << " ";
	}

	tamDiem = Snake.point;

	//tăng level 3

	PlaySound(TEXT("Oh_Yeah"), NULL, SND_ASYNC);

	gotoXY(xConsole / 2 - 2, yConsole / 2);
	cout << "LEVEL UP";

	khoiTao(Snake, thucAn, vatcan, tocDo);
	Snake.level = 3;
	Snake.point = tamDiem;

	//Dừng màn hình lại xem
	Sleep(1000);

	clrscr();

	veManHinh();

	veVatCan(Snake, vatcan);

	while (1)
	{
		//Hiển thị con rắn
		hienThi(Snake, thucAn, cuoi, keCuoi);

		//Điều khiển con rắn

		move_Control_snake(Snake);

		//Thao tac game
		thaoTac(Snake, thucAn, vatcan);

		//Game Over
		gameOver(Snake, vatcan);

		if (Snake.mangSong == 0)
		{
			clrscr();
			PlaySound(TEXT("Game_Over"), NULL, SND_ASYNC);
			gotoXY((xConsole) / 2 + 3, yConsole / 2);
			cout << left << setw(10) << "GAME OVER :\"<.";
			gotoXY((xConsole - 17) / 2 - 4, yConsole / 2 + 2);
			cout << left << setw(15) << "Nhan Enter de thoat. Nhan Space de quay lai Menu.";
			char key;
			do
			{
				key = _getch();
				if (key == 13)
					return;
				if (key == 32)
				{
					clrscr();
					menu(Snake, thucAn);
				}
			} while (key != 13 || key != 32);
		}


		//Nhịp Game
		Sleep(Snake.tocDo);

		//xóa 2 vị trí đã lưu ở trên

		gotoXY(keCuoi.x, keCuoi.y);
		cout << " ";
		gotoXY(cuoi.x, cuoi.y);
		cout << " ";

		//Chien thang
		if (Snake.point >= 4000)
		{
			clrscr();
			PlaySound(TEXT("You_Win"), NULL, SND_ASYNC);
			gotoXY((xConsole) / 2 - 1, yConsole / 2);
			cout << left << setw(10) << "YOU WIN :\">. " << Snake.name << " Vo dich :\")";
			gotoXY((xConsole - 17) / 2 - 4, yConsole / 2 + 2);
			cout << left << setw(15) << "Nhan Enter de thoat. Nhan Space de quay lai menu.";
			char key;
			do
			{
				key = _getch();
				if (key == 13)
					return;
				if (key == 32)
				{
					clrscr();
					menu(Snake, thucAn);
				}
			} while (key != 13);
		}
	}

}

//Menu
void menu(snake& ran, food& thucAn)
{

	int choose;
	gotoXY(80 / 2 - 10, 25 / 2 - 3);
	cout << "1 - Choi Game " << endl;

	gotoXY(80 / 2 - 10, 25 / 2 - 1);
	cout << "2 - auto Snake (Demo) " << endl;

	gotoXY(80 / 2 - 10, 25 / 2 + 1);
	cout << "3 - Huong Dan." << endl;

	gotoXY(80 / 2 - 10, 25 / 2 + 3);
	cout << "4 - Thoat." << endl;

	gotoXY(80 / 2 - 10, 25 / 2 + 5);
	cout << "Ban chon: ";
	cin >> choose;

	switch (choose)
	{
	case 1:
	{
		clrscr();

		//Nhap ten

		gotoXY(80 / 2 - 20, 25 / 2 - 3);
		cout << "Nhap Ten cua ban: ";
		cin.ignore();
		getline(cin, ran.name);

		clrscr();

		main_Game(ran, thucAn);

		break;
	}

	case 2:
	{
		clrscr();
		main_Game_2(ran, thucAn);
		break;
	}
	case 3:
	{
		huongDan();
		gotoXY(80 / 2 - 30, 25 / 2 + 11);
		int choose_2;
		cout << "Ban co tiep tuc choi game. Bam 1 de tiep tuc. 0 de thoat :): ";
		cin >> choose_2;
		if (choose_2 == 1)
		{
			clrscr();
			menu(ran, thucAn);
		}
		else
		{
			gotoXY(80 / 2 - 15, 25 / 2 - 1);
			cout << "Hen gap lai. Bye Bye :\">";
			Sleep(500);
			return;
		}

		break;
	}

	case 4:
		clrscr();
		gotoXY(80 / 2 - 15, 25 / 2 - 1);
		cout << "Hen gap lai. Bye Bye :\">";
		break;
	default:
		clrscr();
		gotoXY(80 / 2 - 15, 25 / 2 - 1);
		cout << "Nhap lai ne :\"<";
		Sleep(1000);
		clrscr();
		menu(ran, thucAn);
		break;
	}
}

//	Tự tìm đến cột chứa thức ăn

void timCot(snake& ran, food thucAn)
{
	if (thucAn.toado.x - ran.hinhdang[0].x > 0)
	{
		if (ran.move != Left)
			ran.move = Right;
		else
			if (ran.hinhdang[0].y - ran.hinhdang[ran.len - 1].y < 0)
				ran.move = Up;
			else
				ran.move = Down;
	}

	else
	{
		if (ran.move != Right)
			ran.move = Left;
		else
			if (ran.hinhdang[0].y - ran.hinhdang[ran.len - 1].y < 0)
				ran.move = Up;
			else
				ran.move = Down;
	}
}

//	Tự tìm đến hàng chứa thức ăn

void timHang(snake& ran, food thucAn)
{
	if (thucAn.toado.y - ran.hinhdang[0].y > 0)
	{
		if (ran.move != Up)
			ran.move = Down;
		else
		{
			if (ran.hinhdang[0].x - ran.hinhdang[ran.len - 1].x < 0)
				ran.move = Left;
			else
				ran.move = Right;
		}

	}
	else
	{
		if (ran.move != Down)
			ran.move = Up;
		else
		{
			if (ran.hinhdang[0].x - ran.hinhdang[ran.len - 1].x < 0)
				ran.move = Left;
			else
				ran.move = Right;
		}
	}

}

//Tự động điều khiển

void autoControlSnake(snake& ran, food thucAn)
{

	//thay đổi các vị trí thân con rắn

	for (int i = ran.len - 1; i > 0; --i)
	{
		ran.hinhdang[i].x = ran.hinhdang[i - 1].x;
		ran.hinhdang[i].y = ran.hinhdang[i - 1].y;
	}

	timCot(ran, thucAn);

	if (ran.hinhdang[0].x == thucAn.toado.x)
		timHang(ran, thucAn);

	if (ran.move == Left)
		--ran.hinhdang[0].x;
	else if (ran.move == Right)
		++ran.hinhdang[0].x;
	else if (ran.move == Up)
		--ran.hinhdang[0].y;
	else if (ran.move == Down)
		++ran.hinhdang[0].y;

}

//Hướng dẫn bằng autoBot

void main_Game_2(snake& Snake, food& thucAn)
{
	Snake.name = "Auto Snake Cute";

	//Chọn tốc độ bắt đầu game.

	do
	{
		gotoXY(xConsole / 2 - 20, yConsole / 2 - 2);
		cout << "chon toc do bat dau (>0) (cang nho cang nhanh 50->500): ";
		cin >> Snake.tocDo;

		if (Snake.tocDo <= 0)
		{
			clrscr();
			gotoXY(xConsole / 2 - 5, yConsole / 2 - 2);
			cout << "Nhap lai: ";
		}

	} while (Snake.tocDo <= 0);

	int tocDo = Snake.tocDo;

	clrscr();

	vatCan vatcan;

	khoiTao(Snake, thucAn, vatcan, Snake.tocDo);

	toaDo cuoi, keCuoi;

	//Chạy game

	veManHinh();

	while (Snake.level == 1)
	{
		//Hiển thị con rắn
		hienThi(Snake, thucAn, cuoi, keCuoi);

		//Điều khiển con rắn

		autoControlSnake(Snake, thucAn);

		//Thao tac game
		thaoTac(Snake, thucAn, vatcan);

		//Game Over
		gameOver(Snake, vatcan);

		if (Snake.mangSong == 0)
		{
			clrscr();
			gotoXY((xConsole) / 2 + 3, yConsole / 2);
			cout << left << setw(10) << "GAME OVER :\"<.";
			gotoXY((xConsole - 17) / 2 - 4, yConsole / 2 + 2);
			cout << left << setw(15) << "Nhan Enter de thoat. Nhan Space de quay lai Menu.";
			char key;
			do
			{
				key = _getch();
				if (key == 13)
					return;
				if (key == 32)
				{
					clrscr();
					menu(Snake, thucAn);
				}
			} while (key != 13 || key != 32);
		}

		//Nhịp Game
		Sleep(Snake.tocDo);

		//xóa 2 vị trí đã lưu ở trên

		gotoXY(keCuoi.x, keCuoi.y);
		cout << " ";
		gotoXY(cuoi.x, cuoi.y);
		cout << " ";
	}

	int tamDiem = Snake.point; //lưu điểm

	//tăng level 2

	gotoXY(xConsole / 2 - 2, yConsole / 2);
	cout << "LEVEL UP";

	khoiTao(Snake, thucAn, vatcan, tocDo);
	Snake.level = 2;
	Snake.point = tamDiem;

	//Dừng màn hình lại xem

	Sleep(1000);

	clrscr();

	veManHinh();

	veVatCan(Snake, vatcan);

	while (Snake.level == 2)
	{
		//Hiển thị con rắn
		hienThi(Snake, thucAn, cuoi, keCuoi);

		//Điều khiển con rắn

		autoControlSnake(Snake, thucAn);

		//Thao tac game
		thaoTac(Snake, thucAn, vatcan);

		//Game Over
		gameOver(Snake, vatcan);

		if (Snake.mangSong == 0)
		{
			clrscr();
			gotoXY((xConsole) / 2 + 3, yConsole / 2);
			cout << left << setw(10) << "GAME OVER :\"<.";
			gotoXY((xConsole - 17) / 2 - 4, yConsole / 2 + 2);
			cout << left << setw(15) << "Nhan Enter de thoat. Nhan Space de quay lai Menu.";
			char key;
			do
			{
				key = _getch();
				if (key == 13)
					return;
				if (key == 32)
				{
					clrscr();
					menu(Snake, thucAn);
				}
			} while (key != 13 || key != 32);
		}

		//Nhịp Game
		Sleep(Snake.tocDo);

		//xóa 2 vị trí đã lưu ở trên

		gotoXY(keCuoi.x, keCuoi.y);
		cout << " ";
		gotoXY(cuoi.x, cuoi.y);
		cout << " ";
	}

	tamDiem = Snake.point;

	//tăng level 3

	gotoXY(xConsole / 2 - 2, yConsole / 2);
	cout << "LEVEL UP";

	khoiTao(Snake, thucAn, vatcan, tocDo);
	Snake.level = 3;
	Snake.point = tamDiem;

	//Dừng màn hình lại xem
	Sleep(1000);

	clrscr();

	veManHinh();

	veVatCan(Snake, vatcan);

	while (1)
	{
		//Hiển thị con rắn
		hienThi(Snake, thucAn, cuoi, keCuoi);

		//Điều khiển con rắn

		autoControlSnake(Snake, thucAn);

		//Thao tac game
		thaoTac(Snake, thucAn, vatcan);

		//Game Over
		gameOver(Snake, vatcan);

		if (Snake.mangSong == 0)
		{
			clrscr();
			gotoXY((xConsole) / 2 + 3, yConsole / 2);
			cout << left << setw(10) << "GAME OVER :\"<.";
			gotoXY((xConsole - 17) / 2 - 4, yConsole / 2 + 2);
			cout << left << setw(15) << "Nhan Enter de thoat. Nhan Space de quay lai Menu.";
			char key;
			do
			{
				key = _getch();
				if (key == 13)
					return;
				if (key == 32)
				{
					clrscr();
					menu(Snake, thucAn);
				}
			} while (key != 13 || key != 32);
		}


		//Nhịp Game
		Sleep(Snake.tocDo);

		//xóa 2 vị trí đã lưu ở trên

		gotoXY(keCuoi.x, keCuoi.y);
		cout << " ";
		gotoXY(cuoi.x, cuoi.y);
		cout << " ";

		//Chien thang
		if (Snake.point >= 4000)
		{
			clrscr();
			gotoXY((xConsole) / 2 - 1, yConsole / 2);
			cout << left << setw(10) << "YOU WIN :\">. " << Snake.name << " Vo dich :\")";
			gotoXY((xConsole - 17) / 2 - 4, yConsole / 2 + 2);
			cout << left << setw(15) << "Nhan Enter de thoat. Nhan Space de quay lai menu.";
			char key;
			do
			{
				key = _getch();
				if (key == 13)
					return;
				if (key == 32)
				{
					clrscr();
					menu(Snake, thucAn);
				}
			} while (key != 13);
		}
	}

}

void huongDan()
{
	clrscr();

	srand((unsigned)time(NULL));

	gotoXY(80 / 2 - 30, 25 / 2 - 9);
	TextColor(rand() % 14 + 1);
	cout << "=====================HUONG DAN=====================" << endl;

	gotoXY(80 / 2 - 20, 25 / 2 - 7);
	TextColor(rand() % 14 + 1);
	cout << "1) Nhan phim W (UP) de di chuyen len." << endl;

	gotoXY(80 / 2 - 20, 25 / 2 - 5);
	TextColor(rand() % 14 + 1);
	cout << "2) Nhan phim S (DOWN) de di chuyen xuong." << endl;

	gotoXY(80 / 2 - 20, 25 / 2 - 3);
	TextColor(rand() % 14 + 1);
	cout << "3) Nhan phim A (LEFT) de di chuyen sang trai." << endl;

	gotoXY(80 / 2 - 20, 25 / 2 - 1);
	TextColor(rand() % 14 + 1);
	cout << "4) Nhan phim D (RIGHT) de di chuyen sang phai." << endl;

	gotoXY(80 / 2 - 20, 25 / 2 + 1);
	TextColor(rand() % 14 + 1);
	cout << "5) Nhan phim Space de tam dung game." << endl;

	gotoXY(80 / 2 - 20, 25 / 2 + 3);
	TextColor(rand() % 14 + 1);
	cout << "6) Nhan phim Q de tang mang song." << endl;

	gotoXY(80 / 2 - 20, 25 / 2 + 5);
	TextColor(rand() % 14 + 1);
	cout << "7) Nhan phim Tab de xem huong dan khi choi game." << endl;

	gotoXY(80 / 2 - 20, 25 / 2 + 7);
	TextColor(rand() % 14 + 1);
	cout << "8) Nhan phim E de mo nhac, Z de tat nhac." << endl;

	gotoXY(80 / 2 - 30, 25 / 2 + 9);
	cout << "=====================================================" << endl;
}