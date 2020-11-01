#include "Vector.h"
#include <iostream>
using namespace std;

int main()
{
    int a[4] = { 0, 2, 4, 6 };
    int b[4] = { 1, 4, 6, 8 };

    Vector<int> vec1(a, 4), vec2(b, 4), vec3;
    Vector<double> vec4, vec5;
    cin >> vec4;
    cout << vec4 << endl;
    vec3 = vec1 + vec2;
    vec3.Show();
    vec3 = vec1 - vec2;
    vec3.Show();
    vec3 = vec1 * 5;
    vec3.Show();
    vec3 = 5 * vec2;
    vec3.Show();
    cout << ++vec4 << endl;
    vec3 += vec1;
    vec3.Show();
    vec3 -= vec2;
    vec3.Show();
    if (vec1 == vec2)
        cout << "True." << endl;
    else
    {
        cout << "False" << endl;
    }

    cout << vec3.GetLen() << endl;
    vec3.Resize(3);
    cout << vec3 << endl;
    vec4.Resize(-2);
    cout << vec4 << endl;
}
   