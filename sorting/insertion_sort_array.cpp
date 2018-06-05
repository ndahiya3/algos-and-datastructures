#include "insertion_sort_array.h"

template <class T> void insertionSort<T>::insertion_sort_asc() {
  // Insertion sort array based list in Ascending order
  // Starting from the 2nd element to the last element
  // insert the element towards the left at its appropriate
  // position by moving the out of order elements down by one

  for (int i = 1; i < length; i++) {
    T value = list[i]; // This creates a hole
    int hole = i;

    while (hole > 0 && list[hole - 1] > value) {
      list[hole] = list[hole - 1]; // Move the hole upwards or left to
      hole--;                      // the appropriate location
    }

    list[hole] = value; // Fill the hole with the correct value
  }
}

template <class T> void insertionSort<T>::insertion_sort_des() {
  // Insertion sort array based list in Descending order
  // Starting from the 2nd element to the last element
  // insert the element towards the left at its appropriate
  // position by moving the out of order elements down by one

  for (int i = 1; i < length; i++) {
    T value = list[i]; // This creates a hole
    int hole = i;

    while (hole > 0 && list[hole - 1] < value) {
      list[hole] = list[hole - 1]; // Move the hole upwards or left to
      hole--;                      // the appropriate location
    }

    list[hole] = value; // Fill the hole with the correct value
  }
}
