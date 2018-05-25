#include "array_stack.h"
#include <assert.h>

template <class T> arrayStack<T>::arrayStack(int maxSize) {
  if (maxSize > 0)
    maxStackSize = maxSize;
  stackTop = -1;
  list = new T[maxStackSize];
}

template <class T> arrayStack<T>::arrayStack(const arrayStack<T> &otherStack) {
  list = nullptr;
  copyStack(otherStack);
}

template <class T> arrayStack<T>::~arrayStack() {
  if (list != nullptr)
    delete[] list;
  list = nullptr;
  // stackTop = -1;
}

template <class T>
const arrayStack<T> &arrayStack<T>::operator=(const arrayStack<T> &otherStack) {
  if (this != &otherStack) // Avoid self copy
    copyStack(otherStack);
  return *this;
}

template <class T> void arrayStack<T>::initialize_stack() { stackTop = -1; }

template <class T> bool arrayStack<T>::is_empty() const {
  return (stackTop == -1);
}

template <class T> int arrayStack<T>::capacity() const { return maxStackSize; }

template <class T> int arrayStack<T>::size() const { return (stackTop + 1); }

template <class T> void arrayStack<T>::push(const T &data) {
  if (stackTop == maxStackSize - 1)
    resizeStack(2 * maxStackSize);

  list[++stackTop] = data;
}

template <class T> void arrayStack<T>::pop() {
  assert(stackTop != -1);

  if (stackTop == maxStackSize / 4)
    resizeStack(maxStackSize / 2);

  stackTop--;
  // To Do: Implement resizing array
}

template <class T> T arrayStack<T>::top() const {
  assert(stackTop != -1);
  return list[stackTop];
}

template <class T> void arrayStack<T>::resizeStack(int new_size) {
  T *new_array = new T[new_size];
  for (int i = 0; i <= stackTop; i++)
    new_array[i] = list[i];
  delete[] list;
  list = new_array;
  maxStackSize = new_size;
}

template <class T>
void arrayStack<T>::copyStack(const arrayStack<T> &otherStack) {
  initialize_stack();
  if (otherStack.is_empty())
    return;
  maxStackSize = otherStack.maxStackSize;
  stackTop = otherStack.stackTop;
  delete[] list;
  list = new T[maxStackSize];

  for (int i = 0; i <= stackTop; i++)
    list[i] = otherStack.list[i];
}
