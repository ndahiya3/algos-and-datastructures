#ifndef BINARY_SEARCH_ARRAY_H
#define BINARY_SEARCH_ARRAY_H
/*
 * Implementation of binary search in a sorted array.
 * Both iterative and recursive implementations.
 * If array is not sorted, it is sorted first.
 */

#include "array_list_adt.h"

template <class T> class binarySearchArray : public arrayListADT<T> {
public:
  int binary_search(const T &item);     // Search item with binary search
  int binary_search_rec(const T &item); // Recursive binary search
private:
  int rec_binary_search(int start, int end, const T &item);

protected:
  using arrayListADT<T>::list;
  using arrayListADT<T>::length;
};
#include "binary_search_array.cpp"
#endif // BINARY_SEARCH_ARRAY_H
