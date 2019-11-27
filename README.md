# Heurísticas e Metaheurísticas

## Heurísticas Construtivas
### Literatura
1. Greedy (Isadora)
1. Ramsey (Breno)
1. Clique Removal (Rennan)
### Outras
1. Heurística para vertex cover, o que nao faz parte da cobertura é parte do conjunto independente (Isadora)
1. Baseada no emparelhamento estável (Rennan)
1. Solução exata com um critério de parada x (Breno)

## Metaheurísticas
### Literatura
1. Iterated local search usando busca local (j, k)-swap **  (Isadora)
1. [ILS-VND](https://link.springer.com/content/pdf/10.1007%2Fs11590-017-1128-7.pdf)
1. [Tabu Search para max-clique](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.57.4711&rep=rep1&type=pdf)

### Outras
1. GRASP: solução inicial gulosa aleatorizada + busca local  (Isadora)
1. Tabu Search
1. VND


## Instâncias
Foram utilizadas as instâncias do [Dimacs](http://iridia.ulb.ac.be/~fmascia/maximum_clique/DIMACS-benchmark#detC250.9), que são instâncias para o problema do clique máximo. Como clique máximo é complementar ao conjunto independente máximo, criamos o grafo complementar dessas instâncias e computamos o conjunto independente máximo.
