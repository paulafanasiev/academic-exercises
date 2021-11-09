#include "Header.h"

listElem* init(string FIO, string spec, workday* work) // �- �������� ������� ����
{
	listElem* elem;
	// ��������� ������ ��� ������ ������
	elem = new listElem;
	elem->FIO = FIO;
	elem->work = work;
	elem->spec = spec;
	elem->ptr = NULL; // ��� ��������� ���� ������
	return elem;
}

void add_new_item(listElem* root, string FIO, string spec, workday* work)
{
	listElem *temp,*p;
	temp = new listElem;
	while (root->ptr != NULL) // ����������� ������ �� �����
	{ 
		root = root->ptr;
	}
	p = root->ptr;// ���������� ��������� �� ��������� ����
	root->ptr = temp; // ���������� ���� ��������� �� �����������
	temp->FIO = FIO;
	temp->work = work;
	temp->spec = spec;
	temp->ptr = p; // ��������� ���� ��������� �� ��������� �������
}

listElem* delete_item(listElem* elem, listElem* root)
{
	listElem* temp;
	if (elem != root)
	{
		temp = root;
		while (temp->ptr != elem) // ������������� ������ ������� � �����
		{ // ���� �� ������ ����, �������������� lst
			temp = temp->ptr;
		}
		temp->ptr = elem->ptr; // ������������ ���������
	}
	else
	{
		temp = root->ptr;
		root = root->ptr;
	}
		delete elem; // ����������� ������ ���������� ����
	
	return temp;
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
			cout << "� ���� ������ " << i << " ";
			if (p->work[i].workday)
				cout << "������� ���� �� " << p->work[i].start_time << " �� " << p->work[i].end_time << endl;
			else
				cout << "��������" << endl;
		}

		p = p->ptr; // ������� � ���������� ����
	} 
}



void Get_new_item_from_keyboard(listElem** root)
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
	if (*root == NULL)
	    *root=init(FIO, spec, work);
	else
		add_new_item(*root, FIO, spec, work);

}

void save(listElem* root)
{
	string output_file_name;
	cout << "output filename:";
	cin >> output_file_name;

	ofstream out(output_file_name); //��������� ���� ��� ������
	if (!out) {
		cout << "Can't open file"; //���� ������ �������� �����, �� ��������� ���������
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

		p = p->ptr; // ������� � ���������� ����
	} 
	out.close(); // ��������� ����
}

void read(listElem** root)
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
				if (*root == NULL)
					*root = init(FIO, spec, work);
				else
					add_new_item(*root, FIO, spec, work);
			}
		getline(fs, input_file_name);
	}
	fs.close();
}