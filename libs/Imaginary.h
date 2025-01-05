#ifndef _IMAGINARY_H_
#define _IMAGINARY_H_

#include <iostream>

class Imaginary {
public:
    double re;
    double im;

    Imaginary();

    Imaginary(double re, double im);

    double module();
    Imaginary conjugate();
    Imaginary norm();
    Imaginary operator+(double a);
    Imaginary operator-(double a);
    Imaginary operator*(double a);
    Imaginary operator/(double a);

    Imaginary operator++();
    Imaginary operator++(int a);

    Imaginary operator--();
    Imaginary operator--(int a);

    double operator[](int n);

};

Imaginary operator+(Imaginary a, Imaginary b);
Imaginary operator-(Imaginary a, Imaginary b);
Imaginary operator-(double a, Imaginary b);
Imaginary operator*(Imaginary a, Imaginary b);
Imaginary operator*(double a, Imaginary b);
Imaginary operator/(Imaginary a, Imaginary b);
Imaginary operator/(double a, Imaginary b);

bool operator==(Imaginary a, Imaginary b);
bool operator<=(Imaginary a, Imaginary b);
bool operator>=(Imaginary a, Imaginary b);
bool operator!=(Imaginary a, Imaginary b);
bool operator<(Imaginary a, Imaginary b);
bool operator>(Imaginary a, Imaginary b);

Imaginary expi(Imaginary z);
Imaginary discreteFourierTransform(double f, double Ft[], int smapleLen);

std::ostream& operator<<(std::ostream &stream, Imaginary &k);

#endif
