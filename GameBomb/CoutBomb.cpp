#include "GameBomb.h"
void CoutBoom(int**& boardgame,int **&boardgame1, int row, int collum, int mines)
{
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < collum; j++)
		{
			for (int k = i - 1; k <= i + 1; k++)
			{
				for (int f = j - 1; f <= j + 1; f++)
				{
					if (k >= 0 && f >= 0)
					{
						if (boardgame[k][f] == 1)
						{
							boardgame1[i][j] += 1;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < collum; j++)
		{
			cout << boardgame[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "--------------------" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < collum; j++)
		{
			cout << boardgame1[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "--------------------" << endl;
	//DrawBoardGame(row, collum, mines);
}