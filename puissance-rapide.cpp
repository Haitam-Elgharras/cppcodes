#include <iostream>
#include <chrono>
//Mesure expérimentale en c++
unsigned long long pow_recursive(unsigned long long a, unsigned long long n) {
  if (n == 0) {
    return 1;
  }

  unsigned long long b = pow_recursive(a, n / 2);

  if (n % 2 == 0) {
    return b * b;
  } else {
    return a * b * b;
  }
}
unsigned long long pow2_recursive(unsigned long long a, unsigned long long n) {
  if (n == 0) {
    return 1;
  }
else {return a*pow2_recursive(a,n-1);}
}

int main() {
  unsigned long long a, n;
  std::cout << "Enter the base number: ";
  std::cin >> a;
  std::cout << "Enter the exponent: ";
  std::cin >> n;
 


  auto start = std::chrono::high_resolution_clock::now();
  unsigned long long result = pow_recursive(a, n);
  auto end = std::chrono::high_resolution_clock::now();
 

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << a << "^" << n << " = " << result << std::endl;   
  std::cout << "Time spent with the O(log2(n)): " << duration.count() << " microseconds" << std::endl;


   auto start2 = std::chrono::high_resolution_clock::now();
  unsigned long long result2 = pow2_recursive(a, n);
  auto end2 = std::chrono::high_resolution_clock::now();

   auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);
  std::cout << a << "^" << n << " = " << result2 << std::endl;   
  std::cout << "Time spent with the O(n): " << duration2.count() << " microseconds" << std::endl;

  return 0;
}
