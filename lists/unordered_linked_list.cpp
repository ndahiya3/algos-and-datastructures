#include "unordered_linked_list.h"
#include <iostream>

template <class T> bool unorderedLinkedList<T>::search(const T &item) const {

  nodeS<T> *current = head;
  bool found = false;

  while (current != nullptr && !found)
    if (current->data == item)
      found = true;
    else
      current = current->next;

  return found;
}

template <class T> void unorderedLinkedList<T>::insert_front(const T &item) {
  nodeS<T> *newNode = new nodeS<T>;
  newNode->data = item;
  newNode->next = head;
  head = newNode;
  count++;
  if (tail == nullptr)
    tail = newNode;
}

template <class T> void unorderedLinkedList<T>::insert_back(const T &item) {
  nodeS<T> *newNode = new nodeS<T>;
  newNode->data = item;
  newNode->next = nullptr;

  if (head == nullptr) { // list is empty
    head = newNode;
    tail = newNode;
    count++;
  } else { // list is not empty. Insert after last
    tail->next = newNode;
    tail = newNode;
    count++;
  }
}

template <class T> void unorderedLinkedList<T>::insert_at(const T &item, int n) {
  if (n < 0 || n > count) {
    std::cout << "Insert index out of bounds\n";
    return;
  }
  nodeS<T> *newNode = new nodeS<T>;
  newNode->data = item;
  newNode->next = nullptr;

  if (n == 0) {
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) // list was empty, now head == tail
      tail = newNode;
    return;
  }

  nodeS<T> *current = head;
  for (int i = 0; i < n - 1; i++)
    current = current->next;
  newNode->next = current->next;
  current->next = newNode;
  if (current == tail)
    tail = newNode;
}

template <class T> void unorderedLinkedList<T>::delete_item(const T &item) {

  if (count == 0) {
    std::cout << "List is empty.\n";
    return;
  }

  nodeS<T> *current;
  nodeS<T> *trailCurrent; // to adjust links
  bool found;

  if (head->data == item) {
    current = head;
    head = head->next;
    delete current;
    count--;
    if (head == nullptr) // only node in list
      tail = nullptr;
  } else {
    trailCurrent = head;
    current = head->next;
    found = false;
    while (current != nullptr && !found) {
      if (current->data != item) {
        trailCurrent = current;
        current = current->next;
      } else
        found = true;
    }
    if (found) {
      trailCurrent->next = current->next;
      if (current == tail)
        tail = trailCurrent;
      delete current;
      count--;
    } else
      std::cout << "Element to delete not found in list.\n";
  }
}

template <class T> void unorderedLinkedList<T>::delete_front() {

  if (head == nullptr) {
    std::cout << "List is empty\n";
    return;
  }

  nodeS<T> *temp = head;
  head = head->next;
  count--;
  if (head == nullptr) // list had only one node
    tail = nullptr;
  delete temp;
}

template <class T> void unorderedLinkedList<T>::delete_back() {

  if (head == nullptr) {
    std::cout << "List is empty\n";
    return;
  }

  if (head == tail) {
    delete head;
    head = nullptr;
    tail = nullptr;
    count--;
    return;
  }

  nodeS<T> *trailCurrent = head;
  nodeS<T> *current = head->next;

  while (current != tail) {
    trailCurrent = current;
    current = current->next;
  }
  tail = trailCurrent;
  delete current;
  count--;
}

template <class T> void unorderedLinkedList<T>::delete_at(int n) {

  if (head == nullptr) {
    std::cout << "List is empty\n";
    return;
  }
  if (n < 0 || n > (count - 1)) {
    std::cout << "Index out of range\n";
    return;
  }

  nodeS<T> *temp = head;
  if (n == 0) {
    head = head->next;
    delete temp;
    count--;
    if (head = nullptr) // There was only one element in list
      tail = nullptr;
    return;
  }
  for (int i = 0; i < n - 1; i++) // Go to trailing node
    temp = temp->next;

  nodeS<T> *current = temp->next; // Node to delete
  if (current = tail)             // Node to delete is last node; adjust tail
    tail = temp;
  delete current;
  count--;
}
