#include "Header.h"
char** read(string* input_file_name)
{
	char** file_data;
	file_data = new char* [2];
	int i = 0, k;
	size_t length=0;
	char next;
	cout << "input filename:";
	cin >> *input_file_name;
	ifstream fs(*input_file_name);

	if (!fs) {
		cout << "Can't open file"; //Если ошибка открытия файла, то завершаем }программу
		return NULL;
	}


	while (fs.get() != EOF)
	{
		length = (size_t)fs.tellg();
	}
	fs.clear();
	fs.seekg(0);

	file_data[0] = new char[++length];
	file_data[1] = new char[length];
	fs.getline(file_data[0], length, EOF);

	fs.close();             //Закрываем файл
	return file_data;
}
void sort(char* input_file_data, char* output_file_data)
{
	int i, j, tmp_index;
	char tmp_char;
	for (i = 0; input_file_data[i] != 0; i++)
		output_file_data[i] = input_file_data[i];
	output_file_data[i] = 0;
	for (i = 0; output_file_data[i] != 0; i++)
	{
		tmp_index = i;
		for (j = i; output_file_data[j] != 0; j++)
			if (output_file_data[tmp_index] > output_file_data[j])
				tmp_index = j;

		tmp_char = output_file_data[tmp_index];
		output_file_data[tmp_index] = output_file_data[i];
		output_file_data[i] = tmp_char;

	}
}


void save(string* output_file_name, char* input_file_data, char* output_file_data)
{
	cout << "output filename:";
	cin >> *output_file_name;

	ofstream out(*output_file_name); //Открываем файл для записи
	if (!out) {
		cout << "Can't open file"; //Если ошибка открытия файла, то завершаем программу
		return;
	}

	out << input_file_data << endl; // Вносим изменения
	out << "упорядочивание элементов одномерного cимволного массива по алфавиту:" << endl;
	out << output_file_data << endl; // Вносим изменения

	out.close(); // Закрываем файл
}


