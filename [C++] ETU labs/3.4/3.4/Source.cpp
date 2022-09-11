#include "Header.h"

int main()
{
	list* root = NULL;
	char ch;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true)
	{
		cout << "1 - Добавить новый элемент с клавиатуры" << endl << "2 - Вывод на экран" << endl << "3 - загрузить из файла" << endl << "4 - сохранить в файл" << endl;
		cout << "5 - Удалить элемент по ФИО" << endl << "6 - Отредактировать элемент по ФИО" << endl << "7 - Найти врача по ФИО" << endl << "8 - Отсортировать врачей по ФИО" << endl;

		if (!cin.get(ch)) break;
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (ch)
		{
		case '1':
			Get_new_item_from_keyboard(&root);
			break;
		case '2':
			listprint(root);
			break;
		case '3':
			read(&root);
			break;
		case '4':
			save(root);
			break;
		case '5':
			deletename(&root);
			break;
		case '6':
			editname(root);
			break;
		case '7':
			findname(root);
			break;
		case '8':
			sortbyname(&root);
			break;
		}

	}


	return 0;
}