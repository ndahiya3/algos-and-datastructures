#include "merge_sort_linked.h"
using namespace std;

void fill_data(mergeSortLinked<int> &sort) {
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
  sort.insert(125);
}

void test_sort_ascending() {
  // Test selection sort in ascending order

  mergeSortLinked<int> sort;
  fill_data(sort);

  cout << "Before sorting in ascending order: " << endl;
  sort.print();

  cout << "After sorting in ascending order: " << endl;
  sort.merge_sort_asc();
  sort.print();
}

int main() {
  test_sort_ascending();
  return 0;
}
