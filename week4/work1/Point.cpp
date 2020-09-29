#include<iostream>
#include"Point.h"
using namespace std;
Point::Point(int Xp, int Yp)
{
    x = new int(Xp);
    y = new int(Yp);
}// ����
Point::Point(const Point& pn)
{
    this->x = new int(*pn.x);
    this->y = new int(*pn.y);
}//���
Point&Point :: operator = (const Point& pn)
{
    if (&pn != this)
    {
        this->x = new int(*pn.x);
        this->y = new int(*pn.y);
    }
    return *this;
}//�ֵ
Point::~Point()
{
    if (x != NULL)
    {
        delete x;
        delete y;
    }
}//����
void Point::Show()
{
    cout << "x= " << *x << endl;
    cout << "y= " << *y << endl;
}