#include "insertion_sort_linked.h"
template <class T>
void insertionSortLinked<T>::insertion_sort(bool (*comparator)(const T &,
                                                               const T &)) {
  nodeS<T> *last_in_order;
  nodeS<T> *first_out_of_order;
  nodeS<T> *current;
  nodeS<T> *trail_current;

  last_in_order = head;

  if (head == nullptr)
    std::cout << "Cannot sort empty list." << std::endl;
  else if (head->next == nullptr)
    std::cout << "List of length 1, already sorted." << std::endl;
  else
    while (last_in_order->next != nullptr) {
      // last_in_order represents end of sorted part of list
      // and hence first_out_of_order lies next to it
      first_out_of_order = last_in_order->next;
      // Move to start of the list?
      // Comparator return true if a compare b is true
      if (comparator(first_out_of_order->data, head->data)) {
        // Move first_out_of_order to start of list
        last_in_order->next = first_out_of_order->next;
        first_out_of_order->next = head;
        head = first_out_of_order;
      } else {
        // Find correct position for first_out_of_order element
        trail_current = head;
        current = head->next;
        while (comparator(current->data, first_out_of_order->data)) {
          trail_current = current;
          current = current->next;
        }
        if (current != first_out_of_order) {
          // Move first_out_of_order to somewhere in middle of list
          // between trail_current and current
          last_in_order->next = first_out_of_order->next;
          first_out_of_order->next = current;
          trail_current->next = first_out_of_order;
        } else
          // Else first_out-of_order was in correct place
          //  Increment last_in_order
          last_in_order = last_in_order->next;
      }
    }
}

template <class T>
bool insertionSortLinked<T>::ascending_comparator(const T &a, const T &b) {
  return (a < b);
}
