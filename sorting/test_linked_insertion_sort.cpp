#include "insertion_sort_linked.h"
using namespace std;

bool compare_descending(const int &a, const int &b) { return (a > b); }
void fill_data(insertionSortLinked<int> &sort) {
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

  insertionSortLinked<int> sort;
  fill_data(sort);

  cout << "Before sorting in ascending order: " << endl;
  sort.print();

  cout << "After sorting in ascending order: " << endl;
  sort.insertion_sort();
  sort.print();
}

void test_sort_descending() {
  // Test selection sort in descending order

  insertionSortLinked<int> sort;
  fill_data(sort);

  cout << "Before sorting in descending order: " << endl;
  sort.print();

  cout << "After sorting in descending order: " << endl;
  sort.insertion_sort(compare_descending);
  sort.print();
}

int main() {
  test_sort_ascending();
  test_sort_descending();
  return 0;
}
