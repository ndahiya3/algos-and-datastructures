#ifndef ARRAY_LIST_ADT_H
#define ARRAY_LIST_ADT_H
/*
 * Implementation of a resizing Array based list.
 * Provides:
 *  is_empty                  O(1)
 *  is_full                   O(1)
 *  list_size                 O(1)
 *  max_list_size             O(1)
 *  is_sorted                 O(1)
 *  print                     O(n)
 *  is_item_at_equal          O(1)
 *  insert_at                 O(n)
 *  insert_end                O(1)
 *  remove_at                 O(n)
 *  retrieve_at               O(1)
 *  replace_at                O(1)
 *  clear_list                O(1)
 *  seq_search                O(n)
 *  quick_sort          O(nlog(n))
 *  insert                    O(n)
 *  remove                    O(n)
 *  Assignment operator       O(n)
 *  Constructor               O(1)
 *  Copy constructor          O(n)
 *  Destructor                O(1)
 */

template <class T> class arrayListADT {
public:
  bool is_empty() const;     // Is the list empty?
  bool is_full() const;      // Is the list full?
  int list_size() const;     // Current size of list
  int max_list_size() const; // Maximum allowed size of list
  bool is_sorted() const;    // Is the list sorted
  void print() const;        // Print the elements of the list
  bool is_item_at_equal(int loc, const T &item)
      const; // Is the item at location loc equal to item?
  void insert_at(int loc,
                 const T &item);  // Insert item at location loc (0 based)
  void insert_end(const T &item); // Insert given item at list end
  void remove_at(int loc);        // Remove the otem at location loc
  T retrieve_at(int loc) const;   // Retrieve item at location loc
  void replace_at(
      int loc,
      const T &item); // Replace the item at location loc with supplied item
  void clear_list();  // Clear all elements from the list
  int seq_search(
      const T &item) const;   // Return location of item if found, -1 otherwise
  void quick_sort();          // Sort array using quick sort
  void insert(const T &item); // Insert item at end if not found in list
  void remove(const T &item); // Remove item if found

  const arrayListADT<T> &
  operator=(const arrayListADT<T> &otherList); // Overloaded assignment operator
  arrayListADT(int size = 100);                // Constructor
  arrayListADT(const arrayListADT<T> &otherList); // Copy constructor
  ~arrayListADT();                                // Destructor

private:
  void resize(int new_size); // Resize internal array
  bool sorted;
  int partition(int first, int last); // Partition list (for quick sort)
  void swap(int first, int second);   // Swap first location element with second
  void rec_quick_sort(int first, int last); // Recursive quick sort

protected:
  T *list;
  int max_size;
  int length;
  int curr_size;
};
#include "array_list_adt.cpp"
#endif // ARRAY_LIST_ADT_H
