#include "GameBomb.h"



int main()
{
	int** boardgame = new int*[MAX_ROW];
	for (int i = 0; i < MAX_COLUMN; i++)
	{
		boardgame[i] = new int[MAX_COLUMN];
	}
	Menu(boardgame);
	system("pause");


	return 0;
}
