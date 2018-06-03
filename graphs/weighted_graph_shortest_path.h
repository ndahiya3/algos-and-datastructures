#ifndef WEIGHTED_GRAPH_SHORTEST_PATH_H
#define WEIGHTED_GRAPH_SHORTEST_PATH_H

#include "graph_adt.h"
class weightedGraphType : public graphType {
public:
  create_weighted_graph();                 // Create graph and its weight matrix
  void shortest_path_dijkstra(int vertex); // Find shortest path from source to
                                           // every other vertex using Dijkstra
                                           // algo
  void print_shortest_distance() const; // Print shortest path to every vertex
  weightedGraphType(int size = 0);      // Constructor
  ~weightedGraphType();                 // Destructor, free storage

protected:
  double **weights;        // Pointer to create weight matrix
  double *smallest_weight; // Smallest weight from source to vertices
  int source_vertex;
  bool shortest_path_calculated;
};
#endif // WEIGHTED_GRAPH_SHORTEST_PATH_H
