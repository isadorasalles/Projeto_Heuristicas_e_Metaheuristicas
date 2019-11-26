#include <bits/stdc++.h>
#include <vector>

using namespace std;

int min_degree(vector <vector <int > > G, vector <int> visited);
void remove_v_and_neighbors(vector <vector <int> > &G, int del, vector <int> &visited);


void greedy_heuristic(vector <vector <int > > G, vector <int> &S){
	int sum = 0;
	vector <int> visited;
	for(int i = 0; i < G.size(); i++)
		visited.push_back(0);

	while(true){
		int min = min_degree(G, visited);
		S.push_back(min);
		remove_v_and_neighbors(G, min, visited);
		for (int i = 0; i < visited.size(); i++)
			sum += visited[i];
		if (sum == visited.size())
			break;
		sum = 0;
	}
	//cout << "Vertices que formam o conjunto: ";
	//for (int i = 0; i < S.size(); i++)
	//	cout << S[i] << " ";
	//cout << "\n";
	//cout << "Tamnho do Conjunto: " << S.size() << "\n";
	
}

int min_degree(vector <vector <int > > G, vector <int> visited){
	int smallest = 1e5+5;
	int index = 0;
	int sum = 0;
	for(int i = 0; i < G.size(); i++){
		if (visited[i] == 0){
			for (int j = 0; j < G.size(); j++){
				if (visited[j] == 0)
					sum += G[i][j];
			}
			if (sum < smallest){
				smallest = sum;
				index = i;
			}
			sum = 0;
		}
	}
	return index;
}

void remove_v_and_neighbors(vector <vector <int> > &G, int del, vector <int> &visited){

	for (int i = 0; i < G.size(); i++)
		if (G[del][i] == 1)
			visited[i] = 1;
	visited[del] = 1;	
}