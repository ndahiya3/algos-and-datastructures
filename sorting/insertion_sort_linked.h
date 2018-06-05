#ifndef INSERTION_SORT_LINKED_H
#define INSERTION_SORT_LINKED_H
/*
 * Insertion sort implementation on a singly linked list.
 * Uses function pointers to sort in user defined order
 * Implements:
 *  insertion_sort        O(n^2)
 */
#include "unordered_linked_list.h"

template <class T> class insertionSortLinked : public unorderedLinkedList<T> {
public:
  void insertion_sort(bool (*comparator)(const T &a,
                                         const T &b) = ascending_comparator);

private:
  static bool ascending_comparator(const T &a, const T &b);

protected:
  using unorderedLinkedList<T>::head;
};
#include "insertion_sort_linked.cpp"
#endif // INSERTION_SORT_LINKED_H
