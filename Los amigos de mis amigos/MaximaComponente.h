#pragma once
#include "Grafo.h"
#include <climits>

using namespace std;

class MaximaComponente {
private:
	std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?		
	int maximaComponente;

	int dfs(Grafo const& G, int v) {
		visit[v] = true;
		int tam = 1;
		for (int w : G.ady(v)) {
			if (!visit[w]) {
				tam += dfs(G,w);
			}
		}

		return tam;
	}

public:
	MaximaComponente(Grafo const& g) : visit(g.V(), false), maximaComponente(0) {
		for (int i = 0; i < g.V(); i++)
		{
			if (!visit[i])
			{
				int tam = dfs(g,i);
				maximaComponente = max(tam, maximaComponente);
			}
		}
	}

	int maxiComponente() const {
		return maximaComponente;
	}
};
