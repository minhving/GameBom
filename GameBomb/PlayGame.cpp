#include "GameBomb.h"
void XuatLoangRa(int** boardgame1,int row_selection,int collum_selection,int row,int collum,int **&boardgame3,bool **&boardgame4,bool **boardgame5)
{
	if (boardgame4[row_selection][collum_selection] == false && boardgame5[row_selection][collum_selection] == false)
	{
		boardgame5[row_selection][collum_selection] = true;
		boardgame4[row_selection][collum_selection] = true;
		if (boardgame1[row_selection][collum_selection] != 0)
		{
			boardgame3[row_selection][collum_selection] = boardgame1[row_selection][collum_selection];
		}
		else if (boardgame1[row_selection][collum_selection] == 0)
		{
			boardgame3[row_selection][collum_selection] = 0;
			for (int i = row_selection - 1; i <= row_selection + 1; i++)
			{
				for (int j = collum_selection - 1; j <= collum_selection + 1; j++)
				{
					if (i >= 0 && i <= row-1 && j >= 0 && j <= collum-1 && (i != row_selection || j != collum_selection))
					{
						XuatLoangRa(boardgame1, i, j, row, collum, boardgame3, boardgame4,boardgame5);
					}
				}
			}
		}
	}
	
}
void PlayGame(int**& boardgame, int**& boardgame1, bool** boardgame2, int row, int collum, int mines)
{
	int** boardgame3 = new int* [row]; // dung de nhap xuat
	for (int i = 0; i < row; i++)
	{
		boardgame3[i] = new int[collum];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < collum; j++)
		{
			boardgame3[i][j] = -1;
		}
	}

	bool** boardgame4 = new bool* [row]; //check mở hay chưa
	for (int i = 0; i < row; i++)
	{
		boardgame4[i] = new bool[collum];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < collum; j++)
		{
			boardgame4[i][j] = false;
		}
	}
	bool** boardgame5 = new bool* [row]; // check có cắm cờ hay chưa
	for (int i = 0; i < row; i++)
	{
		boardgame5[i] = new bool[collum];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < collum; j++)
		{
			boardgame5[i][j] = false;
		}
	}

	int row_selection, collum_selection;
	ClockTime start_time = Clock::now();
	while (true)
	{
		cout << "Total mines = " << mines << endl;
		char* choice = new char[2];

		cout << "Input row selection = "; cin >> row_selection;
		cout << "Input collum selection = "; cin >> collum_selection;
		
		cin.ignore(1000, '\n');
		row_selection -= 1;
		collum_selection -= 1;
		cout << "------------------------------" << endl;
		cout << "Press O to open " << endl;
		cout << "Press P to pin the boom " << endl;
		cout << "Input your choice = "; 
		cin.getline(choice, 2, '\n');
		cout << choice << endl;
		
		
		if (choice[0] == 'o')
		{
			if (boardgame2[row_selection][collum_selection] == true)
			{
				ClockTime end_time = Clock::now();
				
				for (int i = 0; i < row; i++)
				{
					for (int j = 0; j < collum; j++)
					{
						if (boardgame3[i][j] == -2 && boardgame2[i][j] == true)
						{
							cout << "|" << "\t";
						}
						else if (boardgame3[i][j] == -2 && boardgame2[i][j] == false)
						{
							cout << "_" << "\t";
						}
						else
						{
							cout << boardgame[i][j] << "\t";
						}
					}
					cout << endl;
				}
				cout << "------------------------------" << endl;
				cout << "You lose " << endl;
				printExecutionTime(start_time, end_time);
				break;
			}
			else if (boardgame2[row_selection][collum_selection] == false)
			{
				
				XuatLoangRa(boardgame1, row_selection, collum_selection, row, collum, boardgame3, boardgame4, boardgame5);
			}
			
			
		}
		else if (choice[0] == 'p')
		{
			
			if (boardgame5[row_selection][collum_selection] == false && boardgame4[row_selection][collum_selection] == false)
			{
				mines -= 1;
				boardgame5[row_selection][collum_selection] = true;
				boardgame3[row_selection][collum_selection] = -2;
			}
			else if(boardgame5[row_selection][collum_selection] == true && boardgame4[row_selection][collum_selection] == false)
			{
				mines += 1;
				boardgame5[row_selection][collum_selection] = false;
				boardgame3[row_selection][collum_selection] = -1;
			}
			
			
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < collum; j++)
			{
				if (boardgame3[i][j] == -1)
				{
					cout << "*" << "\t";
				}
				else if (boardgame3[i][j] == -2)
				{
					cout << "P" << "\t";
				}
				else if (boardgame3[i][j] != 0)
				{
					cout << boardgame3[i][j] << "\t";
				}
				else if (boardgame3[i][j] == 0)
				{

					cout << boardgame3[i][j] << "\t";
				}
			}
			cout << endl;
		}
		bool flag = true;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < collum; j++)
			{
				if (boardgame3[i][j] == -1)
				{
					flag = false;
				}
			}
		}
		if (flag == true)
		{
			ClockTime end_time = Clock::now();
			
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < collum; j++)
				{
					if (boardgame5[i][j] == true && boardgame2[i][i] == true)
					{
						cout << "P(d)" << "\t";
					}
					else
					{
						cout << boardgame[i][j] << "\t";
					}
					
				}
				cout << endl;
			}
			cout << "------------------------------" << endl;
			cout << "CONGRATULATION" << endl;
			printExecutionTime(start_time, end_time);
			break;
		}
	
	}
}
