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

int main()
{
    Complex c1(2, 3);
    Complex c2(c1);

    c1 = c2;

    Complex c3 = c2;

    std::cout << c1 << ": " << c3 << std::endl;

    return 0;
}