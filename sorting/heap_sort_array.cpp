#include "heap_sort_array.h"

template <class T> void heapSortArray<T>::heap_sort_asc() {
  // First we convert the array to a heap
  // Being a heap, the first element (root) is the max element
  // of the array. We move the largest to end of array by swapping
  // first and last and re-heapify the remaining heap (excluding the
  // largest). Keep repeating as the list to be heapified gets smaller

  build_heap();

  for (int last_out_order = length - 1; last_out_order >= 0; last_out_order--) {
    T temp = list[last_out_order];
    list[last_out_order] = list[0]; // Move largest to end
    list[0] = temp;
    heapify(0, last_out_order - 1); // Heapify the remaining
  }
}

template <class T> void heapSortArray<T>::heapify(int root, int end) {
  // Heapify the sub-tree with root at index root and last
  // element of heap at index end

  // Heap structure is a complete binary tree with root larger than
  // both its children
  // If root is not larger than children swap with larger of the
  // two children. After swapping, the sub-tree rooted at the
  // swapped child location can now violate the heap property, so
  // recursively heapify until reaching a sub-tree that already
  // satisfies the heap property

  T temp = list[root]; // Save the current root, helps reduce
                       // number of assignments in swaps from 3 to 1

  int index_largest = 2 * root + 1; // Left child index
  while (index_largest <= end) {
    if (index_largest < end) // Otherwise no right child possible
      if (list[index_largest] < list[index_largest + 1]) // Right child is >
        index_largest = index_largest + 1;
    if (temp > list[index_largest]) // sub-tree already in heap
      break;
    else {
      list[root] = list[index_largest]; // Swap root
      root = index_largest;             // New root location to consider
      index_largest = 2 * root + 1;     // New root's left-child
    }
  }
  list[root] = temp; // Finally put original root at final location
}

template <class T> void heapSortArray<T>::build_heap() {

  // We have to build heap from the bottom up.
  // The final root index which is not a leaf
  // (and hence may need to be heapified) is length/2 -1

  for (int index = length / 2 - 1; index >= 0; index--)
    heapify(index, length - 1);
}
