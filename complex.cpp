#include "complex.h"

namespace cmpx {

    template<typename T>
    constexpr Complex<T>::Complex(T real, T imaginary) noexcept
        : realNum(real), imaginaryNum(imaginary)
    {

    }

    template<typename T>
    Complex<T> Complex<T>::operator +(const Complex& c) {
        return Complex(realNum + c.realNum, imaginaryNum + c.imaginaryNum);
    }
}
