#include <bits/stdc++.h>
#include <vector>
#include <cstdio>
#include <ctime>
#include <time.h> 

using namespace std;

int min_degree(vector <vector <int > > G, vector <int> visited);
void remove_v_and_neighbors(vector <vector <int> > &G, int del, vector <int> &visited);
void two_improvement(vector <vector <int> > G, vector <int> &Set);


void greedy_heuristic_aleatorized(vector <vector <int > > G, vector <int> &S){
	int sum = 0;
	vector <int> visited;
	for(int i = 0; i < G.size(); i++)
		visited.push_back(0);

	srand (time(NULL));

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
	/*
	cout << "Vertices que formam o conjunto: ";
	for (int i = 0; i < S.size(); i++)
		cout << S[i] << " ";
	cout << "\n";
	cout << "Tamanho do Conjunto: " << S.size() << "\n";
	*/
	
}

int min_degree(vector <vector <int > > G, vector <int> visited){
	int smallest = 1e5+5;
	int smallest2 = -1;
	int index = 0;
	int index2 = -1;
	int sum = 0;
	int count = 0;

	int rand_i = rand() % 100;
  	rand_i = rand_i%2;

	for(int i = 0; i < G.size(); i++){
		if (visited[i] == 0){
			for (int j = 0; j < G.size(); j++){
				if (visited[j] == 0)
					sum += G[i][j];
			}

			if (sum < smallest){
				count++;
				smallest2 = smallest;
				smallest = sum;
				index2 = index;
				index = i;
			}
			sum = 0;
		}
	}

	if (index2 == -1)
		index2 = index;

	if ((rand_i == 1)&&(count > 2))
		index = index2;
	
	return index;
}

void remove_v_and_neighbors(vector <vector <int> > &G, int del, vector <int> &visited){

	for (int i = 0; i < G.size(); i++)
		if (G[del][i] == 1)
			visited[i] = 1;
	visited[del] = 1;	
}


void grasp(vector <vector <int> > G){
	vector <int> sBest;
	float bestCandidate;
	float candidate;
	std::clock_t start;
    double duration = 0;
    int i = 0;

    start = std::clock();


	while (duration < 10){
		vector <int> S;
		greedy_heuristic_aleatorized(G, S);
		two_improvement(G, S);
  		candidate = S.size();
  		cout << "\nSolucao Candidata: " << candidate << "\n\n";
  		if (i == 0){
  			sBest = S;
  			bestCandidate = candidate;
  		}
  		if (candidate > bestCandidate){
  			sBest = S;
  			bestCandidate = candidate;
  		}
  		i++;
  		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
  	
	}
	cout << "Vertices que formam o conjunto: ";
	for (int i = 0; i < sBest.size(); i++)
		cout << sBest[i] << " ";
	cout << "\n";
	cout << "Tamanho do Conjunto: " << sBest.size() << "\n";
}