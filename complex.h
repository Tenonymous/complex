#ifndef COMPLEX_H
#define COMPLEX_H

#include <math.h>
#include <iostream>

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
        Complex operator -(const Complex& c) noexcept;
        Complex operator *(T number) noexcept;

        constexpr double module() const noexcept {
            return sqrt(realNum * realNum + imaginaryNum * imaginaryNum);
        }

        Complex operator -() noexcept {
            return Complex{realNum, -imaginaryNum};
        }

        friend Complex operator*(T number, const Complex& c) noexcept;
        friend std::ostream& operator <<(std::ostream&, const Complex&);

    private:
        T realNum;
        T imaginaryNum;
        char sign;
    };

}
#endif // COMPLEX_H
