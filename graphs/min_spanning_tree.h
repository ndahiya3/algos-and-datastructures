#ifndef MIN_SPANNING_TREE_H
#define MIN_SPANNING_TREE_H
/*
 * Class to create minimum spanning tree of a connected
 * graph using different algorithms.
 */

#include "graph_adt.h"

class msTree : public graphType {
public:
  void create_spanning_graph();  // Create the graph and weight matrix
  void min_spanning(int source); // Create the minimum spanning tree with root
                                 // as source vertex
  void print_tree_and_weight(); // Ouput the edges of the tree and corresponding
                                // weights
  msTree(int size = 0);         // Constructor
  ~msTree();                    // Destructor

protected:
  int source;
  double **weights;
  int *edges;
  double *edge_weights;
};
#endif // MIN_SPANNING_TREE_H
