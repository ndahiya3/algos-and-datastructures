/*
 * Check if a number is prime or not
 */

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

bool is_prime(int n)
{
  if (n < 2)
    return false;
  for (int i = 2; i <= sqrt(n); i++)
    {
      if (n % i == 0)
        return false;
    }
  return true;
}

void print_output(bool prime_or_not, string expected_output)
{
  cout << "Expected output: " << expected_output << endl;
  cout << "Program output:  ";
  if (prime_or_not)
    cout << "Is prime" << endl;
  else
    cout << "Not prime" << endl;
}
int main()
{
  string pos_output = "Is prime";
  string neg_output = "Not prime";

  int n = 0;
  bool prime = is_prime(n);

  print_output(prime, neg_output);

  n = 1;
  prime = is_prime(n);
  print_output(prime, neg_output);

  n = 2;
  prime = is_prime(n);
  print_output(prime, pos_output);

  n = 17;
  prime = is_prime(n);
  print_output(prime, pos_output);

  n = 20;
  prime = is_prime(n);
  print_output(prime, neg_output);

  n = 157;
  prime = is_prime(n);
  print_output(prime, pos_output);

  return 0;
}
