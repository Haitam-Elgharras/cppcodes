#include <iostream>
#include "complex.h"
#include <math.h>

complex::complex(double a, double b) : re(a), im(b)
{
}
double complex::real()
{
    return re;
}
// retourner la partie imaginaire
double complex::imag()
{
    return im;
}
// the complex conjugate
complex complex::conj()
{
    return complex(re, -im);
}
// the square of the magnitude
double complex::norm()
{
    return pow(pow(re, 2) + pow(im, 2), 0.5);
}
// the angle of radians
double complex::arg()
{
    return atan(im / re);
}

complex complex::polar(double mag, double angle = 0)
{
    return complex(mag * cos(angle), mag * sin(angle));
}
complex complex::operator+(complex Z)
{
    return complex(Z.re + re, Z.im + im);
}
/*
The first operator, complex operator+(complex Z, double a), allows adding a complex number Z and a double a in that order.
This means that you can write an expression like Z + a.

The second operator, complex operator+(double a, complex Z), allows adding a double a and a complex number Z in that order.
This means that you can write an expression like a + Z.
*/

complex operator+(complex Z, double a)
{
    return complex(Z.re + a, Z.im);
}
complex operator+(double a, complex Z)
{
    return complex(a + Z.re, Z.im);
}

complex complex::operator-(complex Z)
{
    return complex(re - Z.re, im - Z.im);
}
complex operator-(complex Z, double a)
{
    return complex(Z.re - a, Z.im);
}
complex operator-(double a, complex Z)
{
    return complex(a - Z.re, Z.im);
}

complex complex::operator*(complex Z)
{
    complex res(re * Z.re - im * Z.im, re * Z.im + im * Z.re);
    return res;
}
complex operator*(complex Z, double a)
{
    return complex(Z.re * a, Z.im * a);
}
complex operator*(double a, complex Z)
{
    return complex(a * Z.re, a * Z.im);
}

complex complex::operator/(complex Z)
{
    // return complex((this->re * Z.re + this->im * Z.im) / pow(Z.norm(), 2), (-this->re * Z.im + Z.re * this->im) / pow(Z.norm(), 2));

    complex res = (*this) * Z.conj() / pow(Z.norm(), 2);
    here = 10;
    return res;
}
complex operator/(complex Z, double a)
{
    return complex(Z.re / a, Z.im / a);
}
complex operator/(double a, complex Z)
{
    // return complex(a * Z.re, a * Z.im);
    complex res(0, 0);
    res = a * Z.conj() / Z.norm();
    return res;
}

// this an independent function it use just a public's methodes
int operator==(complex Z1, complex Z2)
{
    if (Z1.real() == Z2.real() && Z1.imag() == Z2.imag())
        return 1;
    return 0;
}

// this an independent function it use just a public's methodes
int operator!=(complex Z1, complex Z2)
{
    if (Z1 == Z2)
        return 0;
    return 1;
}

complex complex::operator-()
{
    return complex(-this->re, -this->im);
}

void complex::operator=(complex Z)
{
    this->re = Z.re;
    this->im = Z.im;
}
