#include "weighted_graph_shortest_path.h"
#include <cfloat>
#include <iomanip>

void weightedGraphType::shortest_path_dijkstra(int vertex) {
  // Implementation of Dijkstra's algorithm to
  // find shortest path from source vertex to
  // every other vertex in the graph

  // Initialize smallest weight
  for (int i = 0; i < g_size; i++)
    smallest_weight[i] = weights[vertex][i];

  bool *weight_found = new bool[g_size];

  for (int i = 0; i < g_size; i++)
    weight_found[i] = false;

  weight_found[vertex] = true;
  smallest_weight[vertex] = 0;

  for (int i = 0; i < g_size - 1; i++) {
    double min_weight = DBL_MAX;

    // Find vertex v closest to source for which shortest path is yet to be
    // found Keep track of its current weight as min_weight and mark v as vertex
    // for which minimum weight has been found
    int v;
    for (int j = 0; j < g_size; j++)
      if (!weight_found[j])
        if (smallest_weight[j] < min_weight) {
          v = j;
          min_weight = smallest_weight[v];
        }
    weight_found[v] = true;

    // For each vertex w in graph G for which the shortest weight has not been
    // found and an edge from v to w exists, if the weight of path to w through
    // v is smaller than its current weight, then udpate its weight
    for (int j = 0; j < g_size; j++)
      if (!weight_found[j])
        if (min_weight + weights[v][j] < smallest_weight[j])
          smallest_weight[j] = min_weight + weights[v][j];
  }

  source_vertex = vertex;
  shortest_path_calculated = true;
}

void weightedGraphType::print_shortest_distance() const {
  // Print shortest distance from source to every other vertex

  if (!shortest_path_calculated)
    std::cout << "Calculate shortest path first." << std::endl;
  else {
    std::cout << "Source vertex: " << source_vertex << endl;
    std::cout << "Vertex  Shortest_Distance" << std::endl;

    for (int i = 0; i < g_size; i++)
      cout << setw(4) << i << setw(12) << smallest_weight[i] << std::endl;
    std::cout << endl;
  }
}

weightedGraphType::weightedGraphType(int size) : graphType(size) {
  weights = new double *[size];
  for (int i = 0; i < size; i++)
    weights[i] = new double[size];

  smallest_weight = new double[size];
  source_vertex = -1;
  shortest_path_calculated = false;
}

weightedGraphType::~graphType() {
  for (int i = 0; i < g_size; i++)
    delete[] weights[i];
  delete[] weights;
  delete[] smallest_weight;
}
