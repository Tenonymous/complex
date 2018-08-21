#include "complex.h"


int main()
{

   using namespace cmpx;

    cmpx::Complex<double> c{2.0,+5.0};
    std::cout << c << std::endl;
    cmpx::Complex<double> c2{1.0, 2.3};
    std::cout << (3 * c2) << '\n';
    return 0;
}
