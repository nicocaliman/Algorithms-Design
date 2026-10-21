#pragma once
#include "IndexPQ.h"
#include "GrafoValorado.h"
#include <limits>
#include <stack>

template <typename Valor>
class Dijkstra {
public:
	Dijkstra(GrafoValorado<Valor> const& g, int orig, int destino) : origen(orig),
		dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
		dist[origen] = 0;
		pq.push(origen, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v))
				relajar(a, v);
		}
	}
	bool hayCamino(int v) const { return dist[v] != INF; }
	Valor distancia(int v) const { return dist[v]; }
	void mostrarCamino(int destino) const {
		
		if (!hayCamino(destino)) {
			cout << "NO LLEGA\n";
			return;
		}
		
		cout << dist[destino] << ": ";
		
		stack<int> pila;
		
		int actual = destino;
		
		while (actual != origen) {
			pila.push(actual);
			auto a = ulti[actual];
			actual = a.otro(actual);
		}
		
		cout << origen + 1;

		while (!pila.empty()) {
			std::cout << " -> " << pila.top() + 1;
			pila.pop();
		}
		
		cout << "\n";
	}
private:
	const Valor INF = std::numeric_limits<Valor>::max();
	int origen;
	std::vector<Valor> dist;
	std::vector<Arista<Valor>> ulti;
	IndexPQ<Valor> pq;
	void relajar(Arista<Valor> a, int v) {
		int w = a.otro(v); // w es el vecino opuesto a v
		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor();
			ulti[w] = a;
			pq.update(w, dist[w]);
		}
	}	
};
