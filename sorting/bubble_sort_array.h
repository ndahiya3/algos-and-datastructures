#ifndef BUBBLE_SORT_ARRAY_H
#define BUBBLE_SORT_ARRAY_H
/*
 * Implementation of Bubble sort for array based list
 * Implements:
 *  bubble_sort_asc           O(n^2)
 *  bubble_sort_des           O(n^2)
 */
#include "array_list_adt.h"

template <class T> class bubbleSort : public arrayListADT<T> {
public:
  void bubble_sort_asc(); // Bubble sort array in ascending order
  void bubble_sort_des(); // Bubble sort array in descending order

private:
  void swap(int first, int second); // Swap element at first index with second

protected:
  using arrayListADT<T>::list;
  using arrayListADT<T>::length;
};
#include "bubble_sort_array.cpp"
#endif // BUBBLE_SORT_ARRAY_H
