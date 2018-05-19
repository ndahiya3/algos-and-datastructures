//#include "linked_list_adt.h"
#include <assert.h>
#include <iostream>

template <class T> linkedListADT<T>::linkedListADT() {
  // Default constructor
  count = 0;
  head = nullptr;
  tail = nullptr;
}

template <class T>
linkedListADT<T>::linkedListADT(const linkedListADT<T> &otherList) {
  // Copy constructor
  head = nullptr; // If being passed as a value parameter
                  // See copy_list method
  copyList(otherList);
}

template <class T>
const linkedListADT<T> &linkedListADT<T>::
operator=(const linkedListADT<T> &otherList) {

  // Assignment operator
  if (this != otherList) // Avoid self copy
    copyList(otherList);
  return *this;
}
template <class T> bool linkedListADT<T>::is_empty_list() const {
  return (count == 0);
}

template <class T> void linkedListADT<T>::initialize_list() { destroy_list(); }

template <class T> void linkedListADT<T>::destroy_list() {
  nodeS<T> *temp;
  while (head != nullptr) {
    temp = head;
    head = head->next;
    delete temp;
  }
  tail = nullptr;
  count = 0;
}

template <class T> T linkedListADT<T>::front() const {
  assert(head != nullptr);
  return head->data;
}

template <class T> T linkedListADT<T>::back() const {
  assert(tail != nullptr);
  return tail->data;
}

template <class T> void linkedListADT<T>::print() const {
  nodeS<T> *current = head;
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

template <class T> int linkedListADT<T>::length() const { return count; }

template <class T> linkedListIterator<T> linkedListADT<T>::begin() {
  // Iterator to beginning of list
  linkedListIterator<T> temp(head);
  return temp;
}

template <class T> linkedListIterator<T> linkedListADT<T>::end() {
  // Iterator to one past end of list
  linkedListIterator<T> temp(nullptr);
  return temp;
}

template <class T>
void linkedListADT<T>::copyList(const linkedListADT<T> &otherList) {
  nodeS<T> *newNode;
  nodeS<T> *current;

  if (head != nullptr)
    destroy_list();

  if (otherList.head == nullptr) {
    head = nullptr;
    tail = nullptr;
    count = 0;
  } else {
    current = otherList.head;
    count = otherList.count;

    // Copy first node
    head = new nodeS<T>;
    head->data = current->data;
    head->next = nullptr;
    tail = head;

    current = current->next;
    while (current != nullptr) {
      newNode = new nodeS<T>;
      newNode->data = current->data;
      newNode->next = nullptr;
      tail->next = newNode;
      tail = newNode;
      current = current->next;
    }
  }
}
