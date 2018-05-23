#include "array_stack.h"
#include <iostream>
using namespace std;

void test_array_stack() {
  arrayStack<float> stack;

  for(int i = 1; i< 11; i++)
    stack.push(i*0.8);
  while (!stack.is_empty()) {
      cout << stack.top() << ' ';
      stack.pop();
    }
  cout << endl;
  stack.pop();
}

int main(int argc, char *argv[])
{
  test_array_stack();
  return 0;
}
