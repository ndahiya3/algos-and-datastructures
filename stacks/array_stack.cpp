//#include "array_stack.h"
#include <assert.h>

template <class T>
arrayStack<T>::arrayStack(int maxSize) {
  if (maxSize > 0)
    maxStackSize = maxSize;
  stackTop = -1;
  list = new T[maxStackSize];
}

template <class T>
arrayStack<T>::arrayStack(const arrayStack<T> &otherStack) {
  list = nullptr;
  copyStack(otherStack);
}

template <class T>
arrayStack<T>::~arrayStack() {
  if (list != nullptr)
    delete[] list;
  list = nullptr;
  //stackTop = -1;
}

template <class T>
const arrayStack<T>& arrayStack<T>::operator =(const arrayStack<T> &otherStack) {
  if (this != &otherStack)    // Avoid self copy
    copyStack(otherStack);
  return *this;
}

template <class T>
void arrayStack<T>::initialize_stack() {
  stackTop = -1;
}

template <class T>
bool arrayStack<T>::is_empty() const {
  return (stackTop == -1);
}

template <class T>
void arrayStack<T>::push(const T &data) {
  list[++stackTop] = data;
  // To Do: Implement resizing array
}

template <class T>
void arrayStack<T>::pop() {
  assert(stackTop != -1);
  stackTop--;
  // To Do: Implement resizing array
}

template <class T>
T arrayStack<T>::top() const {
  assert(stackTop != -1);
  return list[stackTop];
}

























