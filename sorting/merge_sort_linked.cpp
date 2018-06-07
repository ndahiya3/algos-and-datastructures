#include "merge_sort_linked.h"

template <class T> void mergeSortLinked<T>::merge_sort_asc() {
  // Run recursive merge sort
  recursive_merge_sort(head);

  // Adjust tail as well
  if (head == nullptr)
    tail = nullptr;
  else {
    tail = head;
    while (tail->next != nullptr)
      tail = tail->next;
  }
}

template <class T> void mergeSortLinked<T>::recursive_merge_sort(nodeS<T> *&head) {
  nodeS<T> *right_list_head;
  if (head != nullptr)                    // If list is not empty
    if (head->next != nullptr) {          // If list has more than one element
                                          // Recursively divide and merge list
      divide_list(head, right_list_head); // Divide list into two halves
      recursive_merge_sort(head); // Recursively divides left half of list
      recursive_merge_sort(right_list_head);    // Recursively divide right half
      head = merge_list(head, right_list_head); // Merge left and right lists
    }
}

template <class T>
void mergeSortLinked<T>::divide_list(nodeS<T> *head1, nodeS<T> *&head2) {

  nodeS<T> *current;
  nodeS<T> *middle;

  if (head1 == nullptr) // List empty
    head2 = nullptr;
  else if (head1->next == nullptr) // Only one element
    head2 = nullptr;
  else {
    // 2 or more elements
    middle = head1;
    current = head1->next;
    if (current != nullptr)
      current = current->next;

    // Middle takes 1 step for every 2 steps of current
    while (current != nullptr) {
      middle = middle->next;   // Move middle one step
      current = current->next; // Move current 1st step
      if (current != nullptr)
        current = current->next; // Move current 2nd step if possible
    }
    head2 = middle->next;   // Start of 2nd half of list
    middle->next = nullptr; // End of 1st half of list
                            // head1 still points to beginning of 1st list
  }
}

template <class T>
nodeS<T> *mergeSortLinked<T>::merge_list(nodeS<T> *head1, nodeS<T> *head2) {
  // Merge two sorted sub-lists with head pointers head1 and head2 in acending
  // order

  nodeS<T> *last_merged; // Pointer to last node of merged list
  nodeS<T> *new_head;    // Pointer to merged list

  if (head1 == nullptr)
    return head2;
  else if (head2 == nullptr)
    return head1;
  else {
    // Handle the first element to initialize the merged list (new_head)
    // Use last_merged to keep track of end of merged list where
    // new elements from either 1st or 2nd list go
    if (head1->data < head2->data) {
      new_head = head1;
      head1 = head1->next;
      last_merged = new_head;
    } else {
      new_head = head2;
      head2 = head2->next;
      last_merged = new_head;
    }
    // head1 and head2 point to elements yet to be merged and hence are adjusted
    // after each new element is merged
    // While none of the 2 sub-lists are exhausted
    while (head1 != nullptr && head2 != nullptr) {
      if (head1->data < head2->data) { // Find next element to be merged
        last_merged->next = head1;     // Add to tail of merged and advance
        last_merged = last_merged->next;
        head1 = head1->next; // Advance head to next unmerged item
      } else {
        last_merged->next = head2;
        last_merged = last_merged->next;
        head2 = head2->next;
      }
    }
    // If one of the sub-lists is exhausted, add remaining elements
    // of other list to merged_list
    if (head1 == nullptr) // 1st sub-list is exhausted first
      last_merged->next = head2;
    else
      last_merged->next = head1; // 2nd sub-list is exhausted first

    return new_head;
  }
}
