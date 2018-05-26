#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
/*
 * Unordered singly linked list based stack implementation
 * derived from stack ADT base class.
 *
 * Implements:
 * initialize_stack       O(n)
 * is_empty               O(1)
 * capacity               O(1)
 * size                   O(1)
 * push                   O(1)
 * pop                    O(1)
 * top                    O(1)
 * Assignment             O(n)
 * Default constructor    O(1)
 * Copy constructor       O(n)
 * Destructor             O(n)
 */

#include "stack_adt.h"
#include "unordered_linked_list.h"

template <class T> class linkedStack : public stackADT<T> {
public:
  void initialize_stack();  // Initialize empty stack
  bool is_empty() const;    // Determine if stack is empty
  int capacity() const;     // Current max capacity of stack
  int size() const;         // Current size of stack
  void push(const T &data); // Push element on stack
  void pop();               // Remove top element
  T top() const;            // Return top element without removing
  linkedStack();            // Default constructor
  linkedStack(const linkedStack<T> &otherStack); // Copy constructor
  ~linkedStack();                                // Destructor
  const linkedStack<T> &
  operator=(const linkedStack<T> &otherStack); // Assignment operator

private:
  void copyStack(const linkedStack<T>
                     &otherStack); // Copy other stack and assign to this stack
  unorderedLinkedList<T> list;
};
#include "linked_stack.cpp"
#endif // LINKEDSTACK_H
