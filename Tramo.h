#pragma once
#include "Grafo.h"
#include <queue>

using namespace std;

class Tramo {
private:
	vector<int> distA;
	vector<int> distL;
	vector<int> distT;

	void bfs(Grafo const& g, int origen, vector<int>& distancia) {
		// visit se crea local para que se reinicie limpio en cada BFS
		vector<bool> visit(g.V(), false);
		queue<int> q;

		distancia[origen] = 0;
		visit[origen] = true;
		q.push(origen);

		while (!q.empty()) {
			int v = q.front();
			q.pop();

			for (int w : g.ady(v)) {
				if (!visit[w]) {
					distancia[w] = distancia[v] + 1;
					visit[w] = true;
					q.push(w);
				}
			}
		}
	}

public:

	Tramo(const Grafo& g, int A, int L , int T): distA(g.V(), 0), distL(g.V(), 0), distT(g.V(), 0) {
			
		bfs(g, A, distA);
		bfs(g, L, distL);
		bfs(g, T, distT);
	}

	int tramoMasEficiente() const {
		// Inicializamos con el coste del primer nodo (intersección 0)
		int minCoste = distA[0] + distL[0] + distT[0];

		// Buscamos si hay alguna intersección i con menor coste
		for (int i = 1; i < distA.size(); ++i) {
			int costeActual = distA[i] + distL[i] + distT[i];
			if (costeActual < minCoste) {
				minCoste = costeActual;
			}
		}

		return minCoste;
	}
};