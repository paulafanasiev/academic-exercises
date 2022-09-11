#include "Header.h"


int main()
{
	char** file_data;
	string input_file_name = "", output_file_name = "";
	setlocale(LC_ALL, "Russian");
	file_data = read(&input_file_name);
	cout << "loaded from " << input_file_name << endl;
	cout << file_data[0] << endl;
	sort(file_data[0], file_data[1]);
	cout << "sorted:" << endl;
	cout << file_data[1] << endl;
	save(&output_file_name, file_data[0], file_data[1]);
	cout << "saved to " << output_file_name << endl;
	delete[] file_data[0];
	delete[] file_data[1];
	delete[] file_data;
	return 0;
}