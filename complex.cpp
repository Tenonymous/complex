#include "complex.h"

namespace cmpx {

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
    Complex<T> operator*(T number, const Complex<T>& c) noexcept {
        return c * number;
    }

    template <typename T>
    std::ostream& operator <<(std::ostream& os, const Complex<T>& c) {
        os << c.realNum <<  " " << c.sign << " " << std::abs(c.imaginaryNum) << 'i';
        return os;
    }
}
