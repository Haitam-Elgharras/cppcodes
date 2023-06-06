class complex
{
    double re, im;

public:
    int here;
    complex(double, double);
    double real();  // retourner la partie réelle
    double imag();  // retourner la partie imaginaire
    complex conj(); // the complex conjugate
    double norm();  // the square of the magnitude
    double arg();   // the angle of radians

    complex polar(double mag, double angle);
    complex operator+(complex);
    void operator=(complex Z);
    friend complex operator+(double, complex);
    friend complex operator+(complex, double);

    complex operator-(complex);
    friend complex operator-(double, complex);
    friend complex operator-(complex, double);

    complex operator*(complex);
    friend complex operator*(double, complex);
    friend complex operator*(complex, double);

    complex operator/(complex);
    friend complex operator/(double, complex);
    friend complex operator/(complex, double);
    complex operator-();
};

int operator==(complex, complex);
int operator!=(complex, complex);
