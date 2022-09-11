#include "Header.h"
char*** read(string* input_file_name, int* n)
{
	char*** file_data;
	file_data = new char** [2];
	int i = 0;
	size_t length, linestart;
	char next;
	cout << "input filename:";
	cin >> *input_file_name;
	ifstream fs(*input_file_name);

	if (!fs) {
		cout << "Can't open file"; //Если ошибка открытия файла, то завершаем }программу
		return NULL;
	}
	*n = 0;
	while (!fs.eof())
	{
		fs.get(next);
		if (next == '\n')
			(*n)++;

	}
	file_data[0] = new char* [++(*n)];
	file_data[1] = new char* [(*n)];
	fs.clear();
	fs.seekg(0);
	linestart = fs.tellg();
	while (linestart != -1 && !fs.eof())// while (!eof(fs))
	{
		length = 0;
		while (fs.get(next) && !fs.eof())
		{
			if (next == '\n')
				break;
			length = (size_t)fs.tellg() - linestart;
		}
		fs.clear();
		fs.seekg(linestart);
		file_data[0][i] = new char[++length];
		file_data[1][i] = new char[length];
		fs.getline(file_data[0][i++], length, '\n');
		linestart = fs.tellg();
	}
	fs.close();             //Закрываем файл
	return file_data;
}
void change_filtered_item(char** input_file_data, char** output_file_data, int n, char filtered, char changed)
{
	int j, i;
	for (i = 0; i < n; i++)
	{
		for (j = 0; input_file_data[i][j] != 0; j++)
			if (input_file_data[i][j] == filtered)
				output_file_data[i][j] = changed;
			else
				output_file_data[i][j] = input_file_data[i][j];
		output_file_data[i][j] = 0;
	}

}
void Print_all_data(char** input_file_data, int n)
{
	for (int i = 0; i < n; i++)
		cout << input_file_data[i] << endl;
}
void save(string* output_file_name, char** input_file_data, char** output_file_data, char filtered, char changed, int n)
{
	cout << "output filename:";
	cin >> *output_file_name;

	ofstream out(*output_file_name); //Открываем файл для записи
	if (!out) {
		cout << "Can't open file"; //Если ошибка открытия файла, то завершаем программу
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		out << input_file_data[i] << endl; // Вносим изменения
	}
	out << "Заменить все вхождения символа " << filtered << " на символ " << changed << " в каждой строке текста" << endl;
	for (int i = 0; i < n; ++i)
	{
		out << output_file_data[i] << endl; // Вносим изменения
	}
	out.close(); // Закрываем файл
}

void delete_all(char*** file_data, int n)
{
	for (int j = 0; j <2; j++)
	{
		for (int i = 0; i < n; i++)
		{
			delete[] file_data[j][i];
		}
		delete[] file_data[j];
	}
	delete[] file_data;
}
