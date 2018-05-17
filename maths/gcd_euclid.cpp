/*
 * Find the GCD of two numbers using Euclid's algorithm
 */

#include <iostream>
#include <math.h>
using namespace std;

int gcd_euclid(int a, int b)
{
  int divisor = a;
  int dividend = b;

  while (divisor != 0)
    {
      int remainder = dividend % divisor;
      dividend = divisor;
      divisor = remainder;
    }
  return dividend;
}

int main()
{
  int a = 105;
  int b = 350;

  cout << "GCD = " << gcd_euclid(a, b) << endl;

  return 0;
}
