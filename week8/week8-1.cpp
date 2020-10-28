
#include <iostream>
using namespace std;
class Point//点类基类
{
public:
    Point(int X = 0,int Y = 0)
    {
        x = X;
        y = Y;
    }
    virtual void ShowPointCO()
    {
        cout << "The Point is at: " << x << " , " << y<<endl;
    }
protected:
    int x, y;
};

class Circle : public Point
{
public:
    Circle(int X = 0, int Y = 0, double R = 1)
    {
        x = X;
        y = Y;
        r = R;
        p = 2 * r * 3.14;
        s = r * r * 3.14;
    }
    virtual void Showp()
    {
        cout << "The perimeter of this circle is: " << p << endl;
    }
    virtual void ShowPointCO()
    {
        cout << "The Center is at: " << x << " , " << y << endl;
    }
    virtual void ShowS()
    {
        cout << "The size of this circle is: " << s << endl;
    }
protected:
    double r;
    double p;
    double s;
};

class Cylinder : public Circle
{
public:
    Cylinder(int X = 0, int Y = 0, double R = 1, double H=1)
    {
        x = X;
        y = Y;
        r = R;
        h = H;
        p = 2 * r * 3.14;
        s = r * r * 3.14;
    }
    virtual void showCS()
    {
        double cs = s + s + p * h;
        cout << "The CoverSize of this cylinder is: " << cs << endl;
    }
    virtual void showV()
    {
        double volume = s * h;
        cout << "The Volume of this cylinder is: " << volume << endl;
    }
protected:
    double h;
};
int main()
{
    Point point1(2, 2);
    point1.ShowPointCO();
    Circle c1(3, 3, 2);
    c1.Showp();
    c1.ShowS();
    c1.ShowPointCO();
    Cylinder c2(3, 3, 2, 2);
    c2.showCS();
    c2.showV();

}

