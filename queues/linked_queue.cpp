#include "linked_queue.h"
#include <iostream>

template <class T> linkedQueue<T>::linkedQueue() { list.initialize_list(); }

template <class T>
linkedQueue<T>::linkedQueue(const linkedQueue<T> &otherQueue) {
  list = otherQueue.list;
}

template <class T>
const linkedQueue<T> &linkedQueue<T>::
operator=(const linkedQueue<T> &otherQueue) {
  if (this != &otherQueue)
    list = otherQueue.list;
  return *this;
}

template <class T> linkedQueue<T>::~linkedQueue() { list.destroy_list(); }

template <class T> bool linkedQueue<T>::is_empty() const {
  return list.is_empty_list();
}

template <class T> bool linkedQueue<T>::is_full() const { return false; }

template <class T> void linkedQueue<T>::initialize_queue() {
  list.initialize_list();
}

template <class T> T linkedQueue<T>::front() const { return list.front(); }

template <class T> T linkedQueue<T>::back() const { return list.back(); }

template <class T> void linkedQueue<T>::enqueue(const T &item) {
  list.insert_back(item);
}

template <class T> void linkedQueue<T>::dequeue() { list.delete_front(); }
