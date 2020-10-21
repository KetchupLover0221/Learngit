// Date.cpp
#include "Date.h"
#include <iomanip>

int Date::days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
// ���弰��ʼ����̬���ݳ�Ա
Date::Date(int Year, int Month, int Day)
{
	SetDate(Year, Month, Day);
}

bool Date::isLeapyear() const
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

bool isLeapyear(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

bool Date::isValid(int y, int m, int d)
{
	if (y <= 0 || m <= 0 || m > 12 || d <= 0) return false;
	days[1] = ::isLeapyear(y) ? 29 : 28;
	if (d > days[m - 1]) return false;
	return true;
}

int Date::GetTotalDays(int year, int month, int day)
{
	int y = year - 1, n;
	n = 365 * y + y / 4 - y / 100 + y / 400;
	days[1] = ::isLeapyear(year) ? 29 : 28;
	for (int i = 1; i < month; i++)
		n += days[i - 1];
	n += day;
	return n;
}

int Date::GetTotalDays() const
{
	return GetTotalDays(year, month, day);
}

int Date::GetYear() const { return year; }
int Date::GetMonth()const { return month; }
int Date::GetDay()  const { return day; }
int Date::GetWeek() const { return GetTotalDays() % 7; }

int Date::DaysOfYear() const
{
	int i, n = day;
	days[1] = ::isLeapyear(year) ? 29 : 28;
	// ������Ա���������޸ľ�̬���ݳ�Ա��ֵ
	for (i = 1; i < month; i++)
		n += days[i - 1];
	return n;
}

Date& Date::SetDate(int Year, int Month, int Day)
{
	if (isValid(Year, Month, Day))
		year = Year, month = Month, day = Day;		// ʹ�ö���������ʽ
	else
		year = month = day = 0;
	return *this;
}

Date& Date::SetDate(int Year, int Daysofyear)
{
	int y = Year - 1, n;
	n = GetTotalDays(Year, 1, 1) + Daysofyear - 1;
	y = n / 365;
	y -= (y / 4 - y / 100 + y / 400) / 365;
	if (n <= (365 * y + y / 4 - y / 100 + y / 400))
		year = y;
	else
		year = y + 1;
	y = year - 1;
	n -= 365 * y + y / 4 - y / 100 + y / 400;
	days[1] = ::isLeapyear(year) ? 29 : 28;
	for (month = 1; month <= 12; month++)
	{
		if (n > days[month - 1])
			n -= days[month - 1];
		else
		{
			day = n;
			break;
		}
	}
	return *this;
}

// ���������
Date operator+(const Date& d, int n)		// ��Ԫ����
{
	Date temp(d);
	int m = temp.DaysOfYear() + n;
	temp.SetDate(d.year, m);
	return temp;
}

Date operator-(const Date& d, int n)		// ��Ԫ����
{
	return d + (-n);						// �����Ѿ����ص����������
}

Date operator+(int n, const Date& d)		// ����Ϊ��Ԫ����
{
	return d + n;
}

int Date::operator-(const Date& d) const	// ��Ա����
{
	return GetTotalDays() - GetTotalDays(d.year, d.month, d.day);
}

Date& Date::operator+=(int n)
{
	*this = *this + n;						// ���� operator+ ��Ĭ�ϵĸ�ֵ���������
	return *this;
}

Date& Date::operator-=(int n)
{
	*this = *this + (-n);
	return *this;
}

bool Date::operator> (const Date& d) const { return *this - d > 0; }
bool Date::operator>=(const Date& d) const { return *this - d >= 0; }
bool Date::operator< (const Date& d) const { return *this - d < 0; }
bool Date::operator<=(const Date& d) const { return *this - d <= 0; }
bool Date::operator==(const Date& d) const { return *this - d == 0; }
bool Date::operator!=(const Date& d) const { return *this - d != 0; }

ostream& operator<<(ostream& out, const Date& d)
{
	out << setfill('0') << setw(4) << d.year
		<< '/' << setw(2) << d.month
		<< '/' << setw(2) << d.day
		<< setfill(' ');
	return out;
}

/*istream& operator>>(istream& in, Date& d)
{
	int year, month, day;
	char str[100];

	in.getline(str, 100, '/');				// ��ȡ�����������ַ�'/'Ϊֹ
	if (in == NULL) return in;
	year = atoi(str);

	in.getline(str, 100, '/');				// ��ȡ�����������ַ�'/'Ϊֹ
	if (in == NULL) return in;
	month = atoi(str);

	in.getline(str, 100, '\n');				// ��ȡ�����������ַ�'\n'Ϊֹ
	if (in == NULL) return in;
	day = atoi(str);

	d.SetDate(year, month, day);

	return in;
}*/

Date& Date::operator++()
{
	days[1] = isLeapyear() ? 29 : 28;
	day++;
	if (day > days[month - 1])
	{
		day = 1;
		month++;
	}
	if (month > 12)
	{
		month = 1;
		year++;
	}
	return *this;
}

Date& Date::operator--()
{
	days[1] = isLeapyear() ? 29 : 28;
	if (day == 1 && month == 1)
	{
		year--;
		month = 12;
		day = 31;
		return *this;
	}
	day--;
	if (day < 1)
	{
		month--;
		day = days[month - 1];
	}
	return *this;
}

Date Date::operator++(int)
{
	Date temp(*this);						// ���汾����ԭֵ�����Ա㺯������
	++(*this);								// ����ǰ����������ı�����ֵ
	return temp;							// ���ر������ԭֵ
}

Date Date::operator--(int)
{
	Date temp(*this);
	--(*this);
	return temp;
}
