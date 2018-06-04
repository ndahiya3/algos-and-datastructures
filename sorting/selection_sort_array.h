#ifndef SELECTION_SORT_ARRAY_H
#define SELECTION_SORT_ARRAY_H
/*
 * Class to implement selection sort on array based lists.
 * Implements:
 *  selection_sort_asc        O(n^2)
 *  selection_sort_des        O(n^2)
 */

#include "array_list_adt.h"
template <class T>
class selectionSort : public arrayListADT<T> {
public:
  void selection_sort_asc(); // Perform selection sort in ascending order
  void selection_sort_des(); // Perform selection sort ind escending order
private:
  int min_location(
      int start,
      int end) const; // Find minimum element's location between start and end points.
  int max_location(
      int start,
      int end) const; // Find maximum element's location between start and end points.
  void swap(int first, int second); // Swap element at first with second element
protected:
  using arrayListADT<T>::length;
  using arrayListADT<T>::list;
};
#include "selection_sort_array.cpp"
#endif // SELECTION_SORT_ARRAY_H
