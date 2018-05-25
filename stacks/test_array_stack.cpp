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

void test_resizing_array_constructors() {

  // Test copy constructor and assignment operator
  arrayStack<int> stack(5);
  for (int i = 1; i < 11; i++)
    stack.push(i);

  arrayStack<int> stack2 = stack;

  cout << "Testing copy constructor: " << endl;
  cout << "Original stack: Size: " << stack.size()
       << " Capacity: " << stack.capacity() << endl;
  while (!stack.is_empty()) {
    cout << stack.top() << " ";
    stack.pop();
  }
  cout << endl;
  cout << "Copy stack: Size" << stack2.size()
       << " Capacity: " << stack2.capacity() << endl;
  while (!stack2.is_empty()) {
    cout << stack2.top() << " ";
    stack2.pop();
  }
  cout << endl;

  cout << "Testing assignment operator: " << endl;
  for (int i = 1; i < 11; i++)
    stack.push(i);
  for (int i = 11; i < 21; i++)
    stack2.push(i);
  cout << "Stack1: ";
  while (!stack.is_empty()) {
    cout << stack.top() << " ";
    stack.pop();
  }
  cout << endl;

  cout << "Stack2: ";
  while (!stack2.is_empty()) {
    cout << stack2.top() << " ";
    stack2.pop();
  }
  cout << endl;

  for (int i = 1; i < 11; i++)
    stack.push(i);
  for (int i = 11; i < 21; i++)
    stack2.push(i);
  stack2 = stack;

  cout << "Stack2 after assignment = stack1 : ";
  while (!stack2.is_empty()) {
    cout << stack2.top() << " ";
    stack2.pop();
  }
  cout << endl;
}
int main(int argc, char *argv[]) {
  // test_array_stack();
  // test_resizing_array_stack();
  test_resizing_array_constructors();
  return 0;
}
