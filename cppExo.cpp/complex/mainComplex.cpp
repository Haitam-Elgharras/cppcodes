#include <iostream>
#include "complex.h"

using namespace std;
int main()
{
    complex z1(1, 2), z2(3, 4);

    // Addition
    complex z3 = z1 + z2;
    std::cout << "z1 + z2 = " << z3.real() << " + " << z3.imag() << "i" << std::endl;
    // Expected output: z1 + z2 = 4 + 6i

    // Subtraction
    z3 = z1 - z2;
    std::cout << "z1 - z2 = " << z3.real() << " + (" << z3.imag() << ")i" << std::endl;
    // Expected output: z1 - z2 = -2 - 2i

    // Multiplication
    z3 = z1 * z2;
    std::cout << "z1 * z2 = " << z3.real() << " + " << z3.imag() << "i" << std::endl;
    // Expected output: z1 * z2 = -5 + 10i

    // Division
    z3 = z1 / z2;
    std::cout << "z1 / z2 = " << z3.real() << " + " << z3.imag() << "i" << std::endl;
    // Expected output: z1 / z2 = 0.44 - 0.08i

    // Unary negation
    z3 = -z1;
    std::cout << "-z1 = " << z3.real() << " + " << z3.imag() << "i" << std::endl;
    // Expected output: -z1 = -1 - 2i

    // Equality
    std::cout << "z1 == z2? " << (z1 == z2) << std::endl;
    // Expected output: z1 == z2? 0

    // Inequality
    std::cout << "z1 != z2? " << (z1 != z2) << std::endl;
    // Expected output: z1 != z2? 1

    return 0;
}
