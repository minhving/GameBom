#pragma once
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <chrono>


using namespace std;
using namespace std::chrono;

typedef high_resolution_clock Clock;
typedef Clock::time_point ClockTime;

#define MAX_ROW 100
#define MAX_COLUMN 100

void NewGame(int**& boardgame);
void Menu(int**& boardgame);
void CreatGame(int**& boardgame, int row, int collum,int mines);
void CoutBoom(int**& boardgame,int**&boardgame1, int row, int collum, int mines);
void DrawBoardGame(int row, int collum, int mines);
void PlayGame(int**& boardgame, int**& boardgame1, bool** boardgame2, int row, int collum, int mines);
void timer();
void printExecutionTime(ClockTime start_time, ClockTime end_time);
void displayClock();