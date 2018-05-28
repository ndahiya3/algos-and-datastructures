#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

/*
 * Implementation of Bianry Search Tree derived from
 * Binary Tree base class.
 *
 * Implements:
 *   search
 *   insert
 *   delete
 */

#include "binary_tree_adt.h"

template <class T> class binarySearchTree {
public:
  bool search(const T &item) const;           // Search given item in tree
  bool search_recursive(const T &item) const; // Recursive search
  void insert(const T &item);                 // Insert given item in tree
  void delete_item(const T &item);            // Delete given item from tree

private:
  void delete_node(nodeBT<T> *&p); // Delete node pointed to by p
  void search_recursive(nodeBT<T> *p, const T &item) const;

protected:
  using binaryTreeADT<T>::root;
};
#endif // BINARY_SEARCH_TREE_H
