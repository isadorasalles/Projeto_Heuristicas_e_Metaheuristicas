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
void two_improvement(vector <vector <int> > G, vector <int> &Set);
void three_improvement(vector <vector <int> > G, vector <int> &Set);
vector <int> pertubation(vector <vector <int> > G, vector <int> S);


void tabu(vector <vector <int> > G){
	std::vector<std::vector<int>> tabu_list;
	vector <int> S = greedy_heuristic(G);
	vector <int> aux, best_solution;
	int size, best_size = (int)S.size();

	for (int i = 0; i < TABU; ++i){
		aux  = S;
		two_improvement(G, S);
		if (best_size < (int)S.size()){
			best_size = (int)S.size();
		}
		three_improvement(G, S);
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

	std::cout << best_size << std::endl; 
}

vector <int> pertubation(vector <vector <int> > G, vector <int> S){
	int k = 0;
	vector <int>::iterator it, it2;

	for (int i = 0; i < G.size(); i++){
		vector <int> index;

		int rand_i = rand() % G.size();
		it = find (S.begin(), S.end(), rand_i);

		if (it != S.end()){
			rand_i = i; 
			it = find (S.begin(), S.end(), rand_i);
		}

		if (it == S.end()){
			for (int j = 0; j < S.size(); j++){
				if (G[rand_i][S[j]] == 1){
					it2 = find (index.begin(), index.end(), j);
					if (it2 == index.end())
						index.push_back(j);
				}
			}
			if ((index.size() <= 2)&&(index.size() > 0)){
					k++;
					S.push_back(rand_i);

					sort(index.begin(), index.end(), greater<int>()); 

					for (int j = 0; j < index.size(); j++)
						S.erase(S.begin() + index[j]);
					
			}

		}
		if (k == 4)
			break;
	}
	return S;
}