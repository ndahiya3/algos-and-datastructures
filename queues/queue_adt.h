#ifndef QUEUE_ADT_H
#define QUEUE_ADT_H
/*
 * Abstract base class for queue data structure.
 * Enqueue to front and dequeue from back ==> FIFO
 *
 * Provides:
 *  is_empty
 *  is_full
 *  initialize_queue
 *  front
 *  back
 *  enqeue
 *  dequeue
 */

template <class T> class queueADT {
public:
  virtual bool is_empty() const = 0;       // Check if queue is empty
  virtual bool is_full() const = 0;        // Check if queue is full
  virtual void initialize_queue() = 0;     // Initialize empty queue
  virtual T front() const = 0;             // Peek front of list
  virtual T back() const = 0;              // Peek rear of list
  virtual void enqueue(const T &item) = 0; // Enqueue item to front
  virtual void dequeue() = 0;              // Dequeue utem from back
};
#endif // QUEUE_ADT_H
