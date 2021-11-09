#include "Header.h"
int main()
{
	string Colors[] = { "черный",
		"синий",
		"зеленый",
		"сине-зеленый",
		"красный",
		"красно-синий",
		"коричневый",
		"светло-серый",
		"темно-серый",
		"€рко-синий",
		"€рко-зеленый",
		"€ркий сине-зеленый",
		"€рко-красный",
		"€ркий красно-синий",
		"желтый",
		"белый" };
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