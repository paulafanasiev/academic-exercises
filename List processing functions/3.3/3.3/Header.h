#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <conio.h>
#ifdef max
#undef max
#endif
using namespace std;

struct workday
{
	bool workday;
	int start_time,end_time;
};

struct listElem
{
	string FIO,spec;
	workday* work;// поле данных
	listElem* ptr=NULL; // указатель на следующий элемент
};


void listprint(listElem* root);
void Get_new_item_from_keyboard(listElem** root);
void save(listElem* root);
void read(listElem** root);



