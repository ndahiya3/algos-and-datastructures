#ifndef DOUBLY_LINKED_LIST_ITERATOR_H
#define DOUBLY_LINKED_LIST_ITERATOR_H
/*
 * Iterator class for a doubly linked list
 * Provides:
 * default constructor          O(1)
 * constructor with node ptr    O(1)
 * operator*                    O(1)
 * operator++                   O(1)
 * operator--                   O(1)
 * operator==                   O(1)
 * operator!=                   O(1)
 */

#include "node_d.h"

template <class T> class doublyLinkedListIterator {
public:
  doublyLinkedListIterator();               // Default constructor
  doublyLinkedListIterator(nodeD<T> *ptr);  // Constructor at location ptr
  T operator*();                            // Dereference a node value
  doublyLinkedListIterator<T> operator++(); // Overloaded pre increment operator
  doublyLinkedListIterator<T> operator--(); // Overloaded pre decrement operator
  // Equality operator
  bool operator==(const doublyLinkedListIterator<T> &right) const;
  // Not equal operator
  bool operator!=(const doublyLinkedListIterator<T> &right) const;

private:
  nodeD<T> *current;
};
#include "doubly_linked_list_iterator.cpp"

#endif // DOUBLY_LINKED_LIST_ITERATOR_H
