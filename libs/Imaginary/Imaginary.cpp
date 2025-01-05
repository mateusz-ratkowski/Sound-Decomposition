#include "Imaginary.h"
#include <cmath>



Imaginary::Imaginary()  {
        re = 0;
        im = 0;
}

Imaginary::Imaginary(double re, double im)  {
        this -> re = re;
        this -> im = im;
}

double Imaginary::module() {
    return sqrt(this->re * this->re + this->im * this->im);
}

Imaginary Imaginary::conjugate() {
    Imaginary c = *this;
    c.im = -c.im;
    return c;
}

Imaginary Imaginary::norm() {
    return *this / this->module();
}







//dodawanie
Imaginary operator+(Imaginary a, Imaginary b) {
    Imaginary c;
    c.re = a.re + b.re;
    c.im = a.im + b. im;
    return c;
}

Imaginary Imaginary::operator+(double s) {
    return *this + Imaginary(s, 0);
}

Imaginary operator+(double s, Imaginary b) {
    return Imaginary(s, 0) + b;
}







//odejmowanie
Imaginary operator-(Imaginary a, Imaginary b) {
    Imaginary c;
    c.re = a.re - b.re;
    c.im = a.im - b. im;

    return c;
}

Imaginary Imaginary::operator-(double s) {
    return *this - Imaginary(s, 0);
}

Imaginary operator-(double s, Imaginary b) {
    return Imaginary(s, 0) - b;
}







//mnożenie
Imaginary operator*(Imaginary a, Imaginary b) {
    Imaginary c;

    c.re = a.re * b.re - (a.im * b.im);
    c.im = a.re * b.im + b.re * a.im;

    return c;
}

Imaginary Imaginary::operator*(double s) {
    return *this * Imaginary(s, 0);
}

Imaginary operator*(double s, Imaginary b) {
    return b * Imaginary(s, 0);
}









//dzielenie
Imaginary operator/(Imaginary a, Imaginary b) {
    Imaginary c;

    if (b.re == 0 && b.im == 0) return Imaginary(0, 0);

    if (b.im == 0) {
        c.re = a.re / b.re;
        c.im = a.im / b.re;
        return c;
    }

    Imaginary denominator = (b * b.conjugate());


    c = (a * b.conjugate()) / denominator;

    return c;
}

Imaginary Imaginary::operator/(double s) {
    return *this / Imaginary(s, 0);
}

Imaginary operator/(double s, Imaginary b) {
    return Imaginary(s, 0) / b;
}






//++ zwiększa im i re równomiernie tak że moduł liczby zostaje zwiększony o 1, do tego wykorzystuje rozwiązania równania kwadratowego
Imaginary Imaginary::operator++() {
    double translation = ( -(this->re + this->im) + sqrt( (this->re + this-> im) * (this-> re + this-> im) + 4 * (this->module() + 0.5) ) ) / 2;
    return *this = Imaginary(this->re + translation, this-> im + translation);
}

Imaginary Imaginary::operator++(int a) {
    Imaginary c = *this;
    double translation = ( -(this->re + this->im) + sqrt( (this->re + this-> im) * (this-> re + this-> im) + 4 * (this->module() + 0.5) ) ) / 2;
    *this = Imaginary(this->re + translation, this-> im + translation);
    return c;
}







//- zmniejsza im i re równomiernie tak że moduł liczby zostaje zmniejszony o 1, do tego wykorzystuję postać trygonometryczną liczby zespolonej
Imaginary Imaginary::operator--() {
    double r = sqrt(this->re * this->re + this->im * this->im);

    if (r <= 1) {
        return Imaginary(0, 0);
    }

    double angle = atan2(this->im, this->re);

    double a = (r - 1) * cos(angle);
    double b = (r - 1) * sin(angle);
    return *this = Imaginary(a, b);
}

Imaginary Imaginary::operator--(int a) {
    Imaginary c = *this;
    double r = sqrt(this->re * this->re + this->im * this->im);

    if (r <= 1) {
        return Imaginary(0, 0);
    }

    double angle = atan2(this->im, this->re);

    this->re = (r - 1) * cos(angle);
    this->im = (r - 1) * sin(angle);
    return c;
}






//porównywanie po module
bool operator==(Imaginary a, Imaginary b) {
    return a.module() == b.module();
}

bool operator<=(Imaginary a, Imaginary b) {
    return a.module() <= b.module();
}

bool operator>=(Imaginary a, Imaginary b) {
    return a.module() >= b.module();
}

bool operator!=(Imaginary a, Imaginary b) {
    return a.module() != b.module();
}

bool operator<(Imaginary a, Imaginary b) {
    return a.module() < b.module();
}

bool operator>(Imaginary a, Imaginary b) {
    return a.module() > b.module();
}





//[]
double Imaginary::operator[](int n) {
    if (n == 0) {
        return this->re;
    }   else if (n == 1) {
        return this->im;
    }   else {
        return 0;
    }
}




Imaginary expi(Imaginary z) {
    double x = exp(z.re);
    Imaginary z1 = Imaginary(x * cos(z.im), sin(z.im) * x);
    return z1;
}

Imaginary discreteFourierTransform(double f, double Ft[], int sampleLen) {
    Imaginary sum(0, 0);
    for (int i = 0; i < sampleLen; i += 20) {
        sum = sum + Ft[i] * expi(Imaginary(0, -2 * M_PI * f * (i / (double)sampleLen)));
    }
    return sum;
}



//cout
std::ostream& operator<<(std::ostream &stream, Imaginary &k) {
    stream << k.re << " + " << k.im << "i";
    return stream;
}


