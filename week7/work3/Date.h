// Date.h
#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date
{
public:
	Date(int Year = 2008, int Month = 1, int Day = 1);
	bool isLeapyear() const;						// �ж��Ƿ�Ϊ����
	friend bool isLeapyear(int y);					// �ж��Ƿ�Ϊ����
	Date& SetDate(int Year, int Month, int Day);	// �����ꡢ�¡�����������
	Date& SetDate(int Year, int Daysofyear);
	// �����ꡢ����������������ڡ�Daysofyear ��Ϊ�������ϴ����
	int GetYear() const, GetMonth() const, GetDay() const;
	int GetWeek() const;							// ���㵱ǰ���ڵ�������
	int DaysOfYear() const;							// ���㵱ǰ�����ڵ��������

	// ���������
	friend Date operator+(const Date& d, int n);
	friend Date operator-(const Date& d, int n);
	friend Date operator+(int n, const Date& d);
	// û�� n-d ����
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
	static bool isValid(int y, int m, int d);		// ��̬��Ա����
	static int GetTotalDays(int y, int m, int d);	// ��̬��Ա����
	int GetTotalDays() const;						// ���㡰�������������ڲ�ʹ��

private:
	static int days[12];							// ��̬���ݳ�Ա
	int year, month, day;
};

#endif
