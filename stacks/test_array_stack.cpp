#include "array_stack.h"
#include <iostream>
using namespace std;

void test_array_stack() {
  arrayStack<float> stack;

  for (int i = 1; i < 11; i++)
    stack.push(i * 0.8);
  while (!stack.is_empty()) {
    cout << stack.top() << ' ';
    stack.pop();
  }
  cout << endl;
  stack.pop();
}

void test_resizing_array_stack() {
  arrayStack<int> stack(5);
  for (int i = 1; i < 11; i++) {
    cout << "Curr. num elems: " << stack.size()
         << " Max stack size: " << stack.capacity() << endl;
    stack.push(i);
  }
  cout << "Curr. num elems: " << stack.size()
       << " Max stack size: " << stack.capacity() << endl;

  cout << " Now deleting:   \n";
  for (int i = 1; i < 11; i++) {
    cout << "Curr. num elems: " << stack.size()
         << " Max stack size: " << stack.capacity() << endl;
    stack.pop();
  }
  cout << "Curr. num elems: " << stack.size()
       << " Max stack size: " << stack.capacity() << endl;

  cout << " Now Adding again:   \n";

  for (int i = 1; i < 101; i++) {
    cout << "Curr. num elems: " << stack.size()
         << " Max stack size: " << stack.capacity() << endl;
    stack.push(i);
  }
  cout << "Curr. num elems: " << stack.size()
       << " Max stack size: " << stack.capacity() << endl;
}

int main(int argc, char *argv[]) {
  // test_array_stack();
  test_resizing_array_stack();
  return 0;
}
