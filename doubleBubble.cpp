
#include <iostream>
#include <time.h>
using namespace std;
double gettime(int restart = 0)	   // 参数带默认值，非零表示重新设置计时起点
{
	const double c = 1.0 / CLOCKS_PER_SEC;// 毫秒转换至秒
	static long t = clock(); 	// 静态局部变量，第一次调用本函数时，确定计时起点
	if (restart) t = clock();	   // 根据实参决定是否重新确定计时起点
	return c * (clock() - t); 		   // 从上一计时点到现在所经历的时间差
}
void fvdoubleBubble(double* a, int length)//冒泡排序带计时计数
{
	unsigned long long nComp = 0;// 未使用引用型传递,因为做不来
	unsigned long long nAssign = 0;// 非递归函数，可在此置0
	int small, big, s, b, i = 0;
	small = 0;
	big = length - 1;
	while (small < big)
	{
		s = small + 1;
		b = big - 1;
		for ( i = small; i < big; i++)
		{
			nComp += 1;
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				nAssign += 3;
				b = i;
			}
		}
		big = b;//第一轮正向循环
		for (i = big; i > small; i--)
		{
			nComp += 1;
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				nAssign += 3;
				s = i;
			}
		}
		small = s;//第二轮反向循环
	}
	cout << "比较次数为：" << nComp << "次，赋值次数为：" << nAssign << "次。" << '\n';
	for (int k = 0; k < length; k++)
	{
		cout << a[k] << " ";
	}
	cout << '\n';
}

int main()
{
	double arr[500];
	int i = 0;
	while (cin.peek() != '\n')
	{
		cin >> arr[i++];
	}
	double t;
	gettime(1);
	fvdoubleBubble(arr, i);
	t = gettime(0);
	cout << "排序用时：" << t << "s" << '\n';

}

