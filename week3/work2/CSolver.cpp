#include < iostream>
#include < cmath>
#include"CSolver.h"
 using namespace std;
CSolver:: CSolver(double a, double b, double c)
{
	_a = a; _b = b; _c = c; flag = -3;
}
void  CSolver::Set(double a, double b, double c)
{
	_a = a; _b = b; _c = c; flag = -3;
}
double CSolver::GetA() const { return _a; }
double CSolver::GetB() const { return _b; }
double CSolver::GetC() const { return _c; }
double CSolver::GetX1() const { return x1; }
double CSolver::GetX2() const { return x2; }
int CSolver::GetFlag() const { return flag; }
void CSolver::ShowEquation() const
{
	if (_a == 1) cout << "x^2";
	else cout << _a << "x^2";
	if (_b > 0) cout << " + " << _b << "x";
	else if (_b < 0) cout << " - " << -_b << "x";
	if (_c > 0) cout << " + " << _c;
	else if (_c < 0) cout << " - " << -_c;
	cout << " = 0";
}
void CSolver::ShowSolution() const
{
	switch (flag)
	{
	case -3: cout << " 尚未进行求解。"; break;
	case -2:cout << " 该方程无实数根"; break;
	case -1:cout << "该方程是矛盾式"; break;
	case 0:cout << " 该方程为一次方程。其解：" << "x = " << x1; break;
	case 1: cout << " 该方程有重根" << "x1 = x2 = " << x1; break;
	case 2: cout << " 该方程有两个不同的实数根： " << "x1 = " << x1 << ", x2 = " << x2; break;
	case 3: cout << " 该方程为恒等式。"; break;
	}
	cout << endl;
}
int CSolver::Solve()
{
	double d;
	if (_a == 0)
	{
		if (_b ==0)
		{
			flag = (_c == 0) ? 3 : -1;
		}
		else
		{
			flag = 0;
			x1 = x2 = -_c / _b;
		}
	}
	else
	{
		d = Delta();
		if (d >=0)
		{
			d = sqrt(d);
			x1 = (-_b - d) / (2 * _a);
			x2 = (-_b + d) / (2 * _a);
			flag = (d > 0) ? 2 : 1;
		}
		else flag = -2;
	}
	return flag;
}
double CSolver::Delta()
{
	return _b * _b - 4 * _a * _c;
}
