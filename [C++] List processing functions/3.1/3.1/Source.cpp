#include "Header.h"


int main()
{
	char*** file_data, filtered, changed;
	string input_file_name = "", output_file_name = "";
	int inputsize = 0;
	//char input;
	setlocale(LC_ALL, "Russian");
	file_data = read(&input_file_name, &inputsize);
	cout << "loaded from " << input_file_name << endl;
	Print_all_data(file_data[0], inputsize);
	cout << "filtered char:";
	cin >> filtered;
	cout << "filtered char is changed to:";
	cin >> changed;
	change_filtered_item(file_data[0], file_data[1], inputsize, filtered, changed);
	Print_all_data(file_data[1], inputsize);
	save(&output_file_name, file_data[0], file_data[1], filtered, changed, inputsize);
	cout << "saved to " << output_file_name << endl;
	delete_all(file_data, inputsize);
	return 0;
}