#ifndef QUICK_SORT_ARRAY_H
#define QUICK_SORT_ARRAY_H
/*
 * Quick sort implementation on array based list.
 */
#include "array_list_adt.h"

template <class T> class quickSortArray : public arrayListADT<T> {
public:
  void quick_sort_asc(); // Quick sort array in descending order
private:
  int partition(int first, int last); // Partition list
  void swap(int first, int second);   // Swap first location element with second
  void rec_quick_sort(int first, int last); // Recursive quick sort
protected:
  using arrayListADT<T>::list;
  using arrayListADT<T>::length;
};
#include "quick_sort_array.cpp"

#endif // QUICK_SORT_ARRAY_H
