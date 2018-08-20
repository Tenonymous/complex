#ifndef COMPLEX_H
#define COMPLEX_H


namespace cmpx {
    template <typename T>
    class Complex
    {
    public:
        constexpr Complex(T real = {}, T imaginary = {}) noexcept;
        ~Complex();
        Complex(Complex&&) = default;
        Complex& operator =(Complex&&) = default;

        Complex(const Complex&) = default;
        Complex& operator =(const Complex&) = default;

    private:
        T realNum;
        T imaginaryNum;
    };

}
#endif // COMPLEX_H
