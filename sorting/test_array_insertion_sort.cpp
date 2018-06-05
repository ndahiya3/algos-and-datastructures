#include "insertion_sort_array.h"
#include <iostream>
using namespace std;

void fill_data(insertionSort<int> &sort) {
  sort.insert(1);
  sort.insert(-8);
  sort.insert(10);
  sort.insert(16);
  sort.insert(5);
  sort.insert(3);
  sort.insert(6000);
  sort.insert(-5000);
  sort.insert(7);
  sort.insert(9);
  sort.insert(99);
}

void test_sort_ascending() {
  // Test insertion sort in ascending order

  insertionSort<int> sort;
  fill_data(sort);

  cout << "Before sorting in ascending order: " << endl;
  sort.print();

  cout << "After sorting in ascending order: " << endl;
  sort.insertion_sort_asc();
  sort.print();
}

void test_sort_descending() {
  // Test insertion sort in descending order

  insertionSort<int> sort;
  fill_data(sort);

  cout << "Before sorting in descending order: " << endl;
  sort.print();

  cout << "After sorting in descending order: " << endl;
  sort.insertion_sort_des();
  sort.print();
}

int main() {
  test_sort_ascending();
  test_sort_descending();
  return 0;
}
