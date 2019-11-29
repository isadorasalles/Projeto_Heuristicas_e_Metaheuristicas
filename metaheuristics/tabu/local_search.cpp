#include <bits/stdc++.h>
#include <vector>

using namespace std;

int max_degree(vector <vector <int > > G, vector <int> visited, vector <int> Set);
vector <int> find_neighbors(vector <vector <int> > G, int v, vector <int> Set);

void n_improvement(vector <vector <int> > G, vector <int> &Set){
	int improvement = 0;
	do {
		improvement = 0;
		for (int i = 0; i < Set.size(); i++){
			int max = i;
			vector <int> nodes = find_neighbors(G, max, Set);
			if (nodes.size() > 1){
				Set.erase(Set.begin()+max);
				for(int i = 0; i < nodes.size(); i++) Set.push_back(nodes[i]);
				improvement = 1;				
			}
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

void _2k_swap(vector <vector <int> > G, vector <int> &Set){
	int improvement = 0;
	do {
		improvement = 0;
     	vector <int> visited;
		for (int i = 0; i <  Set.size(); i++){
			for (int j = 0; j <  Set.size(); j++){
				vector <int> nodes = find_neighbors(G, i, Set);
				vector <int> nodes2 = find_neighbors(G, j, Set);
				if (nodes.size() + nodes2.size() > 2){
					Set.erase(Set.begin()+i);
					Set.erase(Set.begin()+j);
					for(int i = 0; i < nodes.size(); i++) Set.push_back(nodes[i]);
					for(int i = 0; i < nodes2.size(); i++) Set.push_back(nodes2[i]);

					improvement = 1;
				}
			}	
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
			if (j!=v){
				if (G[neighbors[i]][Set[j]] == 1){
					count++;
		  		}
		  		if ((nodes.size() == 1)&&(G[neighbors[i]][nodes[0]] == 1))
		  			count++;
		  	}
		}
		if (count == 0){ 
			it = find (Set.begin(), Set.end(), neighbors[i]);
			if (it == Set.end())
				nodes.push_back(neighbors[i]);
		}
		count = 0;
		if (nodes.size() == 2)
			break;
	}

	return nodes;
}