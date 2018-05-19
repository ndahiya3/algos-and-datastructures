#include "linked_list_iterator.h"

template <class T>
linkedListIterator<T>::linkedListIterator() {
  current = nullptr;
}

template <class T>
linkedListIterator<T>::linkedListIterator(nodeS<T> *ptr) {
  current = ptr;
}

template <class T>
T linkedListIterator<T>::operator*() {
  return current->data;
}

template <class T>
linkedListIterator<T> linkedListIterator<T>::operator ++(){
  current = current->next;
  return *this;
}

template <class T>
bool linkedListIterator<T>::operator ==(const linkedListIterator<T>& right) const {
  return (current == right.current);
}

template <class T>
bool linkedListIterator<T>::operator !=(const linkedListIterator<T>& right) const {
  return (current != right.current);
}
