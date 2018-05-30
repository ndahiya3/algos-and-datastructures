#include "binary_tree_adt.h"
#include <iostream>

template <class T> binaryTreeADT<T>::binaryTreeADT() { root = nullptr; }

template <class T>
binaryTreeADT<T>::binaryTreeADT(const binaryTreeADT<T> &otherTree) {
  // Copy constructor
  if (otherTree.root == nullptr)
    root = nullptr;
  else
    copy_tree(root, otherTree.root);
}

template <class T>
const binaryTreeADT<T> &binaryTreeADT<T>::
operator=(const binaryTreeADT<T> &otherTree) {
  if (this != &otherTree) {
    if (root != nullptr)
      destroy(root);
    if (otherTree.root == nullptr)
      root = nullptr;
    else
      copy_tree(root, otherTree.root);
  }
  return *this;
}

template <class T> binaryTreeADT<T>::~binaryTreeADT() { destroy(root); }

template <class T> bool binaryTreeADT<T>::is_empty() const {
  return (root == nullptr);
}

template <class T> void binaryTreeADT<T>::inorder_traversal() const {
  inorder(root);
  std::cout << std::endl;
}

template <class T> void binaryTreeADT<T>::preorder_traversal() const {
  preorder(root);
  std::cout << std::endl;
}

template <class T> void binaryTreeADT<T>::postorder_traversal() const {
  postorder(root);
  std::cout << std::endl;
}

template <class T> void binaryTreeADT<T>::levelorder_traversal() const {
  if (root == nullptr)
    return;

  linkedQueue<nodeBT<T> *> Q;
  Q.enqueue(root);

  while (!Q.is_empty()) {
    nodeBT<T> *current = Q.front(); // Visit node
    std::cout << current->data << " ";
    if (current->left != nullptr) // Discover nodes
      Q.enqueue(current->left);
    if (current->right != nullptr)
      Q.enqueue(current->right);
    Q.dequeue();
  }
  std::cout << std::endl;
}

template <class T> int binaryTreeADT<T>::tree_height() const {
  return height(root);
}

template <class T> int binaryTreeADT<T>::tree_node_count() const {
  return node_count(root);
}

template <class T> int binaryTreeADT<T>::tree_leaves_count() const {
  return leaves_count(root);
}

template <class T> void binaryTreeADT<T>::destroy_tree() { destroy(root); }

template <class T> void binaryTreeADT<T>::inorder(nodeBT<T> *p) const {
  if (p != nullptr) {
    inorder(p->left);
    std::cout << p->data << " ";
    inorder(p->right);
  }
}

template <class T> void binaryTreeADT<T>::preorder(nodeBT<T> *p) const {
  if (p != nullptr) {
    std::cout << p->data << " ";
    preorder(p->left);
    preorder(p->right);
  }
}

template <class T> void binaryTreeADT<T>::postorder(nodeBT<T> *p) const {
  if (p != nullptr) {
    postorder(p->left);
    postorder(p->right);
    std::cout << p->data << " ";
  }
}

template <class T> int binaryTreeADT<T>::height(nodeBT<T> *p) const {
  if (p == nullptr)
    return 0;
  else
    return 1 + max(height(p->left), height(p->right));
}

template <class T> int binaryTreeADT<T>::max(int x, int y) const {
  return x >= y ? x : y;
}

template <class T> int binaryTreeADT<T>::node_count(nodeBT<T> *p) const {
  if (p == nullptr)
    return 0;
  else
    return 1 + node_count(p->left) + node_count(p->right);
}

template <class T> int binaryTreeADT<T>::leaves_count(nodeBT<T> *p) const {
  if (p == nullptr)
    return 0;
  if (p->left == nullptr && p->right == nullptr)
    return 1;

  return leaves_count(p->left) + leaves_count(p->right);
}

template <class T>
void binaryTreeADT<T>::copy_tree(nodeBT<T> *&copiedTreeRoot,
                                 nodeBT<T> *otherTreeRoot) {
  if (otherTreeRoot == nullptr)
    copiedTreeRoot = nullptr;
  else {
    copiedTreeRoot = new nodeBT<T>;
    copiedTreeRoot->data = otherTreeRoot->data;
    copy_tree(copiedTreeRoot->left, otherTreeRoot->left);
    copy_tree(copiedTreeRoot->right, otherTreeRoot->right);
  }
}

template <class T> void binaryTreeADT<T>::destroy(nodeBT<T> *&p) {
  if (p != nullptr) {
    destroy(p->left);
    destroy(p->right);
    delete p;
    p = nullptr;
  }
}
