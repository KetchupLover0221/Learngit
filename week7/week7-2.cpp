#include <iostream>
using namespace std;
class RMB
{
public:
	RMB(double x = 0)
	{
		int n = int(100 * (x + 0.005));
		yuan = n / 100;
		jiao = n / 10 % 10;
		fen = n % 10;
	}
	operator double() const
	{
		return yuan + jiao * 0.1 + fen * 0.01;
	}
private:
	int yuan, jiao, fen;
};
int main()
{
	RMB x = 1.23;
	cout << x << "\n"
		<< x + 2 << "\t" << 2 + x << "\n"
		<< x - 2 << "\t" << 2 - x << "\n"
		<< x * 2 << "\t" << 2 * x << "\n"
		<< x / 2 << "\t" << 2 / x << "\n"
		<< x * x << "\n"
		<< (x > 1) << "\t" << (x < 1) << endl;
	RMB y = x + 2;
	cout << (x < y) << "\t" << (x <= y) << "\t"
		<< (x > y) << "\t" << (x >= y) << "\t"
		<< (x == y) << "\t" << (x != y) << endl;
	x = 2 + 2 * x + 3.5;
	cout << x << endl;
	return 0;
}