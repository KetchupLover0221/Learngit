
#include <iostream>
#include"CSolver.h"
using namespace std;
int main()
{
    CSolver e1(1, -2, 1);
    e1.ShowEquation();
    e1.Solve();
    e1.ShowSolution();
    CSolver e2(1, -3, 2);
    e2.ShowEquation();
    e2.Solve();
    e2.ShowSolution();
    CSolver e3(1, 5, 10);
    e3.ShowEquation();
    e3.Solve();
    e3.ShowSolution();
    

}