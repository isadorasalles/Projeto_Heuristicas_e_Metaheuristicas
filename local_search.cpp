#include <bits/stdc++.h>
#include <vector>

using namespace std;

int max_degree(vector <vector <int > > G, vector <int> visited, vector <int> Set);
vector <int> find_neighbors(vector <vector <int> > G, int v, vector <int> Set);


void two_improvement(vector <vector <int> > G, vector <int> &Set){
	vector <int> visited;
	for(int i = 0; i < Set.size(); i++)
		visited.push_back(0);
	int size = Set.size();
	vector <int> Set_inc;
	int sum = 0;
	int improvement = 0;

	do {
		improvement = 0;

		int max = max_degree(G, visited, Set);
		vector <int> nodes = find_neighbors(G, max, Set);

		if (nodes.size() == 2){
			Set.erase(Set.begin()+max);
			Set.push_back(nodes[0]);
			Set.push_back(nodes[1]);
			improvement = 1;
		}	

		
	} while (improvement == 1);

	/*
	cout << "Vertices que formam o conjunto: ";
	for (int i = 0; i < Set.size(); i++)
		cout << Set[i] << " ";
	cout << "\n";
	cout << "Tamanho do Conjunto: " << Set.size() << "\n";
	*/
	
}

int max_degree(vector <vector <int > > G, vector <int> visited, vector <int> Set){
	int max = 0;
	int index = 0;
	int sum = 0;
	for(int i = 0; i < Set.size(); i++){
		if (visited[i] == 0){
			for (int j = 0; j < G.size(); j++){
				if (visited[j] == 0)
					sum += G[Set[i]][j];
			}
			if (sum > max){
				max = sum;
				index = i;
			}
			sum = 0;
		}
	}
	return index;
}

vector <int> find_neighbors(vector <vector <int> > G, int v, vector <int> Set){
	vector <int>::iterator it;
	vector <int> nodes;
	vector <int> neighbors;
	int count = 0;

	for (int i = 0; i < G.size(); i++){
		if (G[Set[v]][i] == 1)
  			neighbors.push_back(i);
	}
	
	for (int i = 0; i < neighbors.size(); i++){
		for (int j = 0; j < Set.size(); j++){
			it = find (G[neighbors[i]].begin(), G[neighbors[i]].end(), Set[j]);
  			if (it == G[neighbors[i]].end())
  				count++;
		}
		if (count == Set.size())
			nodes.push_back(neighbors[i]);
		count = 0;
		if (nodes.size() == 2)
			break;
	}
	return nodes;
}