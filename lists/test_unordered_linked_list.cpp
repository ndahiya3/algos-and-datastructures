// This program tests various operation of a linked list
// 34 62 21 90 66 53 88 24 10 -999

#include "unordered_linked_list.h" //Line 2
#include <iostream>                //Line 1

using namespace std; // Line 3

void test_insert() {
  unorderedLinkedList<int> list1;
  int num = 10;
  int num_to_insert[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  //  for (int i = 0; i < num; i++)
  //    list1.insert_front(num_to_insert[i]);
  //  cout << "Insert 0 1 2 3 4 5 6 7 8 9 with insert_front: " << endl;
  //  list1.print();

  //  list1.destroy_list();
  //  for (int i = 0; i < num; i++)
  //    list1.insert_back(num_to_insert[i]);
  //  cout << "Insert 0 1 2 3 4 5 6 7 8 9 with insert_back: " << endl;
  //  list1.print();

  list1.destroy_list();
  cout << "Testing insert at:" << endl;
  list1.insert_at(0, -1);
  list1.insert_at(0, 1);

  list1.insert_at(0, 0);
  list1.print();
  list1.destroy_list();

  for (int i = 0; i < num; i++)
    list1.insert_at(num_to_insert[i], 0);
  list1.print();

  list1.destroy_list();
  for (int i = 0; i < num; i++)
    list1.insert_at(num_to_insert[i], i);
  list1.print();

  list1.insert_at(10, 1);
  list1.print();

  list1.insert_at(11, 6);
  list1.print();

  list1.insert_at(12, list1.length());
  list1.print();
}

void test_delete() {
  unorderedLinkedList<int> list1;
  int num = 10;
  int num_to_insert[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  //  list1.delete_front();
  //  list1.delete_back();

  //  list1.insert_front(0);
  //  list1.print();
  //  list1.delete_front();
  //  list1.print();

  //  list1.insert_front(0);
  //  list1.insert_front(1);
  //  list1.print();
  //  list1.delete_front();
  //  list1.print();

  //  list1.destroy_list();

  //  list1.insert_front(0);
  //  list1.print();
  //  list1.delete_back();
  //  list1.print();

  //  list1.insert_back(0);
  //  list1.print();
  //  list1.delete_front();
  //  list1.print();

  //  list1.insert_back(0);
  //  list1.print();
  //  list1.delete_back();
  //  list1.print();

  //  for (int i =0; i< num; i++)
  //    list1.insert_back(num_to_insert[i]);
  //  list1.print();

  //  for (int i = 0; i < num; i++){
  //      //list1.delete_front();
  //      list1.delete_back(); // Discovered bug with this!!
  //      list1.print();
  //    }

  //  list1.insert_front(0);
  //  list1.delete_at(-1);
  //  list1.delete_at(0);
  //  list1.print();

  for (int i = 0; i < num; i++)
    list1.insert_front(num_to_insert[i]);
  list1.print();

  list1.delete_at(
      0); // Discovered bug with this !! (assignment instead of equality :) )
  list1.print();

  list1.delete_at(3); // delete number 5
  list1.print();

  list1.delete_at(4); // delete number 3
  list1.print();

  list1.delete_at(1); // delete number 7
  list1.print();

  list1.delete_at(list1.length() - 1); // delete number 0
  list1.print();

  list1.destroy_list();

  for (int i = 0; i < num; i++)
    list1.insert_front(num_to_insert[i]);
  list1.print();

  for (int i = 0; i < num; i++) {
    list1.delete_at(0);
    list1.print();
  }
}
int main() {
  // test_insert();
  test_delete();
  return 0;
}

void test_ds_malik() {
  unorderedLinkedList<int> list1, list2; // Line 6
  int num;                               // Line 7

  cout << "Line 8: Enter integers ending "
       << "with -999" << endl; // Line 8
  cin >> num;                  // Line 9

  while (num != -999) // Line 10
  {                   // Line 11
    // list1.insert_front(num);                      //Line 12
    list1.insert_front(num);
    cin >> num; // Line 13
  }             // Line 14

  cout << endl; // Line 15

  cout << "Line 16: list1: ";                                     // Line 16
  list1.print();                                                  // Line 17
  cout << endl;                                                   // Line 18
  cout << "Line 19: Length of list1: " << list1.length() << endl; // Line 19

  list2 = list1; // test the assignment operator Line 20

  cout << "Line 21: list2: ";                                     // Line 21
  list2.print();                                                  // Line 22
  cout << endl;                                                   // Line 23
  cout << "Line 24: Length of list2: " << list2.length() << endl; // Line 24

  cout << "Line 25: Enter the number to be "
       << "deleted: "; // Line 25
  cin >> num;          // Line 26
  cout << endl;        // Line 27

  list2.delete_item(num); // Line 28

  cout << "Line 29: After deleting " << num << " list2: " << endl; // Line 29
  list2.print();                                                   // Line 30
  cout << endl;                                                    // Line 31

  cout << "Line 32: Length of list2: " << list2.length() << endl; // Line 32

  cout << endl
       << "Line 33: Output list1 "
       << "using an iterator" << endl; // Line 33

  linkedListIterator<int> it; // Line 34

  for (it = list1.begin(); it != list1.end(); ++it) // Line 35
    cout << *it << " ";                             // Line 36
  cout << endl;                                     // Line 37
}
