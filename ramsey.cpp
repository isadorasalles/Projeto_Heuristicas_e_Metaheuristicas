#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <time.h>

using namespace std;

int min_degree(vector<vector<int>> G, vector<int> visited){
	for(int i = 0; i < G.size(); i++){
		if (visited[i] == 0){
			return i;
		}
	}
}

void remove_v_and_neighbors(vector <vector <int> > &G, int del, vector <int> &visited){
	for (int i = 0; i < G.size(); i++)
		if (G[del][i] == 1)
			visited[i] = 1;
	visited[del] = 1;	
}

vector <int> remove_v_and_neighbors2(vector <vector <int> > G, int del, vector <int> visited){
	for (int i = 0; i < G.size(); i++)
		if (G[del][i] == 1)
			visited[i] = 1;
	visited[del] = 1;
	return visited;
}


vector <int> comp_remove_v_and_neighbors(vector <vector <int> > G, int del, vector <int> visited){
	for (int i = 0; i < G.size(); i++)
		if (G[del][i] == 0)
			visited[i] = 1;
	visited[del] = 1;
	return visited;
}

vector<int> max_vector(vector<int> a, vector<int> b){
	if(a.size() > b.size()) return a;
	return b;
}

pair<vector<int>,vector<int>> ramsey(std::vector<std::vector<int>> G, vector <int> visited){
	int sum = 0;
	vector <int> C, I;

	for (int i = 0; i < visited.size(); i++) sum += visited[i];
	if (sum == visited.size()) return make_pair(C, I);

    int vertex;
	for (vertex = 0; vertex < visited.size(); vertex++) if(!visited[vertex]) break;

    pair<vector<int>,vector<int>> output = ramsey(G, comp_remove_v_and_neighbors(G, vertex, visited));
	pair<vector<int>,vector<int>> comp_output = ramsey(G, remove_v_and_neighbors2(G, vertex, visited));
	output.first.push_back(vertex);
	comp_output.second.push_back(vertex);
	return make_pair(max_vector(output.first, comp_output.first), max_vector(output.second, comp_output.second));
}

int clique_removal_heuristic(std::vector<std::vector<int>> G){
	std::vector<int> visited((int)G.size(), 0);
	pair<vector<int>,vector<int>> output = ramsey(G, visited);
    vector<int> max_set;
	
	while(true){
		if(output.second.size() > max_set.size()){
			max_set = output.second; 
		}
		for (int k = 0;k < output.second.size(); k++){
			remove_v_and_neighbors(G, k, visited);
		}
	    output = ramsey(G, visited);
		for (int k = 0;k < visited.size(); k++)
			if(!visited[k])
				continue;
		break;
	}

	std::cout << "Vertices que formam o conjunto: ";
	for (int i = 0; i < max_set.size(); i++)
		std::cout << max_set[i] << " ";
	std::cout << "\n";
	std::cout << "Tamnho do Conjunto: " << max_set.size() << "\n";
	return 0;
}

int ramsey_heuristic(std::vector<std::vector<int>> G){
	std::vector<int> visited((int)G.size(), 0);
	pair<vector<int>,vector<int>> output = ramsey(G, visited);
    vector<int> max_set =  output.second; 

	std::cout << "Vertices que formam o conjunto: ";
	for (int i = 0; i < max_set.size(); i++)
		std::cout << max_set[i] << " ";
	std::cout << "\n";
	std::cout << "Tamnho do Conjunto: " << max_set.size() << "\n";
	return 0;
}

int maximal_heuristic(std::vector<std::vector<int>> G){
	int sum = 0;
	std::vector <int> S;
	std::vector<int> visited((int)G.size(), 0);

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
	std::cout << "Vertices que formam o conjunto: ";
	for (int i = 0; i < S.size(); i++)
		std::cout << S[i] << " ";
	std::cout << "\n";
	std::cout << "Tamnho do Conjunto: " << S.size() << "\n";
	return 0;
}

int main(int argc, char *argv[]){
	
	std::ifstream file;
	file.open(argv[1]);
	int v1, v2;
	std::string str;
	int nodes, edges;
	std::vector<std::vector<int>> M;
	
	if (file.is_open()){
		file >> nodes;
			file >> edges;
			for (int j = 0; j < nodes; j++){
				std::vector<int> N;
				for (int i = 0; i < nodes; i++){
					if (i != j)
						N.push_back(1);
					else 
						N.push_back(0);
				}
				M.push_back(N);
			}
		for(int k = 0; k < edges; k++){
            file >> str;
            file >> v1;
            file >> v2;
            M[v1-1][v2-1] = 0;
            M[v2-1][v1-1] = 0;   
		}
	}

    std::clock_t start = std::clock();
	ramsey_heuristic(M);
	clique_removal_heuristic(M);
	double duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

    std::cout << "TEMPO: "<< duration <<'\n';

}