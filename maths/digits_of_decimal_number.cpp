/*
 * Given an input integer, get a list of its individual
 * digits.
 */
#include <iostream>
#include <list>
using namespace std;

void get_digits_of_number(int input, list<int> & digits)
{
  if (input == 0)
    {
      digits.push_front(0);
      return;
    }
  if (input < 0)
    input *= -1;

  while (input > 0)
    {
      int remainder = input % 10;
      digits.push_front(remainder);
      input = input / 10;
    }
}

void print_digits(const list<int> & digits)
{
  for (list<int>::const_iterator it = digits.begin(); it != digits.end(); it++)
    cout << *it << ' ';
  cout << endl;
}
int main()
{
  int input = 1234567890;

  list<int> digits;
  get_digits_of_number(input, digits);

  cout << "Expected output: 1 2 3 4 5 6 7 8 9 0" << endl;
  cout << "Program output:  ";
  print_digits(digits);

  digits.clear();
  input = -238745;
  get_digits_of_number(input, digits);
  cout << "Expected output: 2 3 8 7 4 5" << endl;
  cout << "Program output:  ";
  print_digits(digits);

  digits.clear();
  input = 0;
  get_digits_of_number(input, digits);
  cout << "Expected output: 0" << endl;
  cout << "Program output:  ";
  print_digits(digits);

  return 0;
}
