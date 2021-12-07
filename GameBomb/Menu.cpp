#include "GameBomb.h"
void Menu(int**& boardgame)
{
	int choice;
	while (true)
	{
		system("cls");
		cout << "-------------MENU-----------" << endl;
		cout << "1.NEW GAME" << endl;
		cout << "2.RESUME" << endl;
		cout << "3.SCORE BOARD" << endl;
		cout << "4.EXIT" << endl;
		cout << "----------------------------" << endl;
		cout << "INPUT YOUR CHOICE = "; cin >> choice;
		if (choice == 1)
		{
			NewGame(boardgame);
		}
		else
		{
			cout << "HEN GAP LAI BAN" << endl;
			break;
			system("pause");
			
		}
	}
}