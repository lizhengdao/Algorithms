#include <bits/stdc++.h>
using namespace std;
class Complex
{
  private:
    long double real; //real part
    long double imag; //imaginary part
  public:
    Complex()
    {
        real = 0;
        imag = 0;
    }
    Complex(long double r, long double i)
    {
        real = r;
        imag = i;
    }
    long double getReal()
    {
        return real;
    }
    long double getImag()
    {
        return imag;
    }
    Complex conjugate()
    {
        Complex c(real, -imag);
        return c;
    }
    long double modulus()
    {
        return sqrt((real * real) + (imag * imag));
    }
    Complex reciprocal()
    {
        long double mod = this->modulus();
        Complex C(real / mod, -imag / mod);
        return C;
    }
    Complex root()
    {
        long double mod = this->modulus();
        Complex C(sqrt((mod + real) / 2), sqrt((mod - real) / 2));
        return C;
    }
    //operators
    Complex operator+(Complex c2)
    {
        Complex C(real + c2.getReal(), imag + c2.getImag());
        return C;
    }
    Complex operator-(Complex c2)
    {
        Complex C(real - c2.getReal(), imag - c2.getImag());
        return C;
    }
    Complex operator*(Complex c2)
    {
        long double a = real, b = imag, c = c2.getReal(), d = c2.getImag();
        Complex C((a * c) - (b * d), (b * c) + (a * d));
        return C;
    }
    Complex operator/(Complex c2)
    {
        long double a = real, b = imag, c = c2.getReal(), d = c2.getImag(), mod = c2.modulus();
        Complex C(((a * c) + (b * d)) / mod, ((b * c) - (a * d)) / mod);
        return C;
    }
    bool operator==(Complex c2)
    {
        return ((real == c2.getReal()) && (imag == c2.getImag()));
    }
    //utility functions
    string toString()
    {
        stringstream s;
        s << real << " ";
        if (imag >= 0)
            s << "+ " << imag << "i";
        else if (imag < 0)
            s << "- " << -imag << "i";
        return s.str();
    }
};
Complex power(Complex c1, int n)
{
    Complex C(1, 0);
    while (n--)
    {
        C = C * c1;
    }
    return C;
}
int main()
{
    Complex c1(3, 2), c2(1, 7), c3;
    c3 = c1 + c2;
    cout << c3.toString() << "\n";
    c3 = c1 - c2;
    cout << c3.toString() << "\n";
    c3 = c1 * c2;
    cout << c3.toString() << "\n";
    c3 = c1 / c2;
    cout << c3.toString() << "\n";
    c3 = c1.reciprocal();
    cout << c3.toString() << "\n";
    c3 = c1.root();
    cout << c3.toString() << "\n";
    c3 = power(c1, 2);
    cout << c3.toString() << "\n";
}