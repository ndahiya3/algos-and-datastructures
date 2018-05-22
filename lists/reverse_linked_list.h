#ifndef REVERSE_LINKED_LIST_H
#define REVERSE_LINKED_LIST_H
/*
 * Print singly linked list in reverse order with recursion.
 * Reverse the list iteratively and with recursion.
 * Implements:
 * print_reverse
 * reverse_list_iter
 * reverse_list_recursion
 */

#include "unordered_linked_list.h"

template <class T> class reverseLinkedList : public unorderedLinkedList<T> {
public:
  void print_reverse() const;    // Print list in reverse order with recursion
  void reverse_list_iter();      // Reverse list using iterative method
  void reverse_list_recursion(); // Reverse list using recursion

private:
  void reverse_print(const nodeS<T> *const p) const;
  void reverse_recursive(nodeS<T> *p);

protected:
  using linkedListADT<T>::head;
  using linkedListADT<T>::tail;
};

#include "reverse_linked_list.cpp"
#endif // REVERSE_LINKED_LIST_H
