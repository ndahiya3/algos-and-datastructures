#ifndef HEAP_SORT_ARRAY_H
#define HEAP_SORT_ARRAY_H
/*
 * Implementation of building a heap out of array based list
 * and heapsort to sort array in ascending order.
 */
#include "array_list_adt.h"

template <class T> class heapSortArray : public arrayListADT<T> {
public:
  void build_heap(); // Build heap from array
  void heap_sort_asc();

private:
  void heapify(int root, int end); // Convert subtree at root index
protected:
  using arrayListADT<T>::length;
  using arrayListADT<T>::list;
};
#include "heap_sort_array.cpp"
#endif // HEAP_SORT_ARRAY_H
