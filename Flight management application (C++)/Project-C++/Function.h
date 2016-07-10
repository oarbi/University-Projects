#pragma once
#include <Windows.h>
#include <time.h>
void gotoxy(int x, int y)
{
	COORD point;
	point.X = x; point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
void delay(int i)    /*Pause l'application pour i seconds*/
{
	clock_t start, end;
	start = clock();
	while (((end = clock()) - start) <= i*CLOCKS_PER_SEC); // while(((end=clock())-start)<=((i*CLOCKS_PER_SEC)/1000)); => ms
}
/*void gotox()
{
	COORD point;
	POINT p;
	GetCursorPos(&p);
	point.X = p.x + 5; point.Y = p.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}*/
/*void gotoxy(int x, int y)
{
COORD point;
point.X = x; point.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
void gotoxy(int x, int y)
{
static HANDLE h = NULL;
if (!h)
h = GetStdHandle(STD_OUTPUT_HANDLE);
COORD c = { x, y };
SetConsoleCursorPosition(h, c);
}
void gotoxy(int i, int j)
{
int o = 0, p = 0;
for (; p <= j; p++)
cout << "\n";
for (; o <= i; o++)
cout << " ";

}*/