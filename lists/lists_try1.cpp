/*
 * Simple singly linked list. Test/add/delete/print list
 */
// Insert a node at nth position

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* head;

void Insert(int data, int n)
{
  Node* temp1 = new Node;

  temp1->data = data;
  temp1->next = nullptr;

  if (n == 1)
    {
      temp1->next = head;
      head = temp1;
      return;
    }
  Node* temp2 = head;
  for (int i = 0; i < n - 2; i++)
    {
      temp2 = temp2->next;
    }
  temp1->next = temp2->next;
  temp2->next = temp1;
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
  Insert(2, 1);
  Insert(3, 1);
  Insert(4, 2);
  Insert(5, 2);
  Insert(6, 3);
  Insert(1, 5);
  Insert(0, 7);
  Print();
  return 0;
}
