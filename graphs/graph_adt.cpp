#include "graph_adt.h"
#include "linked_queue.h"
#include <istream>
using namespace std;

bool graphType::is_empty() const { return (g_size == 0); }

void graphType::create_graph() {
  // Create graph by reading vertices from file
  // File format:
  // Line 1: #vertices
  // Line 2: 0 2 4 ... -999
  // Line 3: 1 3 6 8 ... -999
  // ...
  // Each line from (2nd line onwards) lists the vertex and the vertices its
  // connected to. End of data is indicated by -999

  ifstream infile;
  char filename[FILENAME_MAX];

  int vertex;
  int adjacent_vertex;

  if (g_size != 0)
    clear_graph();

  cout << "Enter filename: ";
  cin >> filename;
  cout << endl;

  infile.open(filename);

  if (!infile) {
    cout << "Cannot open file." << endl;
    return;
  }
  infile >> g_size;

  for (int index = 0; index < g_size; index++) {
    infile >> vertex;
    infile >> adjacent_vertex;
    while (adjacent_vertex != -999) {
      graph[vertex].insert_back(adjacent_vertex);
      infile >> adjacent_vertex;
    }
  }
  infile.close();
}

void graphType::clear_graph() {
  for (int index = 0; index < g_size; index++)
    graph[index].destroy_list();
  g_size = 0;
}

void graphType::print_graph() {
  for (int index = 0; index < g_size; index++) {
    cout << index << " ";
    graph[index].print();
  }
}

void graphType::depth_first_traversal() {
  // Start traversal at vertex 0. Visit all the vertices
  // reachable from 0 and then start again from the next
  // un-visited vertex and repeat

  bool *visited = new bool[g_size];
  for (int i = 0; i < g_size; i++)
    visited[i] = false;

  for (int index = 0; index < g_size; index++)
    if (!visited[index])
      dft(index, visited);
  delete[] visited;
}

void graphType::dft(int v, bool visited[]) {
  visited[v] = true;
  cout << " " << v << " ";

  linkedListIterator<int> graph_itr;
  for (graph_itr = graph[v].begin(); graph_itr != graph[v].end(); ++graph_itr) {
    int w = *graph_itr;
    if (!visited[w])
      dft(w, visited);
  }
}

void graphType::dft_at_vertex(int vertex) {
  bool *visited = new bool[g_size];
  for (int i = 0; i < g_size; i++)
    visited[i] = false;

  dft(vertex, visited);

  delete[] visited;
}

void graphType::breadth_first_traversal() {
  // Breadth first traversal is similar to level order traversal
  // of binary trees. We start at vertex 0 and visit nodes directly
  // connected to it. Then we visit the nodes directly to the nodes
  // that were connected to 0 and so on...

  linkedQueue<int> Q;
  bool *visited = new bool[g_size];
  for (int i = 0; i < g_size; i++)
    visited[i] = false;

  linkedListIterator<int> graph_itr;

  for (int index = 0; index < g_size; index++) {
    if (!visited[index]) {
      Q.enqueue(index);
      visited[index] = true;
      cout << " " << index << " ";

      while (!Q.is_empty()) {
        int u = Q.front();
        Q.dequeue();

        for (graph_itr = graph[u].begin(); graph_itr != graph[u].end();
             ++graph_itr) {
          int w = *graph_itr;
          if (!visited[w]) {
            Q.enqueue(w);
            visited[w] = true;
            cout << " " << w << " ";
          }
        }
      }
    }
  }
  delete[] visited;
}

graphType::graphType(int size) {
  max_size = size;
  g_size = 0;
  graph = new unorderedLinkedList<int>[max_size];
}

graphType::~graphType() { clear_graph(); }
