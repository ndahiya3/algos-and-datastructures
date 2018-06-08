#include "array_queue.h"
#include <iostream>
using namespace std;

void print_queue(arrayQueue<int> &queue) {
  while (!queue.is_empty()) {
    cout << queue.front() << " ";
    queue.dequeue();
  }
  cout << endl;
}
void test_constructor() {
  arrayQueue<int> queue(10);
  for (int i = 10; i < 21; i++)
    queue.enqueue(i);

  arrayQueue<int> queue2 = queue;
  print_queue(queue2);

  arrayQueue<int> queue3(2);

  queue3 = queue;
  print_queue(queue3);
}

int main() {
  test_constructor();
  return 0;
}
