#include "cissoid.h"
int main()
{
    cissoid c;
    char* s = nullptr;
    while (1)
    {
        std::cout << "Your cissoid is: ";
        s = c.formula();
        std::cout << s << std::endl;
        std::cout << "Area: ";
        std::cout << c.area() << std::endl;
        while (1)
        {
            int choice1;
            double f;
            double dist;
            std::cout << "0. Quit" << std::endl;
            std::cout << "1. Get f(x)" << std::endl;
            std::cout << "2. Get distance to center in polar coordinats"<<std::endl;
            std::cin >> choice1;
            if (choice1 == 1)
            {
                double x;
                while (1)
                {
                    std::cout << "Enter x: ";
                    std::cin >> x;
                    f = c.f(x);
                    if ((f != 0) || (x == 0)) break;
                    else std::cout << "Error, function f(x) unspecified" << std::endl;
                }
                std::cout << "y1 = " << f << std::endl;
                std::cout << "y2 = " << -1*f << std::endl;
            }
            else if (choice1 == 2)
            {
                double angle;
                while (1)
                {
                    std::cout << "Enter angle from 0 to 360 degrees: ";
                    std::cin >> angle;
                    dist = c.distance(angle);
                    if ((dist != 0) || (angle == 0) || (angle == 180)) break;
                    else std::cout << "Error, distance unspecified" << std::endl;
                }
                std::cout << "Distance: " << dist<<std::endl;
            }
            else if (choice1 == 0) break;
        }
        int choice2;
        std::cout << "0. Quit" << std::endl;
        std::cout << "1. Create new cissoid" << std::endl;
        std::cin >> choice2;
        if (choice2 == 1)
        {
            int a;
            while (1)
            {
                std::cout << "Enter new parametr of cissoid: ";
                std::cin >> a;
                if (a > 0) break;
                else std::cout << "Error of input" << std::endl;
            }
            c.set_a(a);
        }
        else if (choice2 == 0) break;
    }
    return 0;
}
