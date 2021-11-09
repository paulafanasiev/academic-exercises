#include "Header.h"
void SetColor(ConsoleColor Colorback, ConsoleColor Colortext)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((Colortext << 4) | Colorback));
}
void SetWindow(int x1, int y1, int x2, int y2)
{
	HWND hWindowConsole = GetConsoleWindow();
	MoveWindow(hWindowConsole, x1, y1, x2 - x1, y2 - y1, TRUE);
}