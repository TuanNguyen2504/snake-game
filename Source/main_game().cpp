#include "snake-game.h"
//Hàm main().

int main()
{
	ShowConsoleCursor(false);
	food thucAn;
	snake Snake;

	
	gotoXY(10, 25 / 2 - 5);
	TextColor(rand() % 14 + 1);
	cout << "~~~~~~~~~~~~~~~~~~~~ GAME SNAKE :\"> ~~~~~~~~~~~~~~~~~~~~";

	//chèn nhạc nền

	PlaySound(TEXT("Game_Music"), NULL, SND_ASYNC);

	srand((unsigned)time(NULL));
	TextColor(rand() % 14 + 1);

	menu(Snake, thucAn);

	return 0;
}

