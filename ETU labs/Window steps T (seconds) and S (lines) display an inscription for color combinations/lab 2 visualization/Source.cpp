#include "Header.h"
int main()
{
	string Colors[] = { "������",
		"�����",
		"�������",
		"����-�������",
		"�������",
		"������-�����",
		"����������",
		"������-�����",
		"�����-�����",
		"����-�����",
		"����-�������",
		"����� ����-�������",
		"����-�������",
		"����� ������-�����",
		"������",
		"�����" };
	SetWindow(10, 15, 700, 200);
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		for (int i = 0; i < 16; i++)
			for (int j = 0; j < 16; j++)
			{
				SetColor(ConsoleColor(i), ConsoleColor(j));
				cout << "\n\n\nBackground = "<< Colors[j]<<" text = "<< Colors[i];
				Sleep(700);
			}
	}

}