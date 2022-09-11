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
	list *temp,*p;
	temp = new list;
	p = lst->ptr; // ���������� ��������� �� ��������� ����
	lst->ptr = temp; // ���������� ���� ��������� �� �����������
	temp->FIO = FIO;
	temp->work = work;
	temp->spec = spec;
	temp->ptr = p; // ��������� ���� ��������� �� ��������� �������
}

list* delete_item(list* lst, list* root)
{
	list* temp;
	if (lst != root)
	{
		temp = root;
		while (temp->ptr != lst) // ������������� ������ ������� � �����
		{ // ���� �� ������ ����, �������������� lst
			temp = temp->ptr;
		}
		temp->ptr = lst->ptr; // ������������ ���������
	}
	else
	{
		temp = root->ptr;
		root = root->ptr;
	}
		delete lst; // ����������� ������ ���������� ����
	
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
			cout << "� ���� ������ " << i << " ";
			if (p->work[i].workday)
				cout << "������� ���� �� " << p->work[i].start_time << " �� " << p->work[i].end_time << endl;
			else
				cout << "��������" << endl;
		}

		p = p->ptr; // ������� � ���������� ����
	} 
}



void Get_new_item_from_keyboard(list** lst)
{
	string FIO, spec;
	workday *work;
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
		cout << "Can't open file"; //���� ������ �������� �����, �� ��������� }���������
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