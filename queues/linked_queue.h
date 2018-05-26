#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

/*
 * Unordered singly linked list based implementation of queue
 *
 * Implements:
 *  is_empty                O(1)
 *  is_full                 O(1)
 *  initialize_queue        O(n)
 *  front                   O(1)
 *  back                    O(1)
 *  enqeue                  O(1)
 *  dequeue                 O(1)
 *  Default constructor     O(1)
 *  Copy constructor        O(n)
 *  Assignment operator     O(n)
 *  Destructor              O(n)
 */
#include "queue_adt.h"
#include "unordered_linked_list.h"

template <class T> class linkedQueue : public queueADT<T> {
public:
  bool is_empty() const;       // Check if queue is empty
  bool is_full() const;        // Check if queue is full
  void initialize_queue();     // Initialize empty queue
  T front() const;             // Peek front of list
  T back() const;              // Peek rear of list
  void enqueue(const T &item); // Enqueue item to front
  void dequeue();              // Dequeue utem from back

  linkedQueue();                                 // Default constructor
  linkedQueue(const linkedQueue<T> &otherQueue); // Copy constructor
  const linkedQueue<T> &
  operator=(const linkedQueue<T> &otherQueue); // Assignment operator
  ~linkedQueue();                              // Destructor

private:
  unorderedLinkedList<T> list; // Singly linked list holding elements
  void copy_queue(
      const linkedQueue<T> &otherQueue); // Copy other queue to this queue
};
#include "linked_queue.cpp"
#endif // LINKED_QUEUE_H
