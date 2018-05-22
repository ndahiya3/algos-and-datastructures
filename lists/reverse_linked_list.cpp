#include "reverse_linked_list.h"

template <class T> void reverseLinkedList<T>::print_reverse() const {
  reverse_print(head);
  std::cout << std::endl;
}

template <class T>
void reverseLinkedList<T>::reverse_print(const nodeS<T> *const p) const {
  if (p == nullptr) // Exit condition
    return;
  // std::cout << p->data << ' ';      // Print statement here for forward print
  reverse_print(p->next);
  std::cout << p->data << ' '; // Print statement here for reverse print
                               // Print starts after last recursive call
}

template <class T> void reverseLinkedList<T>::reverse_list_iter() {

  nodeS<T> *prev, *current, *next;
  prev = nullptr; // Takes care of only zero/one element list
  current = head;

  while (current != nullptr) {
    next = current->next; // Save the next pointer
    current->next = prev; // Reverse the link
    prev = current;       // Advance pointers
    current = next;
  }
  tail = head; // New tail is the old head
  head = prev; // Prev now points to last element of list
}

template <class T> void reverseLinkedList<T>::reverse_list_recursion() {

  if (head == nullptr)
    return;

  reverse_recursive(head);
}

template <class T> void reverseLinkedList<T>::reverse_recursive(nodeS<T> *p) {

  if (p->next == nullptr) {
    tail = head;
    head = p;
    return;
  }
  reverse_recursive(p->next);
  // Comes to this part with p second to last node
  nodeS<T> *q = p->next;
  q->next = p;       // This and previous statement reverses the link
  p->next = nullptr; // This takes care of the last node
}
