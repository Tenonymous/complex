#ifndef COMPLEX_H
#define COMPLEX_H

#include <math.h>
#include <iostream>

namespace cmpx {
    template <typename T = double>
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

        constexpr double module() const noexcept;
        Complex operator -() noexcept;

        friend Complex operator*(T number, const Complex& c) noexcept {
             return c * number;
        }

        friend std::ostream& operator <<(std::ostream& os, const Complex<T>& c) {
            return os << c.realNum <<  " " << c.sign << " " << std::abs(c.imaginaryNum) << 'i';
        }

    private:
        T realNum;
        T imaginaryNum;
        char sign;
    };

    template <typename T>
    constexpr Complex<T>::Complex(T real, T imaginary) noexcept
        : realNum{real}, imaginaryNum{imaginary}, sign{imaginaryNum >= 0 ? '+' : '-'}
    {

    }

    template <typename T>
    Complex<T> Complex<T>::operator +(const Complex& c) noexcept {
        return Complex{realNum + c.realNum, imaginaryNum + c.imaginaryNum};
    }

    template <typename T>
    Complex<T> Complex<T>::operator -(const Complex& c) noexcept {
        return Complex{realNum - c.realNum, imaginaryNum - c.imaginaryNum};
    }

    template <typename T>
    Complex<T> Complex<T>::operator *(T number) noexcept {
        return Complex{realNum* number, imaginaryNum * number};
    }

    template <typename T>
    constexpr double Complex<T>::module() const noexcept {
        return sqrt(realNum * realNum + imaginaryNum * imaginaryNum);
    }

    template <typename T>
    Complex<T> Complex<T>::operator -() noexcept {
        return Complex{realNum, -imaginaryNum};
    }

}
#endif // COMPLEX_H
