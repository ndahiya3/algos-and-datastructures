#include "doubly_linked_list_adt.h"
#include "assert.h"
#include <iostream>

template <class T> doublyLinkedListADT<T>::doublyLinkedListADT() {
  // Default constructor
  head = nullptr;
  tail = nullptr;
  count = 0;
}

template <class T>
doublyLinkedListADT<T>::doublyLinkedListADT(
    const doublyLinkedListADT<T> &otherList) {
  // Copy constructor
  head = nullptr; // Class hadn't been initialized yet
  copyList(otherList);
}

template <class T> doublyLinkedListADT<T>::~doublyLinkedListADT() { clear(); }

template <class T>
doublyLinkedListADT<T> &doublyLinkedListADT<T>::
operator=(const doublyLinkedListADT<T> &otherList) {

  // Assignment operator
  if (this != &otherList) // Avoid self copy
    copyList(otherList);

  return *this;
}
template <class T> bool doublyLinkedListADT<T>::is_empty() const {
  return (head == nullptr);
}

template <class T> int doublyLinkedListADT<T>::length() const { return count; }

template <class T> T doublyLinkedListADT<T>::front() const {
  assert(head != nullptr);
  return head->data;
}

template <class T> T doublyLinkedListADT<T>::back() const {
  assert(tail != nullptr);
  return tail->data;
}

template <class T> void doublyLinkedListADT<T>::clear() {
  nodeD<T> *temp;
  while (head != nullptr) {
    temp = head;
    head = head->next;
    delete temp;
  }
  tail = nullptr;
  count = 0;
}

template <class T> void doublyLinkedListADT<T>::print() const {
  nodeD<T> *current = head; // Start from front of list
  while (current != nullptr) {
    std::cout << current->data << ' '; // Print data
    current = current->next;           // Move forward
  }
  std::cout << std::endl;
}

template <class T> void doublyLinkedListADT<T>::print_reverse() const {
  nodeD<T> *current = tail; // Start from end of list
  while (current != nullptr) {
    std::cout << current->data << ' '; // Print data
    current = current->prev;           // Move backwards
  }
  std::cout << std::endl;
}

template <class T>
doublyLinkedListIterator<T> doublyLinkedListADT<T>::begin() const {
  doublyLinkedListIterator<T> temp(head);
  return temp;
}

template <class T>
doublyLinkedListIterator<T> doublyLinkedListADT<T>::end() const {
  doublyLinkedListIterator<T> temp(nullptr); // One past the end
  return temp;
}

template <class T>
void doublyLinkedListADT<T>::copyList(const doublyLinkedListADT<T> &otherList) {
  if (head != nullptr)
    clear();
  if (otherList.head == nullptr) {
    head = nullptr;
    tail = nullptr;
    count = 0;
    return;
  }

  nodeD<T> *current = otherList.head;
  nodeD<T> *newNode;
  count = otherList.count;

  // Copy the first node
  head = new nodeD<T>;
  head->data = current->data;
  head->next = nullptr;
  head->prev = nullptr;
  tail = head;

  current = current->next;
  while (current != nullptr) {
    newNode = new nodeD<T>; // Current node to copy from other list

    newNode->data = current->data;
    newNode->next = nullptr; // Currently the last node
    newNode->prev = tail;    // Backward link
    tail->next = newNode;    // Forward link
    tail = newNode;          // Advance tail

    current = current->next; // Next node to copy from other list
  }
}
