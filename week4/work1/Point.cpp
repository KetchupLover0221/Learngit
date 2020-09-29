#include<iostream>
#include"Point.h"
using namespace std;
Point::Point(int Xp, int Yp)
{
    x = new int(Xp);
    y = new int(Yp);
}// 构造
Point::Point(const Point& pn)
{
    this->x = new int(*pn.x);
    this->y = new int(*pn.y);
}//深拷贝
Point&Point :: operator = (const Point& pn)
{
    if (&pn != this)
    {
        this->x = new int(*pn.x);
        this->y = new int(*pn.y);
    }
    return *this;
}//深赋值
Point::~Point()
{
    if (x != NULL)
    {
        delete x;
        delete y;
    }
}//析构
void Point::Show()
{
    cout << "x= " << *x << endl;
    cout << "y= " << *y << endl;
}