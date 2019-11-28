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


void vnd(vector <vector <int> > G){
	vector <int> S = greedy_heuristic(G);
	// vector <int> S;
	// S.push_back(0);
	vector <int> aux, best_solution;
	int size, best_size = (int)S.size();

	two_improvement(G, S);
	three_improvement(G, S);

	std::cout << S.size(); 
}