#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;
char*** read(string* input_file_name, int* n);
void change_filtered_item(char** input_file_data, char** output_file_data, int n, char filtered, char changed);
void Print_all_data(char** input_file_data, int n);
void save(string* output_file_name, char** input_file_data, char** output_file_data, char filtered, char changed, int n);
void delete_all(char*** file_data, int n);