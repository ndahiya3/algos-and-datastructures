#ifndef NODED_H
#define NODED_H
/*
 * Node structure for doubly linked list
 */
template <class T>
struct nodeD {
  T data;
  nodeD *prev=nullptr;
  nodeD *next=nullptr;
};
#endif // NODED_H
