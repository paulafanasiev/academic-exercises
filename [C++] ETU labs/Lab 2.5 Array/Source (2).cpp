#include <iostream>
#include <limits>
using namespace std;

void printm(float** f, int n)
{
	cout << "Массив:\n";
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

	//Ввод размера массива
	cout << "Введите размер массива: ";
	cin >> n;
	//Проверка корректности ввода размера массива
	while (!cin.good()||n<1)
	{
		cout<< "Значение введено неверно. Повторите ввод" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> n;
	}
	cout << "Заданная размерность " <<n<<" x "<<n<<endl;
	
	// объявление двумерного динамического массива:
	f = new float* [n]; // строки в массиве
	for (i = 0; i < n; i++)
		f[i] = new float[n]; // и столбцы

	//Ввод элементов массива
	cout << "Введите элементы массива:\n";
	for (i = 0; i < n; i++)
	{
		for (k = 0; k < n; k++)
		{
			cout << "["<<i<<"]["<<k<<"] = ";
			cin >> f[i][k];
			// Проверка корректности ввода элемента массива (i,k)
			while (!cin.good())
			{
				cout << "Значение введено неверно. Повторите ввод" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> f[i][k];
			}
		}
	}

	//Вывод введённого массива на экран
	printm(f, n);

	//Ввод инкремента
	cout << "Программа суммирует диагональные элементы массива с числом, введите это число:";
	cin >> sum;
	//Проверка корректности ввода инкремента
	while (!cin.good())
	{
		cout << "Значение введено неверно. Повторите ввод" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> sum;
	}
	//Суммирование диагональных элементов с инкрементом
	for (i = 0; i < n; i++)
		f[i][i] += sum;

	//Вывод массива
	cout << "Результат:" << endl;
	printm(f, n);
	system("pause");
}