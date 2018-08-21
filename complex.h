#ifndef COMPLEX_H
#define COMPLEX_H

#include <math.h>
#include <iostream>

namespace cmpx {
    template <typename Type = double>
    class Complex
    {
    public:
        constexpr Complex(Type real = {}, Type imaginary = {}) noexcept;
        ~Complex() = default;

        Complex(Complex&&) = default;
        Complex& operator =(Complex&&) = default;

        Complex(const Complex&) = default;
        Complex& operator =(const Complex&) = default;

        Complex operator +(const Complex& c) const noexcept;
        Complex operator -(const Complex& c) const noexcept;
        Complex operator *(Type number) const noexcept;

        constexpr double module() const noexcept;
        Complex operator -() const noexcept;

        std::ostream& print(std::ostream& os) const;

    private:
        Type realNum;
        Type imaginaryNum;
        char sign;
    };

    template <typename Type>
    constexpr Complex<Type>::Complex(Type real, Type imaginary) noexcept
        : realNum{real}, imaginaryNum{imaginary}, sign{imaginaryNum >= 0 ? '+' : '-'}
    {

    }

    template <typename Type>
    Complex<Type> Complex<Type>::operator +(const Complex& c) const noexcept {
        return Complex{realNum + c.realNum, imaginaryNum + c.imaginaryNum};
    }

    template <typename Type>
    Complex<Type> Complex<Type>::operator -(const Complex& c) const noexcept {
        return Complex{realNum - c.realNum, imaginaryNum - c.imaginaryNum};
    }

    template <typename Type>
    Complex<Type> Complex<Type>::operator *(Type number) const noexcept {
        return Complex{realNum* number, imaginaryNum * number};
    }

    template <typename Type>
    constexpr double Complex<Type>::module() const noexcept {
        return sqrt(realNum * realNum + imaginaryNum * imaginaryNum);
    }

    template <typename Type>
    Complex<Type> Complex<Type>::operator -() const noexcept {
        return Complex{realNum, -imaginaryNum};
    }

    template <typename Type>
    std::ostream& Complex<Type>::print(std::ostream& os) const {
        return os << realNum <<  " " << sign << " " << std::abs(imaginaryNum) << 'i';
    }

    template <typename Type>
    std::ostream& operator <<(std::ostream& os, const Complex<Type>& c) {
                return c.print(os);
    };

    template <typename T1, typename T2>
    Complex<T2> operator*(T1 number, const Complex<T2>& c) noexcept {
                return c * number;
    }
}
#endif // COMPLEX_H
