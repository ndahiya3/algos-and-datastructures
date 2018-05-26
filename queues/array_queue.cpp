//#include "array_queue.h"
#include <assert.h>
#include <iostream>

template <class T> arrayQueue<T>::arrayQueue(int max_size) {
  max_q_size = max_size;
  if (max_size < 1)
    max_q_size = 100;
  q_front = 0;
  q_back = -1;
  count = 0;
  list = new T[max_q_size];
}

template <class T> arrayQueue<T>::arrayQueue(const arrayQueue<T> &otherQueue) {
  list = nullptr;
  copy_queue(otherQueue);
}

template <class T>
const arrayQueue<T> &arrayQueue<T>::operator=(const arrayQueue<T> &otherQueue) {
  if (this != &otherQueue)
    copy_queue(otherQueue);
  return *this;
}

template <class T> arrayQueue<T>::~arrayQueue() { delete[] list; }

template <class T> bool arrayQueue<T>::is_empty() const { return (count == 0); }

template <class T> bool arrayQueue<T>::is_full() const {
  return (count == max_q_size);
}

template <class T> void arrayQueue<T>::initialize_queue() {
  q_front = 0;
  q_back = -1;
  count = 0;
}

template <class T> T arrayQueue<T>::front() const {
  assert(!is_empty());
  return list[q_front];
}

template <class T> T arrayQueue<T>::back() const {
  assert(!is_empty());
  return list[q_back];
}

template <class T> void arrayQueue<T>::enqueue(const T &item) {
  if (!is_full()) {
    q_back = (q_back + 1) % max_q_size;
    list[q_back] = item;
    count++;
  } else
    std::cout << "Cannot add element to full queue." << std::endl;
}

template <class T> void arrayQueue<T>::dequeue() {
  if (!is_empty()) {
    q_front = (q_front + 1) % max_q_size; // Array is circular
    count--;
  } else {
    std::cout << "Cannot remove element from empty queue." << std::endl;
  }
}

template <class T>
void arrayQueue<T>::copy_queue(const arrayQueue<T> &otherQueue) {
  if (otherQueue.is_empty())
    initialize_queue();
  count = otherQueue.count;
  q_front = 0;
  q_back = count - 1;
  max_q_size = otherQueue.max_q_size;
  if (list)
    delete[] list;
  list = new T[max_q_size];

  // Copy list
  int j = otherQueue.q_front;
  for (int i = 0; i < count; i++) {
    list[i] = otherQueue.list[j];
    j = (j + 1) % max_q_size;
  }
}
