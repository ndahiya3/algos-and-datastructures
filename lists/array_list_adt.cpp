//#include "array_list_adt.h"
#include <cassert>
#include <climits>
#include <iostream>

template <class T> bool arrayListADT<T>::is_empty() const {
  return (length == 0);
}

template <class T> bool arrayListADT<T>::is_full() const {
  return (length == max_size);
}

template <class T> int arrayListADT<T>::list_size() const { return length; }

template <class T> int arrayListADT<T>::max_list_size() const {
  return max_size;
}

template <class T> void arrayListADT<T>::print() const {
  for (int i = 0; i < length; i++)
    std::cout << list[i] << " ";
  std::cout << std::endl;
}

template <class T>
bool arrayListADT<T>::is_item_at_equal(int loc, const T &item) const {
  if (loc < 0 || loc > length - 1) {
    std::cout << "Index out of range." << std::endl;
    return false;
  } else
    return (list[loc] == item);
}

template <class T> void arrayListADT<T>::insert_at(int loc, const T &item) {
  if (loc < 0 || loc > length)
    std::cout << "Location index out of range." << std::endl;
  else if (length >= max_size)
    std::cout << "List is full." << std::endl;
  else {
    if (length == curr_size)
      resize(2 * curr_size);

    // Move list items down
    for (int i = length; i > loc; i--)
      list[i] = list[i - 1];
    // Insert at desired loc
    list[loc] = item;
    length++;
  }
}
template <class T> void arrayListADT<T>::insert_end(const T &item) {
  if (length >= max_size)
    std::cout << "List is full." << std::endl;
  else {
    if (length == curr_size)
      resize(2 * curr_size);
    list[length++] = item;
  }
}

template <class T> void arrayListADT<T>::remove_at(int loc) {
  if (loc < 0 || loc > (length - 1))
    std::cout << "Location index out of bounds." << std::endl;
  else {
    for (int i = loc; i < length - 1; i++)
      list[i] = list[i + 1];
    length--;
    if (length < curr_size / 4)
      resize(curr_size / 2);
  }
}

template <class T> T arrayListADT<T>::retrieve_at(int loc) const {
  if (loc < 0 || loc > (length - 1)) {
    std::cout << "Location index out of bounds." << std::endl;
    return -1;
  } else
    return list[loc];
}

template <class T> void arrayListADT<T>::replace_at(int loc, const T &item) {
  if (loc < 0 || loc > (length - 1))
    std::cout << "Location index out of bounds." << std::endl;
  else
    list[loc] = item;
}

template <class T> void arrayListADT<T>::clear_list() {
  length = 0;
  resize(100);
}

template <class T> int arrayListADT<T>::seq_search(const T &item) const {
  if (length == 0) {
    std::cout << "List is empty." << std::endl;
    return -1;
  }
  int loc = -1;

  for (int i = 0; i < length; i++)
    if (list[i] == item) {
      loc = i;
      break;
    }
  return loc;
}

template <class T> void arrayListADT<T>::insert(const T &item) {
  if (seq_search(item) != -1) {
    std::cout << "Item already in list." << std::endl;
    return;
  }
  if (length >= max_size) {
    std::cout << "List is full." << std::endl;
    return;
  }
  if (length == curr_size)
    resize(2 * curr_size);
  list[length++] = item;
}

template <class T> void arrayListADT<T>::remove(const T &item) {
  int loc = seq_search(item);
  if (loc != -1)
    remove_at(loc);
}

template <class T> arrayListADT<T>::arrayListADT(int size) {
  // Constructor
  if (size < 0)
    size = 100;
  list = new T[size];
  assert(list != nullptr);
  length = 0;
  max_size = INT_MAX;
  curr_size = size;
}

template <class T>
arrayListADT<T>::arrayListADT(const arrayListADT<T> &otherList) {
  // Copy constructor
  max_size = otherList.max_size;
  length = otherList.length;
  list = new T[length];
  curr_size = length;
  assert(list != nullptr);

  for (int i = 0; i < length; i++)
    list[i] = otherList.list[i];
}

template <class T>
arrayListADT<T> &arrayListADT<T>::operator=(const arrayListADT<T> &otherList) {
  if (this != &otherList) { // Avoid self copy
    length = otherList.length;
    max_size = otherList.max_size;
    if (list != nullptr)
      delete[] list;
    list = new T[length];
    assert(list != nullptr);
    for (int i = 0; i < length; i++)
      list[i] = otherList.list[i];
    curr_size = length;
  }
  return *this;
}

template <class T> arrayListADT<T>::~arrayListADT() { delete[] list; }

template <class T> void arrayListADT<T>::resize(int new_size) {
  // Resize array when list becomes full or quarter empty
  T *new_list = new T[new_size];
  assert(new_list != nullptr);

  for (int i = 0; i < length; i++)
    new_list[i] = list[i];

  delete[] list;
  list = new_list;
  curr_size = new_size;
}
