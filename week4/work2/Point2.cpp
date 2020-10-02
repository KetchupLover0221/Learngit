#include<iostream>
#include"Point2.h"
using namespace std;
Point2::Point2()
{
    x = new int(10);
    y = new int(10);
}
Point2::Point2(int Xp, int Yp)
{
    x = new int(Xp);
    y = new int(Yp);
}// ����
Point2::Point2(const Point2& pn)
{
    this->x = new int(*pn.x);
    this->y = new int(*pn.y);
}//���
Point2& Point2 :: operator = (const Point2& pn)
{
    if (&pn != this)
    {
        this->x = new int(*pn.x);
        this->y = new int(*pn.y);
    }
    return *this;
}//�ֵ
Point2::~Point2()
{
    if (x != NULL)
    {
        delete x;
        delete y;
    }
}//����
void Point2::Show()
{
    cout << "x= " << *x << endl;
    cout << "y= " << *y << endl;
}
int  Point2::CompX()
{
    return *x;
}
void Point2::Showadd()
{
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
}