#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef struct{
	int v1;
	int v2;
} edge;


void print_independent_set(vector <int> visited);
vector <edge> create_edge_list(vector <vector <int> > G);
void remove_v_and_neighbors(vector <vector <int> > &G, int del, vector <int> &visited);

void aproximative_independent_set(vector <vector <int> > G){
	vector <edge> E = create_edge_list(G);

	vector <int> visited;
	for (int i = 0; i < G.size(); i++)
		visited.push_back(0);

	vector <int> set;
	for (int i = 0; i < E.size(); i++){
		if ((visited[E[i].v1] == 0)&&(visited[E[i].v2] == 0)){
			visited[E[i].v1] = 1;
			visited[E[i].v2] = 1;
			set.push_back(E[i].v1);
			remove_v_and_neighbors(G, E[i].v1, visited);
		}
	}
	cout << "Vertices que formam o conjunto: ";
	for (int i = 0; i < set.size(); i++)
		cout << set[i] << " ";
	cout << "\n";
	cout << "Tamanho do Conjunto: " << set.size() << "\n";
}

vector <edge> create_edge_list(vector <vector <int> > G){
	vector <edge> E;
	edge e;
	for (int i = 0; i < G.size(); i++)
		for (int j = 0; j < G.size(); j++)
			if (G[i][j] == 1){
				e.v1 = i;
				e.v2 = j;
				E.push_back(e);
			}

	return E;

}
