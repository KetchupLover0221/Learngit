#include<iostream>
#include<iomanip>
#include"Date.h"
using namespace std;
Date::Date(int year, int month, int day)
{
	y = year; m = month; d = day;
}
void Date::show()  { cout << "����Ϊ��" << y << "�� " << m << "�� " << d << "��" << endl; }
void Date::add() 
{
	d++;
	int judge = 0;
	int judge2 = 0;
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
	{
		judge = 1;//�ж�Ϊ����
		if (m == 2 && d == 30)//����2��
		{
			m++;
			d = 1;
		}
	}
	else if (judge == 0 && m == 2 && d == 29)//ƽ��2��
	{
		m++;
		d = 1;
	}
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		judge2 = 1;//�ж�Ϊ����
		if (d == 32)
		{
			d = 1;
			m++;
		}
	}
	else if (judge2 == 0 && d == 31)//С�����һ��
	{
		d = 1;
		m++;
	}
	if (m == 13)
	{
		m = 1;
		y++;
	}
}