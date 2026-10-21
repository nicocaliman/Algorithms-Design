#pragma once
#include "IndexPQ.h"
#include "DIgrafoValorado.h"
#include <limits>

template <typename Valor>
class Dijkstra {
public:
	Dijkstra(DigrafoValorado<Valor> const& g, int orig, const vector<int>& carga) : origen(orig),
		dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
		dist[origen] = carga[origen];
		pq.push(origen, carga[origen]);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v))
				relajar(a, carga);
		}
	}
	bool hayCamino(int v) const { return dist[v] != INF; }
	Valor distancia(int v) const { return dist[v]; }
private:
	const Valor INF = std::numeric_limits<Valor>::max();
	int origen;
	std::vector<Valor> dist;
	std::vector<AristaDirigida<Valor>> ulti;
	IndexPQ<Valor> pq;
	void relajar(AristaDirigida<Valor> a, const vector<int>& carga) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor()+carga[w]) {
			dist[w] = dist[v] + a.valor() + carga[w]; ulti[w] = a;
			pq.update(w, dist[w]);
		}
	}
};
