#pragma once
#include "Digrafo.h"

class CicloDirigido {
public:
	CicloDirigido(Digrafo const& g) : visit(g.V(), false), ant(g.V()),
		apilado(g.V(), false), hayciclo(false) {
		dfs(g, 0);
	}
	bool hayCiclo() const { return hayciclo; }

	bool esAlcanzable(int v) const { return visit[v]; }

private:
	std::vector<bool> visit; // visit[v] = ¿se ha alcanzado a v en el dfs?
	std::vector<int> ant; // ant[v] = vértice anterior en el camino a v
	std::vector<bool> apilado; // apilado[v] = ¿está el vértice v en la pila?
	bool hayciclo;

	void dfs(Digrafo const& g, int v) {
		apilado[v] = true;
		visit[v] = true;
		for (int w : g.ady(v)) {
			if (!visit[w]) { // encontrado un nuevo vértice, seguimos
				ant[w] = v; dfs(g, w);
			}
			else if (apilado[w]) { // hemos detectado un ciclo
		 // se recupera retrocediendo
				hayciclo = true;
			}
		}
		apilado[v] = false;
	}
};
