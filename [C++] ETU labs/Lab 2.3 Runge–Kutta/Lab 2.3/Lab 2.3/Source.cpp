#include <iostream>
using namespace std;

//расчёт одного члена ряда для проверки итеративной формулы
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
	
	//Ввод Х
	cout << "X:\n";
	cin >> x;
	//Проверка корректности ввода Х
	while (x>=1||x<=-1)
	{
		cout << "X should be betweeen (-1;1), X:\n";
		cin >> x;
	}

	//Ввод точности
	cout << "Eps:\n";
	cin >> eps;
	//Проверка корректности ввода точности
	while (eps <= 0)
	{
		cout << "Eps cannot be <=0, Eps:\n";
		cin >> eps;
	}

	//Расчёт количества знаков после запятой для вывода на экран на основе заданной точности вычислений
	cout.setf(ios::fixed);
	test = eps;
	for (i = 0; test < 1; i++)
		test *= 10;
	cout.precision(i + 1);


	//Задание первого члена ряда
	delta = x;

	//Инициализация суммы ряда по первому члену
	sum = delta;

	//Вычисление суммы ряда с требуемой точностью
	for (k = 2; k < 10000 && abs(delta) >= eps; k++)
	{
		//Итеративное вычисление k-го члена ряда
		delta *=-1*x*(k-1)/k;

		//Проверка итеративной формулы
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