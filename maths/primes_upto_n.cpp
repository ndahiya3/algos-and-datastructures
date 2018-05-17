/*
 * Find all primes upto n
 */
#include <iostream>
#include <math.h>
#include <string>
#include <list>
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

void primes_upto_n(int n, list<int>& primes)
{
  primes.clear();
  for (int i = 2; i <= n; i++)
    {
      if (is_prime(i))
        primes.push_back(i); // Push to back not front for correct order
    }
}

void primes_upto_n_sieve_of_erastosthenes(int n, list<int> &primes)
{
  // Efficient algorithm. Mulitples of a prime cannot be a prime
  // So strike them out
  bool *Primes = new bool[n + 1];

  for (int i = 0; i < n + 1; i++)
    Primes[i] = true;
  Primes[0] = false;
  Primes[1] = false;

  for (int i = 2; i <= sqrt(n); i++)
    {
      if (Primes[i] == true)
        {
          // strike of all multilples of this prime
          for (int j = i + i; j <= n; j += i)
            Primes[j] = false;
        }
    }
  for (int i = 0; i < n + 1; i++)
    if (Primes[i] == true)
      primes.push_back(i);
  delete[] Primes;
}

void print_primes(const list<int> &primes)
{
  for (list<int>::const_iterator it = primes.begin(); it != primes.end(); it++)
    cout << *it << ", ";
  cout << endl;
}

int main()
{
  int n = 100;

  list<int> primes;
  //primes_upto_n(n, primes);
  primes_upto_n_sieve_of_erastosthenes(n, primes);

  cout << "Expected output: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97" << endl;
  cout << "Program output:  ";
  print_primes(primes);
}
