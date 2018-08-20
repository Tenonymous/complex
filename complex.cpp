#include "complex.h"

namespace cmpx {

    template<typename T>
    constexpr Complex<T>::Complex(T real, T imaginary) noexcept
        : realNum(real), imaginaryNum(imaginary)
    {

    }

    template<typename T>
    Complex<T> Complex<T>::operator +(const Complex& c) noexcept {
        return Complex(realNum + c.realNum, imaginaryNum + c.imaginaryNum);
    }

    template<typename T>
    Complex<T> Complex<T>::operator *(T number) noexcept {
        return Complex(realNum* number, imaginaryNum * number);
    }
    template <typename T>
    Complex<T> operator*(T number, const Complex<T>& c) noexcept {
        return c * number;
    }
}
