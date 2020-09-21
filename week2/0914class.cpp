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
}

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
}

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

void findPoint(int a[5][5])
{
	int max[10] = { 0 }, min[10] = { 0 }, xm[10] = { 0 }, ym[10] = { 0 };
	int judge = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (a[i][j] > max[i])
			{
				max[i] = a[i][j];
			}
			if (a[i][j] < min[j])
			{
				min[j] = a[i][j];
			}
		}
	}//确定每行最大每列最小值
	for (int p = 0; p < 5; p++)
	{
		for (int q = 0; q < 5; q++)
		{
			if (a[p][q] == max[p] && a[p][q] == min[q])
			{
				judge = 1;
				cout << "鞍点为：" << a[p][q] << endl;
			}
		}
	}
	if (judge == 0)
	{
		cout << "无鞍点" << endl;
	}
}

int fib(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}//递归结束条件
	else
	{
		return fib(n - 1) + fib(n - 2);
	}
}
template <typename T>  void ShowTypeSize(const char* type, T x)
{
	int n = sizeof(x);
	cout << "sizeof(" << type << "):  " << n << " byte(s)" << endl;
}

int sum(int n)
{
	int sum = 0;
	while (n)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}//整数各位数字之和
int cInt(const void* a, const void* b)
{
	return sum(*(int*)a) - sum(*(int*)b);
}//整数型的比较规则
int cDouble(const void* a, const void* b)
{
	return *(double*)a - *(double*)b;
}//浮点型比较规则
int cChar(const void* a, const void* b)
{
	int size1 = strlen(*(char**)a);
	int size2 = strlen(*(char**)b);
	if (size1 > size2)
		return 1;
	else if (size1 == size2)
		return strcmp(*(char**)a, *(char**)b);
	else
		return -1;
}//字符型比较规则

int main()
{
	double d = distance(1, 1, 2, 2);
	cout << d<<endl;
	//p194(1)

	NextDay(2020, 12, 31);
	//p194(2)

	int a[5][5];
	creatMatrix(a);
	displayMatrix(a);
	transMatrix(a);
	displayMatrix(a);
	//p194(3)

	int b[5][5];
	creatMatrix(b);
	findPoint(b);
	transMatrix(b);
	findPoint(b);
	//p194(4)

	int e;
	cin >> e;
	cout << fib(e)<<endl;
	//p194(5)

	//p194(6) 以二进制输出各数

	ShowTypeSize("int", int(1));
	ShowTypeSize("double", double(1));
	ShowTypeSize("long", long(1));
	//p194(7)

	/*
	p194(8)
	127
	1111111
	177
	7F
	*/
	int x[10] = { 12, 32, 42, 51, 8, 16, 51, 21, 19, 9 };
	double y[10] = { 32.1, 456.87, 332.67, 442.0, 98.12, 451.79, 340.12, 54.55, 99.87, 72.5 };
	char const*z[10] = { "enter", "number", "size", "begin", "of", "cat", "case", "program", "certain", "a" };
	qsort(x, 10, sizeof(int), cInt);
	for (int i = 0; i < 10; i++)
	{
		cout << x[i] << " ";
	}
	cout << endl;
	qsort(y, 10, sizeof(double), cDouble);
	for (int i = 0; i < 10; i++)
	{
		cout << y[i] << " ";
	}
	cout << endl;
	qsort(z, 10, sizeof(*z), cChar);
	for (int i = 0; i < 10; i++)
	{
		cout << z[i] << " ";
	}
}