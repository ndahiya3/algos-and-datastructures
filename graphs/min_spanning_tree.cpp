#include "min_spanning_tree.h"
#include <cfloat>

void msTree::min_spanning(int sVertex) {

  source = sVertex;
  bool *mstv = new bool[g_size]; // Vertex included in ms tree
  for (int j = 0; j < g_size; j++) {
    mstv[j] = false;
    edges[j] = source;
    edge_weights[j] = weights[source][j];
  }

  mstv[source] = true; // Include source in mst
  edge_weights[source] = 0;

  double min_weight;
  int start_vertex, end_vertex;

  for (int i = 0; i < g_size - 1; i++) {
    min_weight = DBL_MAX;

    // Look at all edges emanating from verteces currently in MST
    // and select the one with minimum weight to be added to MST.
    // Store the added edge and edge weights
    for (int j = 0; j < g_size; j++)
      if (mstv[j])
        for (int k = 0; k < g_size; k++)
          if (!mstv[k] && weights[j][k] < min_weight) {
            end_vertex = k;
            start_vertex = j;
            min_weight = weights[j][k];
          }
    mstv[end_vertex] = true;
    edges[end_vertex] = start_vertex; // Multiple edges could start from a
                                      // vertex but only one can end at a vertex
                                      // in a tree
    edge_weights[end_vertex] = min_weight;
  }
}

void msTree::print_tree_and_weight() {
  double tree_weight = 0;
  std::cout << "Source Vertex " << source << std::endl;
  std::cout << "Edges\tWeight" << std::endl;

  for (int j = 0; j < g_size; j++) {
    if (edges[j] != j) {
      tree_weight += edge_weights[j];
      std::cout << "(" << edges[j] << ", " << j << ")\t" << edge_weights[j]
                << std::endl;
    }
  }
  std::cout << std::endl;
  std::cout << "Minimum Spanning Tree Weight: " << tree_weight << std::endl;
}

msTree::msTree(int size) : graphType(size) {
  weights = new double *[g_size];
  for (int i = 0; i < g_size; i++)
    weights[i] = new double[g_size];
  edges = new int[g_size];
  edge_weights = new double[size];
}

msTree::~msTree() {
  for (int i = 0; i < g_size; i++)
    delete[] weights[i];
  delete[] weights;
  delete[] edges;
  delete[] edge_weights;
}
