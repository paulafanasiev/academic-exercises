#include <iostream>
using namespace std;

//������ ������ ����� ���� ��� �������� ����������� �������
/*double ryad (int n, float x)
{
	double tmp;
	tmp = pow(x,n)/n;
	if (n % 2 == 0)
		return -1* tmp;
	else
		return 1 * tmp;
}*/

void main(void)
{
	double eps=0.1,x,sum,delta,test;
	int i, k;
	
	//���� �
	cout << "X:\n";
	cin >> x;
	//�������� ������������ ����� �
	while (x>=1||x<=-1)
	{
		cout << "X should be betweeen (-1;1), X:\n";
		cin >> x;
	}

	//���� ��������
	cout << "Eps:\n";
	cin >> eps;
	//�������� ������������ ����� ��������
	while (eps <= 0)
	{
		cout << "Eps cannot be <=0, Eps:\n";
		cin >> eps;
	}

	//������ ���������� ������ ����� ������� ��� ������ �� ����� �� ������ �������� �������� ����������
	cout.setf(ios::fixed);
	test = eps;
	for (i = 0; test < 1; i++)
		test *= 10;
	cout.precision(i + 1);


	//������� ������� ����� ����
	delta = x;

	//������������� ����� ���� �� ������� �����
	sum = delta;

	//���������� ����� ���� � ��������� ���������
	for (k = 2; k < 10000 && abs(delta) >= eps; k++)
	{
		//����������� ���������� k-�� ����� ����
		delta *=-1*x*(k-1)/k;

		//�������� ����������� �������
		/*
		cout << "iterativno= " << delta << "\n";
		cout << "   formula= " << ryad(k, x) << "\n";
		*/

		sum += delta;
	}

	test = log(1 + x);
	cout << "Znakov posle zapiatoi= " << i+1 << "\n";
	cout << "       kol-vo chlenov= " << k-1 << "\n";
	cout << "          summa ryada= " <<sum<<"\n";
	cout << "              ln(1+x)= " << test << "\n";
	cout << "              Res Eps= " << abs(test-sum) << "\n";
	cout << "       Trebuemaia Eps= " << eps << "\n";
	cout << "Poslednii chlen ryada= " << delta << "\n";
}