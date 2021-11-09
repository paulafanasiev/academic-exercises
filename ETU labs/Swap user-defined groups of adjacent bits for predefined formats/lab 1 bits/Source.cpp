#include "Header.h"
int main(void)
{
	int tmp,bits,l1,l2;
	float datafloat=NULL;
	long datalong=NULL;
	string bin;
	
	while (true)
	{
		cout << "1 -> input number long\n2 -> input number float\n3 -> long to binary\n4 -> float to binary\n5 -> swap bits for long\n6 -> swap bits for float\n";
		cin >> tmp;
		switch (tmp)
		{
		case 1:
			cout << "your number:";
			cin >> datalong;
			break;
		case 2:
			cout << "your number:";
			cin >> datafloat;
			break;
		case 3:
			if (datalong != NULL) {
			ToBinary<long>(datalong, bin);
			cout <<"[long] " << datalong << "=[binary]" << bin<<endl;
			break;
		}
			else
			cout << "number = NULL\n";
			break;
		case 4:
			if (datafloat != NULL) {
				ToBinary<float>(datafloat, bin);
				cout <<"[float] " << datafloat << "=[binary]" << bin << endl;
			}
			else
				cout << "number = NULL\n";
			break;
		case 5:
			if (datalong != NULL) {
				cout << "input number of bit to swap:";
				cin >> bits;
				cout << "input number of the first group bits to swap:";
				cin >> l1;
				cout << "input number of the second group bits to swap:";
				cin >> l2;
				if ((l1 >= 0 && l1 <= 33 - bits) && (l2 >= 0 && l2 <= 33 - bits))
				{
					datalong = swap_bits<long>(datalong, bits, 33-l1, 33-l2);
					ToBinary<long>(datalong, bin);
					cout << "result: [long] " << datalong << "=[binary]" << bin << endl;
				}
				else
					cout << "invalid input\n";
				break;
			}
			else
				cout << "number = NULL\n";
			break;
		case 6:
			if (datafloat != NULL) {
				cout << "input number of bit to swap:";
				cin >> bits;
				cout << "input number of the first group bits to swap:";
				cin >> l1;
				cout << "input number of the second group bits to swap:";
				cin >> l2;
				if ((l1 >= 0 && l1 <= 33 - bits) && (l2 >= 0 && l2 <= 33 - bits))
				{
					datafloat = swap_bits<float>(datafloat, bits, 33 - l1, 33 - l2);
					ToBinary<float>(datafloat, bin);
					cout << "result: [float] " << datafloat << "=[binary]" << bin << endl;
				}
				else
					cout << "invalid input\n";
				break;
			}
			else
				cout << "number = NULL\n";
			break;
		default:
			cout << "invalid operation";
			break;
		}
	}
	return 0;
}