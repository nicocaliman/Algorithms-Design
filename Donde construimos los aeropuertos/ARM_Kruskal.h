#pragma once
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"
#include "GrafoValorado.h"

template <typename Valor>
class ARM_Kruskal {
private:
	std::vector<Arista<Valor>> _ARM;
	Valor coste;
	int nAeropuertos;
public:
	Valor costeARM() const {
		return coste;
	}
	std::vector<Arista<Valor>> const& ARM() const {
		return _ARM;
	}

	int numAeropuertos() const {
		return nAeropuertos;
	}

	ARM_Kruskal(GrafoValorado<Valor> const& g, int precioAeropuerto) : coste(0), nAeropuertos(0) {
		PriorityQueue<Arista<Valor>> pq(g.aristas());
		ConjuntosDisjuntos cjtos(g.V());

		while (!pq.empty()) {
			auto a = pq.top(); pq.pop();
			int v = a.uno(), w = a.otro(v);
			if (!cjtos.unidos(v, w) && a.valor() < precioAeropuerto) {
				cjtos.unir(v, w);
				_ARM.push_back(a); coste += a.valor();	
			}

			if (_ARM.size() == g.V() - 1)
			{
				break;
			}
		}

		coste += precioAeropuerto*cjtos.num_cjtos();
		nAeropuertos = cjtos.num_cjtos();
	}
};
