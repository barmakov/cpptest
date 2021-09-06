// cpptest.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

int main()
{
	char key = 0;
	int x=1, y = 1;
	char player = '@';
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 0;
	pos.Y = 0;
	cout << player;

	SetConsoleCursorPosition(hStdout, pos);
	for (int i = 0; i < 20; i++)
	{
		pos.X = 59; pos.Y = i;
		SetConsoleCursorPosition(hStdout, pos);
		cout << "*";
		
	}
	for (int i = 0; i < 59; i++)
	{
		pos.Y = 20; pos.X = i;
		SetConsoleCursorPosition(hStdout, pos);
		cout << "*";

	}
	pos.X = 4;
	pos.Y = 22;
	SetConsoleCursorPosition(hStdout, pos);
	cout << "W - up, S - down, A - left, D - right, SPACE - push";
	pos.X = 0;
	pos.Y = 0;
	int bias = 0;
	char push = '#';
	SetConsoleCursorPosition(hStdout, pos);
	do
	{
		key = _getch();
		
		if (key == ' ')
		{
			int x = pos.X; int y = pos.Y;
			
			for (int i = 0; i < 3; i++)
			{
				if (i == 0)
				{
					push = '#';
					Beep(200, 200);
					
				}
				else if (i == 1)
				{
					push = '*';
					Sleep(250);
				}
				else if (i==2)
				{
					push = ' ';
					Sleep(250);
				}
						
				if ((pos.Y - 2) > -1)
				{
					pos.Y = y - 2;
					SetConsoleCursorPosition(hStdout, pos);
					cout << push;
					pos.Y = y;
				}
				if ((pos.Y + 2) < 20)
				{
					pos.Y = y + 2;
					SetConsoleCursorPosition(hStdout, pos);
					cout << push;
					pos.Y = y;
				}
				if ((pos.X - 4) > -1)
				{
					pos.X = x - 4;
					SetConsoleCursorPosition(hStdout, pos);
					cout << push;
					pos.X = x;
				}
				if ((pos.X + 4) < 59)
				{
					pos.X = x + 4;
					SetConsoleCursorPosition(hStdout, pos);
					cout << push;
					pos.X = x;
				}
				pos.X = x;
				pos.Y = y;
			}
			
			SetConsoleCursorPosition(hStdout, pos);
			
		}
		else
		{
			SetConsoleCursorPosition(hStdout, pos);
			cout << " ";
			if ((key == 'w' || key == -26) && (pos.Y - 1) > -1)
			{
				pos.Y--;
			}
			else if ((key == 's' || key == -21) && (pos.Y + 1) < 20)
			{
				pos.Y++;
			}
			else if ((key == 'a' || key == -28) && (pos.X - 1) > -1)
			{
				pos.X--;
			}
			else if ((key == 'd' || key == -94) && (pos.X + 1) < 59)
			{
				pos.X++;
			}
			SetConsoleCursorPosition(hStdout, pos);
			cout << player;
			SetConsoleCursorPosition(hStdout, pos);
		}


	} while (key != 27);

}


