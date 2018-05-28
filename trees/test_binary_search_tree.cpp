#include "binary_search_tree.h"
#include <iostream>
using namespace std;

void test_bst_traversal() {
  /*
   * Input tree
   *           5
   *         /   \
   *        3     7
   *         \
   *          4
   *
   * After insertion of 6 and 9
   *
   *            5
   *         /     \
   *        3       7
   *         \     / \
   *          4   6   9
   */

  // Inorder    3 4 5 7
  // Preorder   5 3 4 7
  // Postorder  3 4 7 5
  binarySearchTree<int> bst;

  if (bst.is_empty())
    cout << "Tree is empty" << endl;

  if (!bst.search(5))
    cout << "Tree is empty" << endl;

  bst.insert(5);
  bst.insert(3);
  bst.insert(7);
  bst.insert(4);

  cout << "Inorder    3 4 5 7 \t";
  bst.inorder_traversal();

  cout << "Preorder   5 3 4 7 \t";
  bst.preorder_traversal();

  cout << "Postorder  3 4 7 5 \t";
  bst.postorder_traversal();

  cout << "Num leaves: " << bst.tree_leaves_count() << endl;
  cout << "Num nodes:  " << bst.tree_node_count() << endl;

  // Height = number of nodes on longest path from root to a leaf
  cout << "Tree height " << bst.tree_height() << endl;

  // Search

  if (bst.search(3))
    cout << "Found 3" << endl;
  if (bst.search(4))
    cout << "Found 4" << endl;
  if (bst.search(5))
    cout << "Found 5" << endl;
  if (bst.search(7))
    cout << "Found 7" << endl;
  if (!bst.search(10))
    cout << "Didn't Find 10" << endl;

  // Search recursive
  if (bst.search_recursive(3))
    cout << "Found 3" << endl;
  if (bst.search_recursive(4))
    cout << "Found 4" << endl;
  if (bst.search_recursive(5))
    cout << "Found 5" << endl;
  if (bst.search_recursive(7))
    cout << "Found 7" << endl;
  if (!bst.search_recursive(10))
    cout << "Didn't Find 10" << endl;

  // Insert
  bst.insert(9);
  bst.inorder_traversal();
  bst.insert(6);
  bst.inorder_traversal();

  // Delete leaf node
  bst.delete_item(9);
  bst.inorder_traversal();

  // Delete node with only left
  bst.delete_item(7);
  bst.inorder_traversal();

  bst.insert(7);
  bst.insert(9);
  bst.inorder_traversal();

  // Delete node with only right
  bst.delete_item(3);
  bst.inorder_traversal();

  // Delete node with both right and left
  bst.delete_item(7);
  bst.inorder_traversal();
}

int main() {
  test_bst_traversal();
  return 0;
}
