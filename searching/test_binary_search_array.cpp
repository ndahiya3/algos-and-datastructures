#include "binary_search_array.h"
#include <iostream>
using namespace std;

void fill_data(binarySearchArray<int> &search) {
  search.insert(1);
  search.insert(-8);
  search.insert(10);
  search.insert(16);
  search.insert(5);
  search.insert(3);
  search.insert(6000);
  search.insert(-5000);
  search.insert(7);
  search.insert(9);
  search.insert(99);
}

void test_binary_search() {
  // Test binary search both iterative and recursive implementations

  binarySearchArray<int> search;
  fill_data(search);

  search.quick_sort();
  search.print();

  int loc = search.binary_search(-8);
  if (loc != -1)
    cout << "Found -8 at location: " << loc << endl;

  loc = search.binary_search_rec(6000);
  if (loc != -1)
    cout << "Found 6000 at location: " << loc << endl;

  loc = search.binary_search_rec(1200);
  if (loc == -1)
    cout << "Didn't find 1200" << endl;

  loc = search.binary_search(1400);
  if (loc == -1)
    cout << "Didn't find 1400" << endl;

  if (search.is_item_at_equal(10, 6000))
    cout << "is item at testing" << endl;

  loc = search.seq_search(6000);
  if (loc != -1)
    cout << "Found 6000 using sequential search at: " << loc << endl;
}

int main() {
  test_binary_search();
  return 0;
}
