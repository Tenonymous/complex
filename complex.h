#ifndef COMPLEX_H
#define COMPLEX_H

#include <math.h>

namespace cmpx {
    template <typename T>
    class Complex
    {
    public:
        constexpr Complex(T real = {}, T imaginary = {}) noexcept;
        ~Complex() = default;
        Complex(Complex&&) = default;
        Complex& operator =(Complex&&) = default;

        Complex(const Complex&) = default;
        Complex& operator =(const Complex&) = default;

        Complex operator +(const Complex& c) noexcept;
        Complex operator *(T number) noexcept;

        constexpr double module() const  {
            return sqrt(realNum * realNum + imaginaryNum * imaginaryNum);
        }

        Complex operator -() {
            return Complex(realNum, -imaginaryNum);
        }

        friend Complex operator*(T number, const Complex& c) noexcept;

    private:
        T realNum;
        T imaginaryNum;
    };

}
#endif // COMPLEX_H
