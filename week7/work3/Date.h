// Date.h
#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date
{
public:
	Date(int Year = 2008, int Month = 1, int Day = 1);
	bool isLeapyear() const;						// 判断是否为闰年
	friend bool isLeapyear(int y);					// 判断是否为闰年
	Date& SetDate(int Year, int Month, int Day);	// 根据年、月、日设置日期
	Date& SetDate(int Year, int Daysofyear);
	// 根据年、当年的天数设置日期。Daysofyear 可为负数、较大的数
	int GetYear() const, GetMonth() const, GetDay() const;
	int GetWeek() const;							// 计算当前日期的星期数
	int DaysOfYear() const;							// 计算当前日期在当年的天数

	// 重载运算符
	friend Date operator+(const Date& d, int n);
	friend Date operator-(const Date& d, int n);
	friend Date operator+(int n, const Date& d);
	// 没有 n-d 运算
	int operator-(const Date& d) const;

	Date& operator+=(int n);
	Date& operator-=(int n);

	bool operator> (const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator< (const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

	Date& operator++();
	Date& operator--();
	Date operator++(int);
	Date operator--(int);

protected:
	static bool isValid(int y, int m, int d);		// 静态成员函数
	static int GetTotalDays(int y, int m, int d);	// 静态成员函数
	int GetTotalDays() const;						// 计算“总天数”，仅内部使用

private:
	static int days[12];							// 静态数据成员
	int year, month, day;
};

#endif
