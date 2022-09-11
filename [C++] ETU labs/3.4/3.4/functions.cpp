#include "Header.h"

list* init(string FIO, string spec, workday* work) // �- �������� ������� ����
{
	list* lst;
	// ��������� ������ ��� ������ ������
	lst = new list;
	lst->FIO = FIO;
	lst->work = work;
	lst->spec = spec;
	lst->ptr = NULL; // ��� ��������� ���� ������
	return lst;
}

void add_new_item(list* lst, string FIO, string spec, workday* work)
{
	list* temp, * p;
	temp = new list;
	p = lst->ptr; // ���������� ��������� �� ��������� ����
	lst->ptr = temp; // ���������� ���� ��������� �� �����������
	temp->FIO = FIO;
	temp->work = work;
	temp->spec = spec;
	temp->ptr = p; // ��������� ���� ��������� �� ��������� �������
}

void delete_item(list* lst, list** root)
{
	list* temp;
	if (lst != NULL) {
		if (lst != *root)
		{
			temp = *root;
			while (temp->ptr != lst) // ������������� ������ ������� � �����
			{ // ���� �� ������ ����, �������������� lst
				temp = temp->ptr;
			}
			temp->ptr = lst->ptr; // ������������ ���������
		}
		else
		{
			*root = lst->ptr;
		}
		delete lst; // ����������� ������ ���������� ����
	}
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
			cout << "� ���� ������ " << i << " ";
			if (p->work[i].workday)
				cout << "������� ���� �� " << p->work[i].start_time << " �� " << p->work[i].end_time << endl;
			else
				cout << "��������" << endl;
		}

		p = p->ptr; // ������� � ���������� ����
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void onelistprint(list* lst)
{
	list* p;
	p = lst;
	if (p != NULL)
	{
		cout << p->FIO << " " << p->spec << endl;
		for (int i = 0; i < 7; i++)
		{
			cout << "� ���� ������ " << i << " ";
			if (p->work[i].workday)
				cout << "������� ���� �� " << p->work[i].start_time << " �� " << p->work[i].end_time << endl;
			else
				cout << "��������" << endl;
		}
	}
	else
		cout << "NULL" << endl;
}
list* find(list* lst, string FIOfind)
{
	list* p;
	p = lst;
	while (p != NULL)
	{
		if (p->FIO == FIOfind)
			return p;
		p = p->ptr; // ������� � ���������� ����
	}
	return NULL;
}
void findname(list *lst)
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string FIOfind;
	cout << "����� ��� ����:";
	getline(cin, FIOfind);
	onelistprint(find(lst, FIOfind));
}
void sortbyname(list** root)
{
	list *newone=NULL;
	
	list *p, *minimum;
	while (*root != NULL) 
	{
		p = *root;
		minimum = p;
		while (p != NULL)
		{
			if (p->FIO < minimum->FIO)
				minimum = p;
			p = p->ptr; // ������� � ���������� ����
		}

		if (newone == NULL)
			newone = init(minimum->FIO, minimum->spec, minimum->work);
		else
		{
			p = newone;
			while (p->ptr != NULL)
			{
				p = p->ptr; // ������� � ���������� ����
			}
			add_new_item(p, minimum->FIO, minimum->spec, minimum->work);
		}
		delete_item(minimum, root);
	}
	*root = newone;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void deletename(list** lst)
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string FIOfind;
	cout << "����� ��� ����:";
	getline(cin, FIOfind);
	delete_item(find(*lst, FIOfind), lst);
}
void editname(list* lst)
{
	list* edit = NULL;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string FIOfind;
	cout << "����� ��� ����:";
	getline(cin, FIOfind);
	edit=find(lst, FIOfind);
	if (edit != NULL)
	{
		onelistprint(edit);
		cout << endl << "����� ��� �����:";
		getline(cin, edit->FIO);
		cout << endl << "����� �������������:";
		getline(cin, edit->spec);
		for (int i = 0; i < 7; i++)
		{
			cout << "�� ������� �������� �������� ���� � " << i << "-� ���� ������? ('-1' - ���� ��������):" << endl;
			cin >> edit->work[i].start_time;
			if (edit->work[i].start_time == -1)
			{
				edit->work[i].workday = false;
			}
			else
			{
				edit->work[i].workday = true;
				cout << "�� ������� ����������� �������� ���� � " << i << "-� ���� ������?" << endl;
				cin >> edit->work[i].end_time;
			}
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}




void Get_new_item_from_keyboard(list** lst)
{
	string FIO, spec;
	workday* work;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl << "��� �����:";
	getline(cin, FIO);
	cout << endl << "�������������:";
	getline(cin, spec);
	work = new workday[7];
	for (int i = 0; i < 7; i++)
	{
		cout << "�� ������� �������� �������� ���� � " << i << "-� ���� ������? ('-1' - ���� ��������):" << endl;
		cin >> work[i].start_time;
		if (work[i].start_time == -1)
		{
			work[i].workday = false;
		}
		else
		{
			work[i].workday = true;
			cout << "�� ������� ����������� �������� ���� � " << i << "-� ���� ������?" << endl;
			cin >> work[i].end_time;
		}
	}
	if (*lst == NULL)
		*lst = init(FIO, spec, work);
	else
		add_new_item(*lst, FIO, spec, work);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void save(list* lst)
{
	string output_file_name;
	bool root = true;
	cout << "output filename:";
	cin >> output_file_name;

	ofstream out(output_file_name); //��������� ���� ��� ������
	if (!out) {
		cout << "Can't open file"; //���� ������ �������� �����, �� ��������� ���������
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

		p = p->ptr; // ������� � ���������� ����
	}
	out.close(); // ��������� ����
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void read(list** lst)
{
	string input_file_name, FIO, spec;
	workday* work;
	int starttime;
	int i = 0, k;
	cout << "input filename:";
	cin >> input_file_name;
	ifstream fs(input_file_name);

	if (!fs) {
		cout << "Can't open file"; //���� ������ �������� �����, �� ��������� }���������
		return;
	}

	while (fs.good())
	{
		if (getline(fs, FIO))
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
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	fs.close();
}