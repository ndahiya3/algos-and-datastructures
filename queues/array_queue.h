#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

/*
 * Array based implementation of queue
 *
 * Implements:
 *  is_empty                O(1)
 *  is_full                 O(1)
 *  initialize_queue        O(1)
 *  front                   O(1)
 *  back                    O(1)
 *  enqeue                  O(1)
 *  dequeue                 O(1)
 *  Default constructor     O(1)
 *  Copy constructor        O(n)
 *  Assignment operator     O(n)
 */
#include "queue_adt.h"

template <class T> class arrayQueue : public queueADT<T> {
public:
  bool is_empty() const;       // Check if queue is empty
  bool is_full() const;        // Check if queue is full
  void initialize_queue();     // Initialize empty queue
  T front() const;             // Peek front of list
  T back() const;              // Peek rear of list
  void enqueue(const T &item); // Enqueue item to front
  void dequeue();              // Dequeue utem from back

  arrayQueue(int max_size = 100);              // Default constructor
  arrayQueue(const arrayQueue<T> &otherQueue); // Copy constructor
  const arrayQueue<T> &
  operator=(const arrayQueue<T> &otherQueue); // Assignment operator
  ~arrayQueue();                              // Destructor

private:
  int max_q_size; // Variable for maximum size of queue
  int q_front;    // Index of queue front element
  int q_back;     // Index of queue back element
  int count;      // Current number of elements
  T *list;        // Pointer to array holding the queue elements
  void
  copy_queue(const arrayQueue<T> &otherQueue); // Copy other queue to this queue
};
#include "array_queue.cpp"
#endif // ARRAY_QUEUE_H
