#ifndef MERGE_SORT_ARRAY_H
#define MERGE_SORT_ARRAY_H
/*
 * Implementation of array based merge sort
 */

#include "array_list_adt.h"

template <class T> class mergeSortArray : public arrayListADT<T> {
public:
  void merge_sort_asc(); // Merge sort in ascending order
private:
  void merge_sort(T* list, int size);  // Recursive mergeSort function
  void merge(T *A, T* left, int left_size, T* right, int right_size); // Merge arrays into sorted array
protected:
  using arrayListADT<T>::list;
  using arrayListADT<T>::length;
};
#include "merge_sort_array.cpp"
#endif // MERGE_SORT_ARRAY_H
