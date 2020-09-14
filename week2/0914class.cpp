#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
//int N*  intN [] 都可作为形参传递指针
// N=N+2； 指针向后两个位置
// cout<< *N 输出N现在所指元素
double distance(double x1, double y1, double x2, double y2)
{
	double a = pow((x2 - x1), 2);
	double b = pow((y2 - y1), 2);
	double c = pow((a + b), 0.5);
	return c;
}//p194 (1)

void NextDay(int year, int month, int day)
{
	day++;
	int judge = 0;
	int judge2 = 0;
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		judge = 1;//判断为闰年
		if (month == 2 && day == 30)//闰年2月
		{
			month++;
			day = 1;
		}
	}
	else if (judge == 0 && month == 2 && day == 29)//平年2月
	{
		month++;
		day = 1;
	}
	if (month == 1 || month == 3|| month == 5|| month == 7|| month == 8|| month == 10|| month == 12)
	{
		judge2 = 1;//判断为大月
		if (day == 32)
		{
			day = 1;
			month++;
		}
	}
	else if (judge2 == 0 && day == 31)//小月最后一天
	{
		day = 1;
		month++;
	}
	if (month == 13)
	{
		month = 1;
		year++;
	}
	cout << "下一天为 " << year << "年" << month << "月" << day << "日" << endl;
}//p194(2)

void creatMatrix(int a[5][5])//创建5乘5矩阵
{
	for (int i = 0; i < 5;i++)
	{
		for (int j = 0; j < 5;j++)
		{
			a[i][j] = (rand() % 100);
		}
	}
}
void displayMatrix(int a[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		cout << setw(5)<<a[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
void transMatrix(int a[5][5])
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j <= i; j++)
		{
			swap(a[i][j],a[j][i]);
		}
}
int main()
{
	//double a = distance(1, 1, 2, 2);
	//cout << a;

	//NextDay(2020, 12, 31);

	int a[5][5];
	creatMatrix(a);
	displayMatrix(a);
	transMatrix(a);
	displayMatrix(a);

}