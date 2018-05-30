#include "binary_search_tree.h"

template <class T> bool binarySearchTree<T>::search(const T &item) const {
  nodeBT<T> *current;
  bool found = false;

  if (root == nullptr)
    std::cout << "Can't search in empty tree." << std::endl;
  else {
    current = root;
    while (current != nullptr && !found) {
      if (current->data == item)
        found = true;
      else if (current->data > item)
        current = current->left;
      else
        current = current->right;
    }
  }
  return found;
}

template <class T>
bool binarySearchTree<T>::search_recursive(const T &item) const {
  return search_recursive(root, item);
}

template <class T> void binarySearchTree<T>::insert(const T &item) {
  nodeBT<T> *newNode = new nodeBT<T>;
  newNode->data = item;
  newNode->left = nullptr;
  newNode->right = nullptr;

  nodeBT<T> *current;
  nodeBT<T> *trailCurrent;

  if (root == nullptr)
    root = newNode;
  else {
    current = root;
    while (current != nullptr) {
      trailCurrent = current;
      if (current->data == item) {
        std::cout << "Item already exists. Duplicates not allowed."
                  << std::endl;
        return;
      } else if (current->data > item)
        current = current->left;
      else
        current = current->right;
    }
    if (trailCurrent->data > item)
      trailCurrent->left = newNode;
    else
      trailCurrent->right = newNode;
  }
}

template <class T>
bool binarySearchTree<T>::search_recursive(nodeBT<T> *p, const T &item) const {
  if (p == nullptr)
    return false;
  else if (p->data == item)
    return true;
  else if (p->data > item)
    return search_recursive(p->left, item);
  else
    return search_recursive(p->right, item);
}

template <class T> void binarySearchTree<T>::delete_item(const T &item) {
  nodeBT<T> *current;
  nodeBT<T> *trailCurrent;
  bool found = false;

  if (root == nullptr)
    std::cout << "Can't delete from empty tree." << std::endl;
  else {
    // Find node to delete
    // Traverse starting from root
    current = root;
    trailCurrent = root;
    while (current != nullptr && !found) {
      if (current->data == item)
        found = true;
      else {
        trailCurrent = current;
        if (current->data > item)
          current = current->left;
        else
          current = current->right;
      }
    }
    if (!found)
      std::cout << "Item not found in tree." << std::endl;
    else {
      if (current == root)
        delete_node(root);
      else if (trailCurrent->data > item)
        delete_node(trailCurrent->left);
      else
        delete_node(trailCurrent->right);
    }
  }
}

template <class T> void binarySearchTree<T>::delete_node(nodeBT<T> *&p) {

  nodeBT<T> *current;
  nodeBT<T> *trail_current;
  nodeBT<T> *temp;

  if (p == nullptr)
    std::cout << "Node to be deleted is null." << std::endl;
  else if (p->left == nullptr && p->right == nullptr) {
    // Case 1: Both left and right sub-tree empty
    temp = p;
    p = nullptr;
    delete temp;
  } else if (p->left == nullptr) {
    // Case 2: Only right sub-tree non-empty
    temp = p;
    p = p->right;
    delete temp;
  } else if (p->right == nullptr) {
    // Case 3: Only left sub-tree non-empty
    temp = p;
    p = p->left;
    delete temp;
  } else {
    // Case 4: Both left and right sub-trees non-empty
    // Method: Exchange node info with maximum of left sub-tree OR
    // Exchange info with minimum of right sub-tree THEN
    // delete maximum or minimum whose info was exchanged.
    // Before deleting preserve the left sub-tree of node being deleted.
    // We are choosing to use maximum of left sub-tree

    current = p->left; // Root of left sub-tree
    trail_current = nullptr;
    while (current->right != nullptr) { // Find node with desired maximum value
      trail_current = current;          // based on basic property of BST's
      current = current->right;
    }
    p->data = current->data;
    if (trail_current == nullptr) // Current right was empty to begin with
      p->left = current->left;    // Need to preserve the left-subtree
    else
      trail_current->right = current->left;
    delete current;
  }
}

template <class T> T binarySearchTree<T>::min_element() const {
  nodeBT<T> *current = root;
  while (current->left != nullptr)
    current = current->left;

  return current->data;
}

template <class T> T binarySearchTree<T>::max_element() const {
  nodeBT<T> *current = root;
  while (current->right != nullptr)
    current = current->right;

  return current->data;
}
