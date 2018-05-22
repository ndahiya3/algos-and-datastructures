//#include "unordered_doubly_linked_list.h"
#include <iostream>

template <class T>
bool unorderedDoublyLinkedList<T>::search(const T &item) const {
  bool found = false;
  nodeD<T> *current = head;
  while (current != nullptr && !found)
    if (current->data == item)
      found = true;
    else
      current = current->next;
  return found;
}

template <class T>
void unorderedDoublyLinkedList<T>::insert_front(const T &item) {
  nodeD<T> *newNode = new nodeD<T>;
  newNode->data = item;
  newNode->next = nullptr;
  newNode->prev = nullptr;

  if (head == nullptr) { // Empty list
    head = newNode;
    tail = newNode;
  } else {
    newNode->next = head;
    head->prev = newNode; // Handles case of only 1 when where head == tail
    head = newNode;
  }
  count++;
}

template <class T>
void unorderedDoublyLinkedList<T>::insert_back(const T &item) {
  nodeD<T> *newNode = new nodeD<T>;
  newNode->data = item;
  newNode->next = nullptr;
  newNode->prev = nullptr;

  if (head == nullptr) {
    head = newNode;
    tail = newNode;
  } else {
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
  }
  count++;
}

template <class T>
void unorderedDoublyLinkedList<T>::insert_at(const T &item, int n) {
  if (n < 0 || n > count) {
    std::cout << "Index out of range." << std::endl;
    return;
  }

  if (n == 0) {
    insert_front(item);
    return;
  }
  if (n == count) {
    insert_back(item);
    return;
  }
  // Insert somewhere in the middle
  nodeD<T> *newNode = new nodeD<T>;
  newNode->data = item;

  nodeD<T> *prev = head;
  for (int i = 0; i < n - 1; i++)
    prev = prev->next;
  nodeD<T> *next = prev->next;

  // Insert new node between prev and next and adjust links
  newNode->prev = prev;
  newNode->next = next;
  prev->next = newNode;
  next->prev = newNode;
  count++;
}

template <class T> void unorderedDoublyLinkedList<T>::delete_front() {
  if (head == nullptr) {
    std::cout << "List is empty." << std::endl;
    return;
  }
  nodeD<T> *temp = head;
  head = head->next;
  if (head == nullptr)
    tail = nullptr;
  else
    head->prev = nullptr;

  delete temp;
  count--;
}

template <class T> void unorderedDoublyLinkedList<T>::delete_back() {
  if (head == nullptr) {
    std::cout << "List is empty." << std::endl;
    return;
  }
  nodeD<T> *temp = tail;
  tail = tail->prev;
  if (tail == nullptr)
    head = nullptr;
  else
    tail->next = nullptr;

  delete temp;
  count--;
}

template <class T> void unorderedDoublyLinkedList<T>::delete_at(int n) {
  if (n < 0 || n > (count - 1)) {
    std::cout << "Index out of range." << std::endl;
    return;
  }

  if (n == 0) {
    delete_front();
    return;
  }
  if (n == (count - 1)) {
    delete_back();
    return;
  }

  // Delete somewhere in the middle
  nodeD<T> *current = head->next;
  for (int i = 0; i < n - 1; i++)
    current = current->next;

  // Delete the node current which is between prev and next
  nodeD<T> *prev = current->prev;
  nodeD<T> *next = current->next;
  prev->next = next;
  next->prev = prev;
  delete current;
  count--;
}

template <class T>
void unorderedDoublyLinkedList<T>::delete_item(const T &item) {

  if (head == nullptr)
    std::cout << "List is empty." << std::endl;
  else if (head->data == item)
    delete_front();
  else if (tail->data == item)
    delete_back();
  else {
    bool found = false;
    nodeD<T> *current = head->next;
    while (current != nullptr && !found)
      if (current->data == item)
        found = true;
      else
        current = current->next;
    if (found) {
      nodeD<T> *prev = current->prev;
      nodeD<T> *next = current->next;
      prev->next = next;
      next->prev = prev;
      delete current;
      count--;
    } else {
      std::cout << "Item is not in the list." << std::endl;
    }
  }
}
