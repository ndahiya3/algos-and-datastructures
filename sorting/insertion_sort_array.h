#ifndef INSERTION_SORT_ARRAY_H
#define INSERTION_SORT_ARRAY_H
/*
 * Implementation of Insertion sort for array based list
 * Implements:
 *  insertion_sort_asc           O(n^2)
 *  insertion_sort_des           O(n^2)
 */
#include "array_list_adt.h"

template <class T> class insertionSort : public arrayListADT<T> {
public:
  void insertion_sort_asc(); // Insertion sort array in ascending order
  void insertion_sort_des(); // Insertion sort array in descending order

protected:
  using arrayListADT<T>::list;
  using arrayListADT<T>::length;
};
#include "insertion_sort_array.cpp"
#endif // INSERTION_SORT_ARRAY_H
