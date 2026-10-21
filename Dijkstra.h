#pragma once
#include "IndexPQ.h"
#include "GrafoValorado.h"
#include <limits>

template <typename Valor>
class Dijkstra {
public:
	Dijkstra(GrafoValorado<Valor> const& g, int orig) : origen(orig), caminos(g.V(), 0),
		dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
		dist[origen] = 0;
		caminos[origen] = 1;
		pq.push(origen, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v))
				relajar(a, v);
		}
	}
	bool hayCamino(int v) const { return dist[v] != INF; }
	Valor distancia(int v) const { return dist[v]; }
	int numCaminos(int v) const { return caminos[v]; }
private:
	const Valor INF = std::numeric_limits<Valor>::max();
	int origen;
	vector<int> caminos;
	std::vector<Valor> dist;
	std::vector<Arista<Valor>> ulti;
	IndexPQ<Valor> pq;
	void relajar(Arista<Valor> a, int v) {
		int w = a.otro(v); // w es el vecino opuesto a v
		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor();
			caminos[w] = caminos[v]; // Hereda las formas del camino óptimo anterior
			pq.update(w, dist[w]);
		}
		else if (dist[w] == dist[v] + a.valor()) {
			caminos[w] += caminos[v]; // Acumula formas si encuentra otra ruta con la misma distancia mínima
		}
	}	
};