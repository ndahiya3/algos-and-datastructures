/*
 * Find all factors of n
 */
#include <iostream>
#include <math.h>
#include <list>
using namespace std;

void factors_of_n(int n, list<int> &factors)
{
  factors.clear();
  if (n < 1)
    return;
  factors.push_front(1);
  if (n == 1)
    return;

  for (int i = 2; i <= sqrt(n); i++)
    {
      if (n % i == 0)
        {
          factors.push_front(i);
          if (i != sqrt(n))
            factors.push_front(n / i);
        }
    }
  factors.push_back(n);
  factors.sort();
}

void print_factors(const list<int> &factors)
{
  for (list<int>::const_iterator it = factors.begin(); it != factors.end(); it++)
    cout << *it << ", ";
  cout << endl;
}

int main()
{
  int n = 36;

  list<int> factors;
  factors_of_n(n, factors);

  cout << "Expected output: 1, 2, 3, 4, 6, 9, 12, 18, 36" << endl;
  cout << "Program output:  ";
  print_factors(factors);

  return 0;
}
