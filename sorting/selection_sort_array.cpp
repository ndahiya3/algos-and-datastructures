//#include "selection_sort_array.h"

template <class T> void selectionSort<T>::selection_sort_asc() {
  // Sort list in ascending order using selection sort algorithm
  // Go over the list and replace current element with minimum
  // from the remaining list.

  int list_end = length - 1; // length points at one past the last element
  for (int i = 0; i < list_end;
       i++) { // We don't need to process the last element
    int min_loc = min_location(i, list_end);
    swap(i, min_loc);
  }
}

template <class T> void selectionSort<T>::selection_sort_des() {
  // Sort list in descending order using selection sort algorithm
  // Go over the list and replace current element with maximum
  // from the remaining list.

  int list_end = length - 1; // length points at one past the last element
  for (int i = 0; i < list_end; i++) {
    int max_loc = max_location(i, list_end);
    swap(i, max_loc);
  }
}

template <class T>
int selectionSort<T>::min_location(int start, int end) const {
  // Find location of minimum element in the list between start and end indexes
  int min_loc = start;
  for (int i = start + 1; i <= end; i++)
    if (list[i] < list[min_loc])
      min_loc = i;
  return min_loc;
}

template <class T>
int selectionSort<T>::max_location(int start, int end) const {
  // Find location of maximum element in the list between start and end indexes
  int max_loc = start;
  for (int i = start + 1; i <= end; i++)
    if (list[i] > list[max_loc])
      max_loc = i;
  return max_loc;
}

template <class T> void selectionSort<T>::swap(int first, int second) {
  // Swap element at first location with element at second location
  T temp = list[first];
  list[first] = list[second];
  list[second] = temp;
}
