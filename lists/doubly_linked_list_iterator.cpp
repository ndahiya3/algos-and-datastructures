//#include "doubly_linked_list_iterator.h"

template <class T> doublyLinkedListIterator<T>::doublyLinkedListIterator() {
  current = nullptr;
}

template <class T>
doublyLinkedListIterator<T>::doublyLinkedListIterator(nodeD<T> *ptr) {
  current = ptr;
}

template <class T> T doublyLinkedListIterator<T>::operator*() {
  return current->data;
}

template <class T>
doublyLinkedListIterator<T> doublyLinkedListIterator<T>::operator++() {
  current = current->next;
  return *this;
}

template <class T>
doublyLinkedListIterator<T> doublyLinkedListIterator<T>::operator--() {
  current = current->prev;
  return *this;
}

template <class T>
bool doublyLinkedListIterator<T>::
operator==(const doublyLinkedListIterator<T> &right) const {
  return (current == right.current);
}

template <class T>
bool doublyLinkedListIterator<T>::
operator!=(const doublyLinkedListIterator<T> &right) const {
  return (current != right.current);
}
