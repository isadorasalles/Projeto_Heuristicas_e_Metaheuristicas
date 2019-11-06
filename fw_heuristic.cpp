#include <bits/stdc++.h>

using namespace std;

int **G; //grafo global foda-se

void init_matrix(int nnodes){
  for (int i = 0; i < nnodes; i++) {
    for (int j = 0; j < nnodes; j++) {
      G[i][j] = INT_MAX;
    }
  }
}

void alloc_matrix(int nnodes){
  G = (int **)malloc(nnodes * sizeof(int*));
  for(int i = 0; i < nnodes; i++){
    G[i] = (int *)malloc(nnodes * sizeof(int));
  }
  init_matrix(nnodes);
}

void free_matrix(int nnodes){
  for(int i = 0; i < nnodes; i++)
    free(G[i]);
  free(G);
}


void floyd_warshall(int nodes){
  for (int i = 0; i < nodes; i++) {
    for (int j = 0; j < nodes; j++) {
      for (int k = 0; k < nodes; k++) {
        G[i][j] = min(G[i][j],G[i][k]+G[k][j]);
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
*/
void heuristic(int nodes){

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
  }

  floyd_warshall(nodes);
  free_matrix(nodes);
  return 0;
}
