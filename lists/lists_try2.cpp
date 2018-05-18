/*
 * Simple singly linked list. Test/add/delete/print list
 */
// Delete node at nth position

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* head;

void Delete(int n)
{
  Node* temp1 = head;

  if (n == 1)
    {
      head = temp1->next;
      delete temp1;
      return;
    }
  for (int i = 0; i < n - 2; i++)
    {
      temp1 = temp1->next;
    }
  Node* temp2 = temp1->next;
  temp1->next = temp2->next;
  delete temp2;
}

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
  Delete(1);
  Print();
  Delete(2);
  Print();
  Delete(4);
  Print();
  Delete(4);
  Print();
  Delete(3);
  Print();
  Delete(2);
  Print();
  Delete(1);
  Print();
  return 0;
}
