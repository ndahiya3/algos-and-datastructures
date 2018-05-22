#ifndef UNORDERED_DOUBLY_LINKED_LIST_H
#define UNORDERED_DOUBLY_LINKED_LIST_H
/*
 * Unordered doubly linked list class implementation.
 * Derived from doubly linked list base class.
 *
 * Implements:
 *
 * search           O(n)
 * insert_front     O(1)
 * insert_back      O(1)
 * insert_at        O(n)
 * delete_item      O(n)
 * delete_front     O(1)
 * delete_back      O(1)
 * delete_at        O(n)
 *
 */

#include "doubly_linked_list_adt.h"

template <class T>
class unorderedDoublyLinkedList : public doublyLinkedListADT<T> {
public:
  void search(const T &item) const;
  void insert_front(const T &item); // Insert item at front of list
  void insert_back(const T &item);  // Insert item at end of list
  void insert_at(const T &item,
                 int n);           // Insert item at nth position
  void delete_item(const T &item); // Delete item if found
  void delete_front();             // Delete first item
  void delete_back();              // Delete last item
  void delete_at(int n);           // Delete item at index n
}
#include "unordered_doubly_linked_list.cpp"
#endif // UNORDERED_DOUBLY_LINKED_LIST_H
