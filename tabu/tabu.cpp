#include <bits/stdc++.h>
#include <vector>
#include <cstdio>
#include <ctime>
#include <time.h> 
#include <algorithm>
#define TABU 555
#define LIST_SIZE 57

using namespace std;

vector <int> greedy_heuristic(vector <vector <int > > G);
void n_improvement(vector <vector <int> > G, vector <int> &Set);
void _2k_swap(vector <vector <int> > G, vector <int> &Set);


void tabu(vector <vector <int> > G){
	std::vector<std::vector<int>> tabu_list;
	vector <int> S = greedy_heuristic(G);
	vector <int> aux, best_solution;
	int size, best_size = (int)S.size();

	for (int i = 0; i < TABU; ++i){
		aux  = S;
		n_improvement(G, S);
		if (best_size < (int)S.size()){
			best_size = (int)S.size();
		}
		_2k_swap(G, S);
		if (best_size < (int)S.size()){
			best_size = (int)S.size();
		}

		// checks if solution is in the tabu list
		for (int j = 0; j < tabu_list.size(); ++j){
			if (tabu_list[i]==S) break;
		}

		if (tabu_list.size() == LIST_SIZE){
			tabu_list.erase(tabu_list.begin());
		}
     	tabu_list.push_back(S);
	}

	best_size = 0;
	for (int i = 0; i < tabu_list.size(); ++i){
		if (tabu_list[i].size() > best_size)
		{
			best_size = tabu_list[i].size();
		}
	}

	std::cout << best_size; 
}