#pragma once
// CSolver.h 
#ifndef CSOLVER_H
#define CSOLVER_H
class CSolver
{
public:
	CSolver(double a = 1, double b = 0, double c = 0);
	void Set(double a, double b, double c);
	int Solve(), GetFlag() const;
	double GetA() const, GetB() const, GetC () const; 
	double GetX1 () const, GetX2() const;
	void ShowEquation() const, ShowSolution() const;
protected:
	double Delta();
private:
	double _a, _b, _c, x1, x2;
	int flag;
};
#endif // !CSOLVER_H
