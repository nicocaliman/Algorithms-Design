#pragma once
#include "IndexPQ.h"
#include "DigrafoValorado.h"
#include <limits>

template <typename Valor>
class Dijkstra {
public:
	Dijkstra(DigrafoValorado<Valor> const& g, int o, int umbral) : 
		dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
		// Recorremos los vértices y los que estén a true son orígenes
		dist[o] = 0;
		pq.push(o, 0);

		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v))
				relajar(a, umbral);
		}
	}
	bool hayCamino(int v) const { return dist[v] != INF; }
	Valor distancia(int v) const { return dist[v]; }
private:
	const Valor INF = std::numeric_limits<Valor>::max();
	std::vector<Valor> dist;
	std::vector<AristaDirigida<Valor>> ulti;
	IndexPQ<Valor> pq;

	void relajar(AristaDirigida<Valor> a, int umbral) {
		int v = a.desde(); int w = a.hasta();

		if (dist[w] > dist[v] + a.valor() && dist[v] + a.valor() <= umbral) {
			dist[w] = dist[v] + a.valor();
			ulti[w] = a;
			pq.update(w, dist[w]);
		}
	}
};
