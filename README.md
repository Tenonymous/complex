# complex
my complex impl in c++11/14

1. List of consturctors:
```cpp
constexpr Complex(Type real = {}, Type imaginary = {}) noexcept;
Complex(Complex&&) = default;
Complex(const Complex&) = default;
```

2. Member operator:
```cpp
auto operator +(const Complex&) const noexcept;
auto& operator +=(const Complex&) noexcept;
auto operator -(const Complex&) const noexcept;
auto& operator -=(const Complex&) noexcept;
auto operator *(Type number) const noexcept;
auto& operator *=(Type number) noexcept;

constexpr bool operator ==(const Complex&) const noexcept;
constexpr bool operator !=(const Complex&) const noexcept;
```

3. Non-member operator:
```cpp
template <typename Type>
std::ostream& operator <<(std::ostream&, const Complex<Type>&);

template <typename Type>
std::istream& operator >>(std::istream&, Complex<Type>&);

template <typename T1, typename T2>
auto operator*(T1, const Complex<T2>&) noexcept;
```