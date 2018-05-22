#ifndef DOUBLY_LINKED_LIST_ADT_H
#define DOUBLY_LINKED_LIST_ADT_H

/*
 * Abstract base class for doubly linked list.
 * Ordered or unordered linked lists can be derived from this class
 * Provides:
 * deafult constructor      O(1)
 * copy constructor         O(n)
 * destructor               O(n)
 * assignment operator      O(n)
 * front                    O(1)
 * back                     O(1)
 * is_empty                 O(1)
 * length                   O(1)
 * clear                    O(n)
 * print                    O(n)
 * reverse_print            O(n)
 */
#include "doubly_linked_list_iterator.h"

template <class T> class doublyLinkedListADT {
public:
  doublyLinkedListADT(); // Default constructor
  doublyLinkedListADT(
      const doublyLinkedListADT<T> &otherList); // Copy constructor
  ~doublyLinkedListADT();                       // Destructor
  const doublyLinkedListADT<T> &
  operator=(const doublyLinkedListADT<T> &otherList); // Assignment operator

  T front() const;            // Return first element of the list
  T back() const;             // Return last elements of the list
  bool is_empty() const;      // Check if the list is empty
  int length() const;         // Number of elements in the list
  void clear();               // Destroy the list
  void print() const;         // Print list in forward direction
  void print_reverse() const; // Print list in reverse direction

  virtual bool search(const T &item) const = 0; // Search a given item in list
  virtual void insert_front(const T &item) = 0; // Insert item at front of list
  virtual void insert_back(const T &item) = 0;  // Insert item at end of list
  virtual void insert_at(const T &item,
                         int n) = 0;           // Insert item at nth position
  virtual void delete_item(const T &item) = 0; // Delete item if found
  virtual void delete_front() = 0;             // Delete first item
  virtual void delete_back() = 0;              // Delete last item
  virtual void delete_at(int n) = 0;           // Delete item at index n

  doublyLinkedListIterator<T> begin() const; // Iterator to start of list
  doublyLinkedListIterator<T> end() const;   // Iterator to end of list
protected:
  nodeD<T> *head;
  nodeD<T> *tail;
  int count;

private:
  void copyList(const doublyLinkedListADT<T>
                    &otherList); // copy other list and assign to this list
};
#include "doubly_linked_list_adt.cpp"
#endif // DOUBLY_LINKED_LIST_ADT_H
