#include <iostream>

class Complex 
{

private:
    double real;
    double imaginary;

public:
    Complex() : real(0), imaginary(0)
    {

    }

    Complex(double real, double imaginary) : real(real), imaginary(imaginary)
    {

    }

    Complex(const Complex &other)
    {
        real = other.real;
        imaginary = other.imaginary;
    }

    const Complex &operator=(const Complex &other)
    {
        real = other.real;
        imaginary = other.imaginary;

        return *this;
    }

    double getReal() const
    {
        return real;
    }

    double getImaginary() const
    {
        return imaginary;
    }
};

 std::ostream &operator<<(std::ostream &out, Complex &c)
{
    out << "(" << c.getReal() << ", " << c.getImaginary() << ")";
    return out;
}

Complex operator+(const Complex &c1, const Complex &c2)
{
    return Complex(c1.getReal()+c2.getReal(), c1.getImaginary()+c2.getImaginary());
}

Complex operator+(const Complex &c1, double d)
{
    return Complex(c1.getReal()+d, c1.getImaginary()+d);
}

Complex operator+(double d, const Complex &c2)
{
    return Complex(d+c2.getReal(), d+c2.getImaginary());
}

int main()
{
    Complex c1(3, 4);
    Complex c2(2, 3);

    Complex c3 = c1+c2;

    //std::cout << c1+c2+c3 << std::endl;

    Complex c4(4, 2);
    Complex c5 = c4+7;
    std::cout << c5 << std::endl;

    Complex c6(1, 7);

    c6 = 7+9+8+c1+c2;

    std::cout << 3.2 + c6 << std::endl;

    return 0;
}