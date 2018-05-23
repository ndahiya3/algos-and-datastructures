#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
/*
 * Array based stack implementation derived from satck ADT
 * base class.
 *
 * Implements:
 * initialize_stack       O(1)
 * is_empty               O(1)
 * capacity               O(1)
 * size                   O(1)
 * push                   O(1)
 * pop                    O(1)
 * top                    O(1)
 * Assignment             O(n)
 * Default constructor    O(1)
 * Copy constructor       O(n)
 * Destructor             O(1)
 */

#include "stack_adt.h"
template <class T> class arrayStack : public stackADT<T> {
public:
  void initialize_stack();       // Initialize empty stack
  bool is_empty() const;         // Determine if stack is empty
  int capacity() const;          // Current max capacity of stack
  int size() const;              // Current size of stack
  void push(const T &data);      // Push element on stack
  void pop();                    // Remove top element
  T top() const;                 // Return top element without removing
  arrayStack(int maxSize = 100); // Default constructor
  arrayStack(const arrayStack<T> &otherStack); // Copy constructor
  ~arrayStack();                               // Destructor
  const arrayStack<T> &
  operator=(const arrayStack<T> &otherStack); // Assignment operator

private:
  int maxStackSize; // Maximum size of the stack
  int stackTop;     // Top of the stack
  T *list;          // Pointer to array that holds stack data
  void copyStack(const arrayStack<T>
                     &otherStack); // Copy other stack and assign to this stack
  void resizeStack(int new_size);  // Resize stack
};
#include "array_stack.cpp"
#endif // ARRAY_STACK_H
