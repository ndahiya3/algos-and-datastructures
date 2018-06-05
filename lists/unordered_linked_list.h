#ifndef UNORDERED_LINKED_LIST_H
#define UNORDERED_LINKED_LIST_H

/*
 * Unordered linked list inherited from singly linked list ADT.
 * Implements:
 * search           O(n)
 * insert_front     O(1)
 * insert_back      O(1)
 * insert_at        O(n)
 * delete_item      O(n)
 * delete_front     O(1)
 * delete_back      O(n)
 * delete_at        O(n)
 */

#include "linked_list_adt.h"

template <class T> class unorderedLinkedList : public linkedListADT<T> {
public:
  bool search(const T &item) const;
  void insert(const T &item); // insert front by default
  void insert_front(const T &item);
  void insert_back(const T &item);
  void insert_at(const T &item, int n);

  void delete_item(const T &item);
  void delete_front();
  void delete_back();
  void delete_at(int n);

protected:
  using linkedListADT<T>::head;
  using linkedListADT<T>::tail;
  using linkedListADT<T>::count;
};
#include "unordered_linked_list.cpp"

#endif // UNORDERED_LINKED_LIST_H
