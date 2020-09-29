#include <iostream>
#include"Point.h"
using namespace std;

int main()
{
    int *a= new int[5];
    int* b = new int[5];
    *a = 3;
    *b = 4;
    Point p1(1, 2);
    Point p2(*a, *b);
    p1.Show();
    p2.Show();
    Point p3 = p1;
    p3.Show();
    delete a, b;
    p2.Show();
    p2 = p1;
    p2.Show();
    return 0;
}


