#include <iostream>
#include"Date.h"
using namespace std;
int main()
{
	Date d;
	d.SetDate(2008, 5, 1);
	cout << ++d << endl;
	cout << d << endl;
	d.SetDate(2008, 5, 1);
	cout << d++ << endl;
	cout << d << endl;
	d.SetDate(2008, 5, 1);
	cout << ++(++d) << endl;
	cout << d << endl;
	d.SetDate(2008, 5, 1);
	cout << (++d)++ << endl;
	cout << d << endl;
	d.SetDate(2008, 5, 1);
	cout << ++(d++) << endl;
	cout << d << endl;
	d.SetDate(2008, 5, 1);
	cout << (d++)++ << endl;
	cout << d << endl;
	return 0;
}

