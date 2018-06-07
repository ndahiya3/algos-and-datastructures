#ifndef MERGE_SORT_LINKED_H
#define MERGE_SORT_LINKED_H
/*
 * Implementation of Merge sort on a singly linked list
 */
#include "unordered_linked_list.h"

template <class T> class mergeSortLinked : public unorderedLinkedList<T> {
public:
  void merge_sort_asc();  // Merge sort singly linked list
private:
  void divide_list(nodeS<T> *head1, nodeS<T>* &head2); // Divide list into 2 halves
  nodeS<T>* merge_list(nodeS<T> *head1, nodeS<T> *head2); // Merge two lists
  void recursive_merge_sort(nodeS<T>* &head);
protected:
  using unorderedLinkedList<T>::head;
  using unorderedLinkedList<T>::tail;

};
#include "merge_sort_linked.cpp"
#endif // MERGE_SORT_LINKED_H
