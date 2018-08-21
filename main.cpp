#include "complex.h"


int main()
{
    cmpx::Complex<double> c{2.0,+5.0};
    std::cout << c << std::endl;
    cmpx::Complex<double> c2{1.0, 2.3};
    std::cout << (3 * c2) << '\n';
    std::cout << c  + c2 << '\n';
    std::cout << c - c2 << '\n';
    std::cout << -c << '\n';
    cmpx::Complex<double> c3{};
    std::cin >> c3;
    std::cout << c3 << '\n';
    return 0;
}
