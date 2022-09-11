#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;
char** read(string* input_file_name);
void sort(char* input_file_data, char* output_file_data);
void Print_all_data(char** input_file_data, int n);
void save(string* output_file_name, char* input_file_data, char* output_file_data);
