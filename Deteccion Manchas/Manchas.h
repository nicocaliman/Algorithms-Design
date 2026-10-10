#pragma once
#include "Grafo.h"
#include <climits>

using namespace std;

const vector < pair<int, int >> dirs = { {0, 1}, { 1,0 }, { -1,0 }, { 0,-1 }};

class Manchas {
private:
	int F;
	int C;
	std::vector<vector<bool>>visitado; // visit[v] = ¿hay camino de s a v?	
	int numManchas;
	int manchaMasGrande;

	int dfs(const vector<string>& mapa, int i, int j) {
		visitado[i][j] = true;
		int tam = 1;
		
		for (int w = 0; w < 4; w++)
		{
			if (posicionCorrecta(i + dirs[w].first, j + dirs[w].second) && !visitado[i + dirs[w].first][j + dirs[w].second] && mapa[i + dirs[w].first] [j+dirs[w].second] == '#')
			{
				tam += dfs(mapa, i+dirs[w].first, j + dirs[w].second);
			}
		}
		//recorro las cuatro direcciones posibles
		return tam;
	}

	bool posicionCorrecta(int i, int j) const {
		return i >= 0 && i < F && j >= 0 && j < C;
	}

public:
	Manchas(const vector<string>& mapa): F(mapa.size()), C(mapa[0].size()), visitado(F,vector<bool>(C,false)), numManchas(0), manchaMasGrande(0) {
		for (int i = 0; i < F; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (!visitado[i][j] && mapa[i][j] == '#')
				{
					++numManchas;
					int tam = dfs(mapa, i,j);
					manchaMasGrande = max(manchaMasGrande, tam);
				}
			}
		}
	}

	int numeroManchas() const {
		return numManchas;
	}

	int masGrande() const {
		return manchaMasGrande;
	}
};
