/*
 * Find the prime factorization of n
 */

#include <iostream>
#include <math.h>
using namespace std;

void prime_factors(int n)
{
  if (n <= 1)
    return;
  int sqrt_n = sqrt(n);
  for (int i = 2; i < sqrt_n; i++)
    {
      if (n % i == 0)
        {
          int cnt = 0;
          while (n % i == 0)
            {
              n /= i;
              cnt++;
            }
          cout << i << ", " << cnt << endl;
        }
    }
  if (n != 1)
    cout << n << ", 1" << endl;
}

int main()
{
  int n = 36;

  cout << "Expected output: " << endl;
  cout << "2, 2\n3, 2" << endl;

  cout << "Program output:  " << endl;
  prime_factors(n);

  return 0;
}
