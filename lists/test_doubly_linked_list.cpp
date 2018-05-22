#include "unordered_doubly_linked_list.h"
#include <iostream>
using namespace std;

void test_insert_remove_iterate() {
  // Test basic functionality of Doubly Linked List
  unorderedDoublyLinkedList<int> list;

  // Empty list tests
  cout << "length is: " << list.length() << endl;
  list.print();
  list.print_reverse();
  // list.front();
  // list.back();
  list.clear();
  list.delete_back();
  list.delete_front();
  list.delete_at(0);
  list.delete_at(-1);
  list.delete_at(2);
  list.delete_item(5);
  list.search(10);
  if (list.is_empty())
    cout << "list is empty.\n";
  else
    cout << "list is not empty as it should be.\n";

  doublyLinkedListIterator<int> it;
  for (it = list.begin(); it != list.end(); ++it)
    cout << *it << ' ';
  cout << endl;

  // Insertion/deletion
  // list.insert_front(5);
  // list.insert_back(5);
  list.insert_at(5, 0);
  cout << list.length() << endl;
  if (list.is_empty())
    cout << "list is empty.\n";
  else
    cout << "list is not empty.\n";
  cout << list.front() << ' ' << list.back() << endl;
  if (list.search(5))
    cout << "Found 5\n";
  if (!list.search(6))
    cout << "Didn't find 6\n";

  // list.delete_back();
  list.delete_at(1);
  list.delete_at(0);
  list.print();

  int n = 10;
  for (int i = 0; i < n; i++)
    list.insert_back(i);
  list.print();
  list.print_reverse();

  for (int i = 0; i < n; i++) {
    list.delete_back();
    list.print();
  }

  for (int i = 0; i < n; i++)
    list.insert_at(i, i);
  list.print();

  list.delete_at(0);
  list.print();

  list.insert_at(90, 9);
  list.print();

  list.delete_item(1);
  list.print();
  list.delete_item(90);
  list.print();
  list.delete_item(7);
  list.print();

  for (it = list.begin(); it != list.end(); ++it)
    cout << *it << ' ';
  cout << endl;

  unorderedDoublyLinkedList<int> list2 = list;
  cout << "list 2\n";
  list2.print();

  unorderedDoublyLinkedList<int> list3 = list;
  list3.print();

  list2.clear();
  list2.insert_front(100);
  list3 = list2;
  list3.print();
}
int main() {
  test_insert_remove_iterate();

  return 0;
}
