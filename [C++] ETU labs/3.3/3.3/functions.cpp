#include "Header.h"

list* init(string FIO, string spec, workday* work) // а- значение первого узла
{
	list* lst;
	// выделение памяти под корень списка
	lst = new list;
	lst->FIO = FIO;
	lst->work = work;
	lst->spec = spec;
	lst->ptr = NULL; // это последний узел списка
	return lst;
}

void add_new_item(list* lst, string FIO, string spec, workday* work)
{
	list *temp,*p;
	temp = new list;
	p = lst->ptr; // сохранение указателя на следующий узел
	lst->ptr = temp; // предыдущий узел указывает на создаваемый
	temp->FIO = FIO;
	temp->work = work;
	temp->spec = spec;
	temp->ptr = p; // созданный узел указывает на следующий элемент
}

list* delete_item(list* lst, list* root)
{
	list* temp;
	if (lst != root)
	{
		temp = root;
		while (temp->ptr != lst) // просматриваем список начиная с корня
		{ // пока не найдем узел, предшествующий lst
			temp = temp->ptr;
		}
		temp->ptr = lst->ptr; // переставляем указатель
	}
	else
	{
		temp = root->ptr;
		root = root->ptr;
	}
		delete lst; // освобождаем память удаляемого узла
	
	return temp;
}

void listprint(list* lst)
{
	list* p;
	p = lst;
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
}



void Get_new_item_from_keyboard(list** lst)
{
	string FIO, spec;
	workday *work;
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
	if (*lst == NULL)
	    *lst=init(FIO, spec, work);
	else
		add_new_item(*lst, FIO, spec, work);

}

void save(list* lst)
{
	string output_file_name;
	bool root = true;
	cout << "output filename:";
	cin >> output_file_name;

	ofstream out(output_file_name); //Открываем файл для записи
	if (!out) {
		cout << "Can't open file"; //Если ошибка открытия файла, то завершаем программу
		return;
	}

	list* p;
	p = lst;
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
}

void read(list** lst)
{
	string input_file_name,FIO,spec;
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
		if(getline(fs, FIO))
			if (getline(fs, spec))
			{
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
				if (*lst == NULL)
					*lst = init(FIO, spec, work);
				else
					add_new_item(*lst, FIO, spec, work);
			}
		getline(fs, input_file_name);
	}
	fs.close();
}