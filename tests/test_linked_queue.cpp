#include "linked_queue.h"
#include <iostream>
using namespace std;

void print_queue(linkedQueue<int> &queue) {
  while (!queue.is_empty()) {
    cout << queue.front() << " ";
    queue.dequeue();
  }
  cout << endl;
}
void test_constructor() {
  linkedQueue<int> queue;
  for (int i = 10; i < 21; i++)
    queue.enqueue(i);

  linkedQueue<int> queue2 = queue;
  print_queue(queue2);

  linkedQueue<int> queue3;

  queue3 = queue;
  print_queue(queue3);
}

int main() {
  test_constructor();
  return 0;
}
