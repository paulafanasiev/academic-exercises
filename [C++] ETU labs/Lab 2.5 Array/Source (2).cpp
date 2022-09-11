#include <iostream>
#include <limits>
using namespace std;

void printm(float** f, int n)
{
	cout << "������:\n";
	for (int i = 0; i < n; i++)
	{
		cout << "| ";
		for (int k = 0; k < n; k++)
		{
			cout << f[i][k]<< " | ";
		}
		cout << endl;
	}
}


void main(void)
{
	int n,i,k,sum;
	float** f;
	setlocale(LC_ALL, "Russian");

	//���� ������� �������
	cout << "������� ������ �������: ";
	cin >> n;
	//�������� ������������ ����� ������� �������
	while (!cin.good()||n<1)
	{
		cout<< "�������� ������� �������. ��������� ����" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> n;
	}
	cout << "�������� ����������� " <<n<<" x "<<n<<endl;
	
	// ���������� ���������� ������������� �������:
	f = new float* [n]; // ������ � �������
	for (i = 0; i < n; i++)
		f[i] = new float[n]; // � �������

	//���� ��������� �������
	cout << "������� �������� �������:\n";
	for (i = 0; i < n; i++)
	{
		for (k = 0; k < n; k++)
		{
			cout << "["<<i<<"]["<<k<<"] = ";
			cin >> f[i][k];
			// �������� ������������ ����� �������� ������� (i,k)
			while (!cin.good())
			{
				cout << "�������� ������� �������. ��������� ����" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> f[i][k];
			}
		}
	}

	//����� ��������� ������� �� �����
	printm(f, n);

	//���� ����������
	cout << "��������� ��������� ������������ �������� ������� � ������, ������� ��� �����:";
	cin >> sum;
	//�������� ������������ ����� ����������
	while (!cin.good())
	{
		cout << "�������� ������� �������. ��������� ����" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> sum;
	}
	//������������ ������������ ��������� � �����������
	for (i = 0; i < n; i++)
		f[i][i] += sum;

	//����� �������
	cout << "���������:" << endl;
	printm(f, n);
	system("pause");
}