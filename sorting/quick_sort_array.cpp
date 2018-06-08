#include "quick_sort_array.h"

template <class T> void quickSortArray<T>::quick_sort_asc() {
  rec_quick_sort(0, length - 1);
}

template <class T> int quickSortArray<T>::partition(int first, int last) {
  // Partition the array between first and last index
  // based on comparison with pivot element. Elements
  // smaller than pivot form left part of the array

  int pivot_loc = (first + last) / 2;
  swap(first, pivot_loc); // Move pivot to start of list
  T pivot = list[first];
  int small_index = first;

  // Move elements smaller than pivot to left of list.
  // small_index marks end of smaller part of list
  for (int index = first + 1; index <= last; index++)
    if (list[index] < pivot) {
      small_index++;
      swap(index, small_index);
    }
  // Move pivot back to end of smaller part of list
  swap(first, small_index);
  return small_index;
}

template <class T> void quickSortArray<T>::rec_quick_sort(int first, int last) {
  if (first < last) {
    int pivot_location = partition(first, last);
    rec_quick_sort(first, pivot_location - 1);
    rec_quick_sort(pivot_location + 1, last);
  }
}

template <class T> void quickSortArray<T>::swap(int first, int second) {
  T temp = list[first];
  list[first] = list[second];
  list[second] = temp;
}
