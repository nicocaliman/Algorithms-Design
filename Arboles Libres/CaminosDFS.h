#pragma once
#include "Grafo.h"

class CaminosDFS {
private:
	std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
	std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
	int s; // vértice origen
	void dfs(Grafo const& G, int v) {
		visit[v] = true;
		for (int w : G.ady(v)) {
			if (!visit[w]) {
				ant[w] = v;
				dfs(G, w);
			}
		}
	}

public:
	CaminosDFS(Grafo const& g, int s) : visit(g.V(), false),
		ant(g.V()), s(s) {
		dfs(g, s);
	}
	// ¿hay camino del origen a v?
	bool hayCamino(int v) const {
		return visit[v];
	}

	bool esLibre(Grafo const& g) const {
		
		bool esLibre = true;
		
		if (g.A() != g.V()-1)
		{
			esLibre = false;
		}
		else {

			for (int i = 1; i < g.V() && esLibre; i++)
			{
				if (!hayCamino(i))
				{
					esLibre = false;
				}
			}
		}

		return esLibre;
	}
};
