#ifndef BIANRY_TREE_ADT_H
#define BIANRY_TREE_ADT_H

/*
 * Abstract base class for Binary Trees.
 * Insert, Delete and Search are specialized operations
 * implemented by derived classes such as Binary Search Trees.
 */

#include "node_bt.h"

template <class T> class binaryTreeADT {
public:
  binaryTreeADT();                                  // Default constructor
  binaryTreeADT(const binaryTreeADT<T> &otherTree); // Copy constructor
  const binaryTreeADT<T> &
  operator=(const binaryTreeADT<T> &otherTree); // Assignment operator
  ~binaryTreeADT();                             // Destructor

  bool is_empty() const; // Check if tree is empty

  void inorder_traversal() const;   // Left sub-tree, Node, Right sub-tree
  void preorder_traversal() const;  // Node, Left sub-tree, Right sub-tree
  void postorder_traversal() const; // Left sub-tree, Right sub-tree, Node

  int tree_height() const;       // Get height of tree
  int tree_node_count() const;   // Number of nodes in tree
  int tree_leaves_count() const; // Number of leaves in tree

  void destroy_tree(); // Delete tree, free storage

protected:
  nodeBT<T> *root;

private:
  void copy_tree(nodeBT<T> *&copiedTreeRoot,
                 nodeBT<T> *otherTreeRoot); // Make deep copy of other tree
  void destroy(nodeBT<T> *&p);              // Destroy tree pointed to by p
  void inorder(nodeBT<T> *p) const;   // Inorder traversal of tree with root p
  void preorder(nodeBT<T> *p) const;  // Preorder traversal of tree with root p
  void postorder(nodeBT<T> *p) const; // Postorder traversal of tree with root p

  int height(nodeBT<T> *p) const;     // Height of tree pointed to by p
  int max(int x, int y) const;        // Max of x and y
  int node_count(nodeBT<T> *p) const; // Number of nodes of tree pointed to by p
  int leaves_count(nodeBT<T> *p) const; // Number of leaves of tree with root p;
};
#endif // BIANRY_TREE_ADT_H
