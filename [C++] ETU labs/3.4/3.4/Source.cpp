#include "Header.h"

int main()
{
	list* root = NULL;
	char ch;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true)
	{
		cout << "1 - �������� ����� ������� � ����������" << endl << "2 - ����� �� �����" << endl << "3 - ��������� �� �����" << endl << "4 - ��������� � ����" << endl;
		cout << "5 - ������� ������� �� ���" << endl << "6 - ��������������� ������� �� ���" << endl << "7 - ����� ����� �� ���" << endl << "8 - ������������� ������ �� ���" << endl;

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