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

        auto operator +(const Complex&) const noexcept;
        auto& operator +=(const Complex&) noexcept;
        auto operator -(const Complex&) const noexcept;
        auto& operator -=(const Complex&) noexcept;
        auto operator *(Type number) const noexcept;
        auto& operator *=(Type number) noexcept;

        bool operator ==(const Complex&) noexcept;
        bool operator !=(const Complex&) noexcept;

        constexpr Type realNumber() const noexcept { return realNum;}
        constexpr Type imaginaryNumber() const noexcept { return imaginaryNum;}
        constexpr double module() const noexcept;
        auto operator -() const noexcept;

        auto& print(std::ostream& os) const;
        auto& scanner(std::istream&);

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
    auto Complex<Type>::operator +(const Complex& c) const noexcept {
        return Complex{realNum + c.realNum, imaginaryNum + c.imaginaryNum};
    }

    template <typename Type>
    auto& Complex<Type>::operator +=(const Complex& c) noexcept {
        realNum += c.realNum;
        imaginaryNum += c.imaginaryNum;
        return *this;
    }

    template <typename Type>
    auto Complex<Type>::operator -(const Complex& c) const noexcept {
        return Complex{realNum - c.realNum, imaginaryNum - c.imaginaryNum};
    }

    template <typename Type>
    auto& Complex<Type>::operator -=(const Complex& c) noexcept {
        realNum -= c.realNum;
        imaginaryNum -= c.imaginaryNum;
        return *this;
    }

    template <typename Type>
    auto Complex<Type>::operator *(Type number) const noexcept {
        return Complex{realNum * number, imaginaryNum * number};
    };

    template <typename Type>
    auto& Complex<Type>::operator *=(Type number) noexcept {
            realNum *= number;
            imaginaryNum *= number;
            return *this;
}

    template <typename Type>
    constexpr double Complex<Type>::module() const noexcept {
        return sqrt(realNum * realNum + imaginaryNum * imaginaryNum);
    }

    template <typename Type>
    auto Complex<Type>::operator -() const noexcept {
        return Complex{realNum, -imaginaryNum};
    }

    template <typename Type>
    auto& Complex<Type>::print(std::ostream& os) const {
        return os << realNum <<  " " << sign << " " << std::abs(imaginaryNum) << 'i';
    }

    template <typename Type>
    auto& Complex<Type>::scanner(std::istream& is) {
        return is >> realNum >> imaginaryNum;
    }

    template <typename Type>
    std::ostream& operator <<(std::ostream& os, const Complex<Type>& c) {
        return c.print(os);
    }

    template <typename Type>
    std::istream& operator >>(std::istream& is, Complex<Type>& c) {
        return c.scanner(is);
    }

    template <typename T1, typename T2>
    Complex<T2> operator*(T1 number, const Complex<T2>& c) noexcept {
        return c * number;
    }

    template <typename Type>
    bool Complex<Type>::operator ==(const Complex<Type>& c) noexcept {
        return realNum == c.realNum && imaginaryNum == c.imaginaryNum;
    }

    template <typename Type>
    bool Complex<Type>::operator !=(const Complex<Type>& c) noexcept {
        return !(*this == c);
    }
}
#endif // COMPLEX_H
