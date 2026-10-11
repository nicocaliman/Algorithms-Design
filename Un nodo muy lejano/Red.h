#pragma once
#include "Grafo.h"
#include <queue>

using namespace std;

class Red {
private:
	std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?	
	std::vector<int> dist; // dist[v] = aristas en el camino s-v más corto
	int s;
	int numVisitadas;

	void bfs(Grafo const& g, int TTL) {
		std::queue<int> q;
		dist[s] = 0; visit[s] = true;
		numVisitadas=1;
		q.push(s);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int w : g.ady(v)) {
				if (!visit[w] && dist[v]+1<=TTL) {
					dist[w] = dist[v] + 1; visit[w] = true;
					numVisitadas++;
					q.push(w);
				}
			}
		}
	}

public:

	Red(const Grafo& g, int nodoInicial, int TTL): visit(g.V(), false), dist(g.V()), s(nodoInicial), numVisitadas(0) {
		bfs(g, TTL);
	}

	int numNoVisitadas(const Grafo& g) const {
		return g.V() - numVisitadas;
	}
};
