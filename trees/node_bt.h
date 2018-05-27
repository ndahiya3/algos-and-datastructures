#ifndef NODE_BT_H
#define NODE_BT_H
/*
 * Node struct for a Binary Tree
 */
template <class T> struct nodeBT {
  T data;
  nodeBT *left;  // Left child
  nodeBT *right; // Right child
}
#endif // NODE_BT_H
