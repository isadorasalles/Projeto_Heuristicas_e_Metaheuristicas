#include <bits/stdc++.h>

using namespace std;

int **G; //grafo global foda-se
int **dist; //graph to store the result of the floyd warshall algorithm
#define INF 99999999

void init_matrix(int nnodes){
  for (int i = 0; i < nnodes; i++) {
    for (int j = 0; j < nnodes; j++) {
      if (i==j) {
        dist[i][j] = 0;
      }
      else{
        dist[i][j] = INF;
      }
       G[i][j] = 1;
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
      cout << G[i][j] << " ";
    }
    cout << endl;
  }
}
void floyd_warshall(int nodes){
  for (int i = 0; i < nodes; i++) {
    for (int j = 0; j < nodes; j++) {
      for (int k = 0; k < nodes; k++) {
        dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
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
bool is_independent_set(vector<int> independent_set, int candidate_node){
  // cout << "tamanho do IS "<<independent_set.size() << endl;
  bool flag_ind_set = true;
  for (int i = 0; i < independent_set.size(); i++) {
    if (G[independent_set[i]][candidate_node]>0) {
      flag_ind_set = false;
    }
  }
  return flag_ind_set;
}


int heuristic(int nodes, int starting_node){
  vector<int> independent_set;

  pair<int,int> top;
  bool is_ind_set;
  int i,j;

  independent_set.push_back(starting_node);
  for (i = starting_node; i < nodes; i++) {
    priority_queue<pair<int,int>> neighbors;

    for (j = i+1; j < nodes; j++) {//only de top diagonal
      if (G[i][j]) {
        neighbors.push(make_pair(dist[i][j],j));
      }
    }
    while (!neighbors.empty()) {
      top = neighbors.top();
      neighbors.pop();
      is_ind_set = is_independent_set(independent_set,top.second);
      if (is_ind_set) {
        independent_set.push_back(top.second);
        break;
      }
    }
  }
  set<int> answer(independent_set.begin(),independent_set.end());
  return answer.size();
}

int main(int argc, char const *argv[]) {
  char  e;
  int src,dst,nodes,edges,cost;
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
    G[src-1][dst-1] = 0;
    G[dst-1][src-1] = 0;
    dist[src-1][dst-1] = 0;
    dist[dst-1][src-1] = 0;

  }
  floyd_warshall(nodes);
  cost = heuristic(nodes,0);
  free_matrix(nodes);
  cout << cost << endl;
  return 0;
}
