#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<conio.h>
#include<Windows.h>
using namespace std;



void main()
{
	setlocale(LC_ALL, "");
	time_t timer;
	char key;
	int i = 0;
	do
	{
		//key = _getch();
		/*for (;;)
		{
		}*/
		system("CLS");
		time(&timer);
		//cout << timer << endl;
		tm* current_time = localtime(&timer);
		cout << asctime(current_time) << endl;
		Sleep(1000);
		i++;
	} while (i < 100);
}