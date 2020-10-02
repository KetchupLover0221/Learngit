#pragma once
#pragma once
//Point.h
#ifndef POINT_H
#define POINT_H
class Point2
{
public:
	Point2();
	Point2(int Xp, int Yp);
	Point2(const Point2& pn);
	Point2& operator = (const Point2& pn);
	void Show();
	int CompX();
	void Showadd();
	~Point2();
private:
	int* x, * y;
};
#endif
