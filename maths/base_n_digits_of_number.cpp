/*
 * Find digits of a decimal number in any given base n
 */
#include <iostream>
#include <list>
using namespace std;

void base_n_digits_of_number(int input, int base, list<int>& digits)
{
  if (input < 0)
    input *= -1;
  if (input == 0)
    digits.push_front(0);
  while (input > 0)
    {
      int remainder = input % base;
      digits.push_front(remainder);
      input /= base;
    }
}

void print_digits(const list<int>& digits)
{
  for (list<int>::const_iterator it = digits.begin(); it != digits.end(); it++)
    cout << *it << ' ';
  cout << endl;
}

int main()
{
  // Test decimal base
  int input = 1234567890;
  int base = 10;

  list<int> digits;
  base_n_digits_of_number(input, base, digits);

  cout << "Expected output: 1 2 3 4 5 6 7 8 9 0" << endl;
  cout << "Program output:  ";
  print_digits(digits);

  // Test binary base
  digits.clear();
  input = -289;
  base = 2;
  base_n_digits_of_number(input, base, digits);
  cout << "Expected output: 1 0 0 1 0 0 0 0 1" << endl;
  cout << "Program output:  ";
  print_digits(digits);

  // Test hexadecimal base
  digits.clear();
  input = 300;
  base = 16;
  base_n_digits_of_number(input, base, digits);
  cout << "Expected output: 1 2 12" << endl;
  cout << "Program output:  ";
  print_digits(digits);

  return 0;
}
