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

    bool operator==(const Complex &other) const
    {
        return (real == other.real) && (imaginary == other.imaginary);
    }

    bool operator!=(const Complex &other) const
    {
        return !(*this==other);
    }

    Complex operator*() const
    {
        return Complex(real, -imaginary);
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
    Complex c2 = *c1 + Complex(4, 3);
    std::cout << c2 << std::endl;
    
    return 0;
}