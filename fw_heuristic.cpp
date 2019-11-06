#include <bits/stdc++.h>

using namespace std;

int **G; //grafo global foda-se
int **dist; //graph to store the result of the floyd warshall algorithm
#define INF 99999999;
void init_matrix(int nnodes){
  for (int i = 0; i < nnodes; i++) {
    for (int j = 0; j < nnodes; j++) {
      if (i==j) {
        G[i][j] = 0;
      }
      else{
        G[i][j] = INF;
      }
      dist[i][j] = G[i][j];
    }
  }
}

void alloc_matrix(int nnodes){
  G = (int **)malloc(nnodes * sizeof(int*));
  dist = (int **)malloc(nnodes * sizeof(int*));
  for(int i = 0; i < nnodes; i++){
      G[i] = (int *)malloc(nnodes * sizeof(int));
    dist[i] = (int *)malloc(nnodes * sizeof(int));
  }
  init_matrix(nnodes);
}

void free_matrix(int nnodes){
  for(int i = 0; i < nnodes; i++){
    free(G[i]);
    free(dist[i]);
  }
  free(G);
  free(dist);
}

void print_matrix(int nnodes){
  for (int i = 0; i < nnodes; i++) {
    for (int j = 0; j < nnodes; j++) {
      cout << dist[i][j] << " ";
    }
    cout << endl;
  }
}
void floyd_warshall(int nodes){
  for (int i = 0; i < nodes; i++) {
    for (int j = 0; j < nodes; j++) {
      for (int k = 0; k < nodes; k++) {
        dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        print_matrix(nodes);
        cout << endl;
      }
    }
  }
}




/* after we run floyd_warshall, do as follows:
1. Select a starting node
2. Select the farthest node from it
2.1 if it forms a independent set, add to solution and go to 3
2.2 else, select the n-nd closest node
3. repeat starting from the last node added to solution
The heuristic returns the size of the independent set found
*/

int heuristic(int nodes, int starting_node){
  // starting_node will be indexed starting from 0
  vector<int> independent_set;
  for (int i = 0; i < nodes; i++) {
    for (int j = 0; j < nodes; j++) {

    }
  }
}

int main(int argc, char const *argv[]) {
  char  e;
  int src,dst,nodes,edges;
  string line;

  ifstream infile(argv[1]);

  getline(infile, line);// reading # of nodes and # of edges
  istringstream iss(line);
  iss >> nodes >> edges;
  alloc_matrix(nodes);
  // read edges
  while(getline(infile, line)){
    istringstream iss(line);
    iss >> e >> src >> dst;
    G[src-1][dst-1] = 1;
    G[dst-1][src-1] = 1;
    dist[src-1][dst-1] = 1;
    dist[dst-1][src-1] = 1;

  }

  floyd_warshall(nodes);

  free_matrix(nodes);
  return 0;
}
