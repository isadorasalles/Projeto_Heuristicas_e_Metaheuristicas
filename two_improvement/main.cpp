#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <time.h>

using namespace std;
void greedy_heuristic(vector <vector <int > > G, vector <int> &S);
void two_improvement(vector <vector <int > > G, vector <int> &Set);

int main(int argc, char *argv[]){
	
	ifstream file;
	file.open(argv[1]);
	string str;
	int nodes, edges;
	int v1, v2;
	vector <vector <int> > M;
	
	//sera formado o grafo complementar de cada instancia
	if (file.is_open()){
		file >> nodes;
		file >> edges;
		for (int j = 0; j < nodes; j++){
			vector<int> N;
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
				M[v1-1][v2-1] = 0;   //vertices comecam de 1 nas instancias
				M[v2-1][v1-1] = 0;   
		}
	}


	std::clock_t start;
    double duration;

    start = std::clock();
    vector <int> S;
    greedy_heuristic(M, S);
	two_improvement(M, S);

	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout << "TEMPO: "<< duration <<'\n';

}
