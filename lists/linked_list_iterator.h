#ifndef LINKED_LIST_ITERATOR_H
#define LINKED_LIST_ITERATOR_H
/*
 * Singly linked list iterator class
 * Provides:
 * default constructor          O(1)
 * constructor with node ptr    O(1)
 * operator*                    O(1)
 * operator++                   O(1)
 * operator==                   O(1)
 * operator!=                   O(1)
 */
#include "node_s.h"

template <class T>
class linkedListIterator{
public:
  linkedListIterator();                 // Default constructor
  linkedListIterator(nodeS<T> *ptr);    // Constructor at location ptr

  T operator*();                        // Dereferencing a node
  linkedListIterator<T> operator++();   // Overloaded pre increment operator
  bool operator==(const linkedListIterator<T>& right) const; // Overloaded equality comparison
  bool operator!=(const linkedListIterator<T>& right) const; // Overloaded inequality comparison

private:
  nodeS<T> *current;                       // Pointer to current node in the list
};
#include "linked_list_iterator.cpp"
#endif // LINKED_LIST_ITERATOR_H
