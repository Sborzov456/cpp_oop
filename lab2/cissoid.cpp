#include "cissoid.h"
cissoid::cissoid()
{
    a = 1;
}
cissoid::cissoid(double c_a)
{
    a = c_a;
}
void cissoid::set_a(double c_a)
{
    a = c_a;
}
double cissoid::get_a()
{
    return a;
}
void cissoid::print_a()
{
    std::cout << "Parameter of cissoid: " << a;
}
double cissoid::f(double x)
{
    if (x == 2 * a) return 0;
    double res;
    double temp = 2 * a - x;
    x = x * x * x;
    x = x / temp;
    if (x < 0) return 0;
    res = sqrt(x);
    return res;
}
double cissoid::area()
{
    return 3.14 * 3 * a * a;
}
double cissoid::distance(double angle)
{
    if ((angle == 90) || (angle == 270) || (angle == 0) || (angle == 180) || (angle == 360)) return 0;
    double res;
    double c = cos(angle*PI/180);
    double s = sin(angle*PI/180);
    res = 2*a*s*s;
    res = res/c;
    return res;
}
char* cissoid::formula()
{
    const char* s1 = "y^2 = x^3/(2  - x)";
    int l = strlen(s1) + 1;
    char num[20];
    sprintf_s(num, 20, "%.2f", a);
    l += strlen(num) + 1;
    char* s = new char[l];
    sprintf_s(s, l, "y^2 = x^3/(2*%.2f - x)", a);
    return s;
}








