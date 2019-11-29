# Heurísticas e Metaheurísticas

## Heurísticas Construtivas
### Literatura
1. Greedy
1. Ramsey
1. Clique Removal 
### Outras
1. Heurística baseada no vertex cover
1. Heurística maximal
1. Heurística utilizando Floyd–Warshall

## Metaheurísticas
### Literatura
1. [Iterated local search usando busca local (j, k)-swap](http://www.resende.info/mauricio/doc/ls-indepset.pdf)
1. [ILS-VND](https://link.springer.com/content/pdf/10.1007%2Fs11590-017-1128-7.pdf)
1. [MNTS](http://www.info.univ-angers.fr/pub/hao/clique.html)

### Outras
1. GRASP
1. Tabu Search
1. VND


## Instâncias
Foram utilizadas as instâncias do [Dimacs](http://iridia.ulb.ac.be/~fmascia/maximum_clique/DIMACS-benchmark#detC250.9), que são instâncias para o problema do clique máximo. Como clique máximo é complementar ao conjunto independente máximo, criamos o grafo complementar dessas instâncias e computamos o conjunto independente máximo.
