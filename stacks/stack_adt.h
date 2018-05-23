#ifndef STACK_ADT_H
#define STACK_ADT_H

/*
 * Abstract base class for stack datastructure.
 */

template <class T> class stackADT {
public:
  virtual void initialize_stack() = 0;  // Initialize empty stack
  virtual bool is_empty() const = 0;    // Determine if stack is empty
  virtual int capacity() const = 0;     // Current max capacity of stack
  virtual int size() const = 0;         // Current size of stack
  virtual void push(const T &data) = 0; // Push element on stack
  virtual void pop() = 0;               // Remove top element
  virtual T top() const = 0;            // Return top element without removing
};
#endif // STACK_ADT_H
