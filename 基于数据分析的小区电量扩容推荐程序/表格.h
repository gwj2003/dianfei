#include<stdio.h>
#include<windows.h>
void  gotoxy(int x, int y)   //��궨λ����
{
	HANDLE hOut;
	COORD pos = { x,y };
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);

}