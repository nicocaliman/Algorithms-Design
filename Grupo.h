#pragma once
#include "Grafo.h"

using namespace std;

class Grupo {
private:
	std::vector<bool>visitado; // visit[v] = ¿hay camino de s a v?	
	vector<int> conocenNoticia;

	void dfs(const Grafo& g, int v, vector<int>& componentes) {
		visitado[v] = true;
		componentes.push_back(v);

		for (int w : g.ady(v)) {
			if (!visitado[w])
			{
				dfs(g, w, componentes);
			}
		}
	}

public:

	Grupo(const Grafo& g): visitado(g.V(), false), conocenNoticia(g.V(), 0) {
		for (int i = 0; i < g.V(); i++)
		{
			if (!visitado[i])
			{
				vector<int> Componentes;
				dfs(g, i, Componentes);
				int tam = Componentes.size();

				for (int u : Componentes) {
					conocenNoticia[u] = tam;
				}
			}
		}
	}

	int conocenLaNoticia(int i) const {
		return conocenNoticia[i];
	}
};