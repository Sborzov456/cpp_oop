#include <iostream>
#include <math.h>
#include <string.h>
#include <iomanip>
const double PI = acos(-1.0);
class cissoid
{
private:
    double a;
public:
    cissoid();
    cissoid(double c_a);
    void set_a(double c_a);
    double get_a();
    void print_a();
    double f(double x);
    double area();
    char* formula();
    double distance(double angle);
};

