#pragma once
#include "IndexPQ.h"
#include "DigrafoValorado.h"
#include <limits>

template <typename Valor>
class Dijkstra {
public:
	Dijkstra(DigrafoValorado<Valor> const& g, int o) : 
		dist(g.V(), INF), ulti(g.V()), pq(g.V()), aristasOD(g.V(), 0)
	{
		// Recorremos los vértices y los que estén a true son orígenes
		dist[o] = 0;
		pq.push(o, 0);

		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v))
				relajar(a);
		}
	}
	bool hayCamino(int v) const { return dist[v] != INF; }
	Valor distancia(int v) const { return dist[v]; }
	int aristas(int v) const { return aristasOD[v]; }
private:
	const Valor INF = std::numeric_limits<Valor>::max();
	std::vector<Valor> dist;
	std::vector<AristaDirigida<Valor>> ulti;
	IndexPQ<Valor> pq;
	vector<int> aristasOD;

	void relajar(AristaDirigida<Valor> a) {
		int v = a.desde(); int w = a.hasta();

		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor();
			ulti[w] = a;
			pq.update(w, dist[w]);
			aristasOD[w] = aristasOD[v] + 1;
		}
		else if (dist[w] == dist[v] + a.valor() && aristasOD[v] + 1 < aristasOD[w])
		{
			aristasOD[w] = aristasOD[v] + 1;
		}
	}
};
