//#include "linked_stack.h"
#include <assert.h>

template <class T> linkedStack<T>::linkedStack() { list.initialize_list(); }

template <class T>
linkedStack<T>::linkedStack(const linkedStack<T> &otherStack) {
  list = otherStack.list;
}

template <class T> linkedStack<T>::~linkedStack() { list.destroy_list(); }

template <class T>
const linkedStack<T> &linkedStack<T>::
operator=(const linkedStack<T> &otherStack) {
  if (this != &otherStack)
    copyStack(otherStack);
  return *this;
}

template <class T> void linkedStack<T>::initialize_stack() {
  list.initialize_list();
}

template <class T> bool linkedStack<T>::is_empty() const {
  return list.is_empty_list();
}

template <class T> int linkedStack<T>::capacity() const { return 1000000; }

template <class T> int linkedStack<T>::size() const { return list.length(); }

template <class T> void linkedStack<T>::push(const T &data) {
  list.insert_front(data);
}

template <class T> void linkedStack<T>::pop() {
  assert(is_empty() == false);
  list.delete_front();
}

template <class T> T linkedStack<T>::top() const { return list.front(); }

template <class T>
void linkedStack<T>::copyStack(const linkedStack<T> &otherStack) {
  list = otherStack.list;
}
