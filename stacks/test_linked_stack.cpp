#include "linked_stack.h"
#include <iostream>
using namespace std;

void test_linked_stack() {
  linkedStack<float> stack;

  for (int i = 1; i < 11; i++)
    stack.push(i * 0.8);
  while (!stack.is_empty()) {
    cout << stack.top() << ' ';
    stack.pop();
  }
  cout << endl;
  stack.pop();
}

void test_constructors() {

  // Test copy constructor and assignment operator
  linkedStack<int> stack;
  for (int i = 1; i < 11; i++)
    stack.push(i);

  linkedStack<int> stack2 = stack;

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
  // test_linked_stack();

  test_constructors();
  return 0;
}
