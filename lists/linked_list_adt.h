#ifndef LINKED_LIST_ADT_H
#define LINKED_LIST_ADT_H
/*
 * Abstract base class for singly linked list.
 * Provides:
 * assignment operator    O(n)
 * initialize_list        O(n)
 * is_empty_list          O(1)
 * destroy_list           O(n)
 * front                  O(1)
 * back                   O(1)
 * print                  O(n)
 * length                 O(1)
 * default constructor    O(1)
 * copy constructor       O(n)
 * destructor             O(n)
 * copy_list              O(n)
 */
#include "linked_list_iterator.h"

template <class T> class linkedListADT {
public:
  const linkedListADT<T> &operator=(
      const linkedListADT<T> &otherList); // overloaded assignment operator
  void initialize_list();                 // initialize empty list
  bool is_empty_list() const;             // determine if list is empty
  void destroy_list();                    // delete all nodes from list
  T front() const;                        // return first element of list
  T back() const;                         // return last element of the list
  void print() const;                     // print all elements of the list
  int length() const;                     // return length/size of the list

  virtual bool search(const T &item) const = 0; // search a given item in list
  virtual void insert_front(const T &item) = 0; // insert item at front of list
  virtual void insert_back(const T &item) = 0;  // insert item at last of list
  virtual bool insert_at(const T &item,
                         int n) = 0;           // insert item at nth position
  virtual void delete_item(const T &item) = 0; // delete item if found
  virtual void delete_front() = 0;             // delete first item
  virtual void delete_last() = 0;              // delete last item
  virtual void delete_at(int n) = 0;           // delete item at index n

  linkedListIterator<T> begin(); // return iterator at the beginning of list
  linkedListIterator<T> end();   // return iterator one element past end of list

  linkedListADT();                                  // default constructor
  linkedListADT(const linkedListADT<T> &otherList); // copy constructor
  ~linkedListADT();                                 // destructor

protected:
  int count;      // number of elements in list
  nodeS<T> *head; // first node of list
  nodeS<T> *tail; // last node of list

private:
  void copyList(const linkedListADT<T> &otherList);
  // copy other list and assign to this list
};
#include "linked_list_adt.cpp"
#endif // LINKED_LIST_ADT_H
