//#include "bubble_sort_array.h"

template <class T> void bubbleSort<T>::bubble_sort_asc() {
  // Bubble sort in ascending order
  // Go over the array n-1 times
  // In each pass compare current element to the next
  // and swap if current is greater than next.
  // The above "bubbles" the largest element of unsorted array
  // towards the end of array which forms the sorted part in each pass.

  for (int k = 0; k < length - 1; k++) {
    bool swapped_flag = false;
    for (int i = 0; i < length - k - 1; i++) {
      if (list[i] > list[i + 1]) {
        swap(i, i + 1);
        swapped_flag = true;
      }
    }
    if (swapped_flag == false)
      break;
  }
}

template <class T> void bubbleSort<T>::swap(int first, int second) {
  T temp = list[first];
  list[first] = list[second];
  list[second] = temp;
}

template <class T> void bubbleSort<T>::bubble_sort_des() {
  // Bubble sort in descending order
  // Go over the array n-1 times
  // In each pass compare current element to the next
  // and swap if current is less than next.
  // The above "bubbles" the smallest element of unsorted array
  // towards the end of array which forms the sorted part in each pass.

  for (int k = 0; k < length - 1; k++) {
    bool swapped_flag = false;
    for (int i = 0; i < length - k - 1; i++) {
      if (list[i] < list[i + 1]) {
        swap(i, i + 1);
        swapped_flag = true;
      }
    }
    if (swapped_flag == false)
      break;
  }
}
