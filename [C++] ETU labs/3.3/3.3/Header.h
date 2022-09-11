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

struct list
{
	string FIO,spec;
	workday* work;// поле данных
	list* ptr=NULL; // указатель на следующий элемент
};


void listprint(list* lst);
void Get_new_item_from_keyboard(list** lst);
void save(list* lst);
void read(list** lst);



