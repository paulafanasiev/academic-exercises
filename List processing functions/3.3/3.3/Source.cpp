#include "Header.h"

int main()
{
	listElem* root=NULL;
	char ch;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true)
	{
		cout << "1 - Добавить новый элемент с клавиатуры"<<endl << "2 - Вывод на экран" << endl << "3 - загрузить из файла" << endl <<"4 - сохранить в файл"<<endl;
		

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
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}


	return 0;
}