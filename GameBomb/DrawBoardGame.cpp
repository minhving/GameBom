#include "DoHoa.h"
#include "GameBomb.h"

void DrawBoardGame(int row, int collum, int mines)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < collum; j++)
		{
			if ((i + j) % 2 == 0)
			{
				setColorBGTextXY(j * 2, i, 0, 8,(LPSTR) "  ");
			}
			else
			{
				setColorBGTextXY(j * 2, i, 0, 7,(LPSTR) "  ");
			}
		}
	}
}