#include <bits/stdc++.h>
#include <vector>
#include <cstdio>
#include <ctime>
#include <time.h> 
#include <algorithm>

using namespace std;

vector <int> greedy_heuristic(vector <vector <int > > G);
void two_improvement(vector <vector <int> > G, vector <int> &Set);
vector <int> pertubation(vector <vector <int> > G, vector <int> S);


void iterated_local_search(vector <vector <int> > G){

	vector <int> S = greedy_heuristic(G);
	two_improvement(G, S);

	cout << "Vertices que formam o conjunto: ";
	for (int i = 0; i < S.size(); i++)
		cout << S[i] << " ";
	cout << "\n";
	cout << "Tamanho do Conjunto: " << S.size() << "\n";
	
	vector <int> sBest = S;
	int bestCandidate = S.size();
	int candidate;
	std::clock_t start;
	double duration = 0;

	start = std::clock();

	srand (time(NULL));

	int iterations = 0;

	vector <int> S_;

	while((duration < 120)&&(iterations < 200)){
		S_ = pertubation(G, S);
		cout << "\nPerturbacao: " << S_.size() << "\n\n";
		two_improvement(G, S_);
		candidate = S_.size();
		cout << "\nSolucao Candidata: " << candidate << "\n\n";
		if (candidate >= S.size())
			S = S_;
		if (candidate > bestCandidate){
			sBest = S_;
			bestCandidate = candidate;
		}
		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
		iterations++;
  	}


	cout << "Vertices que formam o conjunto: ";
	for (int i = 0; i < sBest.size(); i++)
		cout << sBest[i] << " ";
	cout << "\n";
	cout << "Tamanho do Conjunto: " << sBest.size() << "\n";


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