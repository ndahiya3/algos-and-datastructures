/*
 * Simple singly linked list. Test/add/delete/print list
 */
// Insert at beginning

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* head;

void Insert(int x)
{
  Node* temp = new Node;

  temp->data = x;
  temp->next = head;
  head = temp;
}

void Print()
{
  Node *temp = head;

  cout << "List is: ";
  while (temp != nullptr)
    {
      cout << temp->data << ' ';
      temp = temp->next;
    }
  cout << endl;
}

int main()
{
  head = nullptr;
  Print(); // Test for print on empty list; Should do nothing
  cout << "How many numbers?\n";
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++)
    {
      cout << "Enter the number\n";
      cin >> x;
      Insert(x);
      Print();
    }
//  cout << endl;
// Sample run: Input n = 5; 2,5,8,1,10
// Output:
// List is: 2
// List is: 5 2
// List is: 8 5 2
// List is: 1 8 5 2
// List is: 10 1 8 5 2
  return 0;
}
