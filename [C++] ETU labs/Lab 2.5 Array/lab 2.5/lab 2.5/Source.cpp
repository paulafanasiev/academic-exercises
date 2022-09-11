#include <iostream>
#include <limits>
using namespace std;

void printm(float** f, int n)
{
	cout << "Massiv:\n";
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

	//Vvod razmera massiva
	cout << "Vvedite razmer massiva: ";
	cin >> n;
	//Proverka korrektnosti vvoda razmera massiva
	while (!cin.good()||n<1)
	{
		cout<< "Znachenie vvedeno neverno. Povtorite vvod" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> n;
	}
	cout << "Zadannaya razmernost' " <<n<<" x "<<n<<endl;
	
	// ob"yavlenie dvumernogo dinamicheskogo massiva:
	f = new float* [n]; // stroki v massive
	for (i = 0; i < n; i++)
		f[i] = new float[n]; // i stolbcy

	//Vvod elementov massiva
	cout << "Vvedite elementy massiva:\n";
	for (i = 0; i < n; i++)
	{
		for (k = 0; k < n; k++)
		{
			cout << "["<<i<<"]["<<k<<"] = ";
			cin >> f[i][k];
			// Proverka korrektnosti vvoda elementa massiva (i,k)
			while (!cin.good())
			{
				cout << "Znachenie vvedeno neverno. Povtorite vvod" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> f[i][k];
			}
		}
	}

	//Vyvod vvedyonnogo massiva na ekran
	printm(f, n);

	//Vvod inkrementa
	cout << "Programma summiruet diagonal'nye elementy massiva s chislom, vvedite eto chislo:";
	cin >> sum;
	//Proverka korrektnosti vvoda inkrementa
	while (!cin.good())
	{
		cout << "Znachenie vvedeno neverno. Povtorite vvod" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> sum;
	}
	//Summirovanie diagonal'nyh elementov s inkrementom
	for (i = 0; i < n; i++)
		f[i][i] += sum;

	//Vyvod massiva
	cout << "Rezul'tat:" << endl;
	printm(f, n);
	system("pause");
}