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

template <class T> class binarySearchTree : public binaryTreeADT<T> {
public:
  bool search(const T &item) const;           // Search given item in tree
  bool search_recursive(const T &item) const; // Recursive search
  void insert(const T &item);                 // Insert given item in tree
  void delete_item(const T &item);            // Delete given item from tree
  T min_element() const;                      // Find minimum element in tree
  T max_element() const;                      // Find maximum element in tree

private:
  void delete_node(nodeBT<T> *&p); // Delete node pointed to by p
  bool search_recursive(nodeBT<T> *p, const T &item) const;

protected:
  using binaryTreeADT<T>::root;
};
#include "binary_search_tree.cpp"
#endif // BINARY_SEARCH_TREE_H
