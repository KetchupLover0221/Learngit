#pragma once
//Point.h
#ifndef POINT_H
#define POINT_H
class Point
{
public:
	Point(int Xp, int Yp);
	Point(const Point& pn);
	Point& operator = (const Point& pn);
	~Point();
	void Show();
private:
	int* x, * y;
};
#endif