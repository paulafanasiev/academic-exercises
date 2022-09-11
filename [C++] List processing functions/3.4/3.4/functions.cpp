#include "Header.h"

listElem* init(string FIO, string spec, workday* work) // а- значение первого узла
{
	listElem* root;
	// выделение памяти под корень списка
	root = new listElem;
	root->FIO = FIO;
	root->work = work;
	root->spec = spec;
	root->ptr = NULL; // это последний узел списка
	return root;
}

void add_new_item(listElem* root, string FIO, string spec, workday* work)
{
	listElem *temp,*p;
	temp = new listElem;
	while (root->ptr != NULL) // проматываем список до конца
	{ 
		root = root->ptr;
	}
	p = root->ptr;// сохранение указателя на следующий узел
	root->ptr = temp; // предыдущий узел указывает на создаваемый
	temp->FIO = FIO;
	temp->work = work;
	temp->spec = spec;
	temp->ptr = p; // созданный узел указывает на следующий элемент
}

void delete_item(listElem* elem, listElem** root)
{
	listElem* temp;
	if (elem != NULL) {
		if (elem != *root)
		{
			temp = *root;
			while (temp->ptr != elem) // просматриваем список начиная с корня
			{ // пока не найдем узел, предшествующий lst
				temp = temp->ptr;
			}
			temp->ptr = elem->ptr; // переставляем указатель
		}
		else
		{
			*root = elem->ptr;
		}
		delete elem; // освобождаем память удаляемого узла
	}
}

void listprint(listElem* root)
{
	listElem* p;
	p = root;
	while (p != NULL)
	{

		cout << p->FIO << " " << p->spec << endl;
		for (int i = 0; i < 7; i++)
		{
			cout << "В день недели " << i << " ";
			if (p->work[i].workday)
				cout << "рабочий день от " << p->work[i].start_time << " до " << p->work[i].end_time << endl;
			else
				cout << "выходной" << endl;
		}

		p = p->ptr; // переход к следующему узлу
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void OnlyOneElementPrint(listElem* elem)
{
	listElem* p;
	p = elem;
	if (p != NULL)
	{
		cout << p->FIO << " " << p->spec << endl;
		for (int i = 0; i < 7; i++)
		{
			cout << "В день недели " << i << " ";
			if (p->work[i].workday)
				cout << "рабочий день от " << p->work[i].start_time << " до " << p->work[i].end_time << endl;
			else
				cout << "выходной" << endl;
		}
	}
	else
		cout << "NULL" << endl;
}
listElem* find(listElem* root, string FIOfind)
{
	listElem* p;
	p = root;
	while (p != NULL)
	{
		if (p->FIO == FIOfind)
			return p;
		p = p->ptr; // переход к следующему узлу
	}
	return NULL;
}
void findname(listElem *root)
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string FIOfind;
	cout << "Какое ФИО ищем:";
	getline(cin, FIOfind);
	OnlyOneElementPrint(find(root, FIOfind));
}
void sortbyname(listElem** root)
{
	listElem *NewList=NULL;
	
	listElem *p, *minimum;
	while (*root != NULL) 
	{
		p = *root;
		minimum = p;
		while (p != NULL)
		{
			if (p->FIO < minimum->FIO)
				minimum = p;
			p = p->ptr; // переход к следующему узлу
		}

		if (NewList == NULL)
			NewList = init(minimum->FIO, minimum->spec, minimum->work);
		else
		{
			p = NewList;
			while (p->ptr != NULL)
			{
				p = p->ptr; // переход к следующему узлу
			}
			add_new_item(p, minimum->FIO, minimum->spec, minimum->work);
		}
		delete_item(minimum, root);
	}
	*root = NewList;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void deletename(listElem** root)
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string FIOfind;
	cout << "Какое ФИО ищем:";
	getline(cin, FIOfind);
	delete_item(find(*root, FIOfind), root);
}
void editname(listElem* root)
{
	listElem* edit = NULL;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string FIOfind;
	cout << "Какое ФИО ищем:";
	getline(cin, FIOfind);
	edit=find(root, FIOfind);
	if (edit != NULL)
	{
		OnlyOneElementPrint(edit);
		cout << endl << "Новое ФИО врача:";
		getline(cin, edit->FIO);
		cout << endl << "Новая специальность:";
		getline(cin, edit->spec);
		for (int i = 0; i < 7; i++)
		{
			cout << "Во сколько начинает работать врач в " << i << "-й день недели? ('-1' - если выходной):" << endl;
			cin >> edit->work[i].start_time;
			if (edit->work[i].start_time == -1)
			{
				edit->work[i].workday = false;
			}
			else
			{
				edit->work[i].workday = true;
				cout << "Во сколько заканчивает работать врач в " << i << "-й день недели?" << endl;
				cin >> edit->work[i].end_time;
			}
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}




void Get_new_item_from_keyboard(listElem** root)
{
	string FIO, spec;
	workday* work;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl << "ФИО врача:";
	getline(cin, FIO);
	cout << endl << "Специальность:";
	getline(cin, spec);
	work = new workday[7];
	for (int i = 0; i < 7; i++)
	{
		cout << "Во сколько начинает работать врач в " << i << "-й день недели? ('-1' - если выходной):" << endl;
		cin >> work[i].start_time;
		if (work[i].start_time == -1)
		{
			work[i].workday = false;
		}
		else
		{
			work[i].workday = true;
			cout << "Во сколько заканчивает работать врач в " << i << "-й день недели?" << endl;
			cin >> work[i].end_time;
		}
	}
	if (*root == NULL)
		*root = init(FIO, spec, work);
	else
		add_new_item(*root, FIO, spec, work);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void save(listElem* root)
{
	string output_file_name;
	cout << "output filename:";
	cin >> output_file_name;

	ofstream out(output_file_name); //Открываем файл для записи
	if (!out) {
		cout << "Can't open file"; //Если ошибка открытия файла, то завершаем программу
		return;
	}

	listElem* p;
	p = root;
	while (p != NULL)
	{
		out << p->FIO << endl << p->spec << endl;
		for (int i = 0; i < 7; i++)
		{
			if (p->work[i].workday)
				out << p->work[i].start_time << endl << p->work[i].end_time << endl;
			else
				out << "-1" << endl;

		}

		p = p->ptr; // переход к следующему узлу
	}
	out.close(); // Закрываем файл
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void read(listElem** root)
{
	string input_file_name, FIO, spec;
	workday* work;
	int starttime;
	int i = 0, k;
	cout << "input filename:";
	cin >> input_file_name;
	ifstream fs(input_file_name);

	if (!fs) {
		cout << "Can't open file"; //Если ошибка открытия файла, то завершаем }программу
		return;
	}

	while (fs.good())
	{
		if (getline(fs, FIO))
			{
				getline(fs, spec);
				work = new workday[7];
				for (i = 0; i < 7; i++)
				{
					fs >> work[i].start_time;
					if (work[i].start_time != -1)
					{
						work[i].workday = true;
						fs >> work[i].end_time;
					}
					else
					{
						work[i].workday = false;
					}
				}
				if (*root == NULL)
					*root = init(FIO, spec, work);
				else
					add_new_item(*root, FIO, spec, work);
			}
		getline(fs, input_file_name);
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	fs.close();
}