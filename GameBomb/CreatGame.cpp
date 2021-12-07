#include "GameBomb.h"
void CreatGame(int**& boardgame, int row, int collum,int mines)
{
	srand(time(NULL));
	int row_selection, collum_selection,count=0;
	
	int i, j;

	int** boardgame1 = new int* [row];
	for (int i = 0; i < row; i++)
	{
		boardgame1[i] = new int[collum];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < collum; j++)
		{
			boardgame1[i][j] = 0;
		}
	}
	bool** boardgame2 = new bool* [row]; // xac dinh co bom hay khong
	for (int i = 0; i < row; i++)
	{
		boardgame2[i] = new bool[collum];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < collum; j++)
		{
			boardgame2[i][j] = false;
			boardgame[i][j] = 0;
		}
	}
	while (count < mines)
	{
		i = rand() % row;
		j = rand() % collum;
		if (boardgame[i][j] == 1)
		{
			continue;
		}
		boardgame[i][j] = 1;
		boardgame2[i][j] = true;
		count++;
	}
	
	
	
	
	CoutBoom(boardgame,boardgame1, row, collum,mines);
	//timer();
	PlayGame(boardgame, boardgame1, boardgame2, row, collum, mines);

}