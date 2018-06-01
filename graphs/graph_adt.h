#ifndef GRAPH_ADT_H
#define GRAPH_ADT_H
/*
 * Graph Abstract Datatype class. Defines basic operations
 * on a graph.
 */
#include "unordered_linked_list.h"

class graphType {
public:
  bool is_empty() const;          // Is the graph empty
  void create_graph();            // Create a new graph with adjacency lists
  void clear_graph();             // Remove all graph vertices
  void print_graph() const;       // Print the graph
  void depth_first_traversal();   // Print vertices using depth first traversal
  void dft_at_vertex(int vertex); // Depth first traversal at given vertex
  void breadth_first_traversal(); // Print graph using breadth first traversal

  graphType(int size = 0); // Constructor with maxsize size
  ~graphType();            // Destructor, deallocate all storage
protected:
  int max_size;                    // Maximum number of vertices
  int g_size;                      // Current number of vertices
  unorderedLinkedList<int> *graph; // Array to create adjacency lists
private:
  void dft(int v, bool visited[]); // Perform depth first traversal at node
                                   // specified by vertex
};
#endif // GRAPH_ADT_H
