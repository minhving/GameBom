#include "GameBomb.h"
void NewGame(int**& boardgame)
{
	srand(time(NULL));
	int choice,row,collum,mines;
	while (true)
	{
		system("cls");
		cout << "----------------------" << endl;
		cout << "1.EASY" << endl;
		cout << "2.MEDIUM" << endl;
		cout << "3.HARD" << endl;
		cout << "4.CUSTOM" << endl;
		cout << "5.RETURN MENU" << endl;
		cout << "----------------------" << endl;
		cout << "INPUT YOUR CHOICE = "; cin >> choice;
		if (choice == 1)
		{
			row = 9, collum = 9,mines = 10;
			CreatGame(boardgame, row, collum, mines);
			system("pause");
		}
		else if (choice == 2)
		{
			row = 16, collum = 16,mines = 40;
			CreatGame(boardgame, row, collum, mines);
			system("pause");
		}
		else if (choice == 3)
		{
			row = 30, collum = 16, mines = 99;
			CreatGame(boardgame, row, collum, mines);
			system("pause");
			
		}
		else if (choice == 4)
		{
			
			cout << "Please input row = "; cin >> row;
			cout << "Please input collum = "; cin >> collum;
			cout << "Please input the number of mines = "; cin >> mines;
			CreatGame(boardgame, row, collum, mines);
			system("pause");

		}
		else if (choice == 5)
		{
			Menu(boardgame);
			break;
			system("pause");
		}
		else
		{
			cout << "HEN GAP LAI BAN" << endl;
			system("pause");
			break;
		}
		

	}

}