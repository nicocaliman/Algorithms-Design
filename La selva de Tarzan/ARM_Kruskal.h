#pragma once
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"
#include "GrafoValorado.h"

template <typename Valor>
class ARM_Kruskal {
private:
	std::vector<Arista<Valor>> _ARM;
	Valor coste;
	bool alcanzable;
public:
	Valor costeARM() const {
		return coste;
	}
	std::vector<Arista<Valor>> const& ARM() const {
		return _ARM;
	}

	bool esConexo() const {
		return alcanzable;
	}

	ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0), alcanzable(false) {
		PriorityQueue<Arista<Valor>> pq(g.aristas());
		ConjuntosDisjuntos cjtos(g.V());

		if (g.V() == 1)
		{
			alcanzable = true;
			return;
		}

		while (!pq.empty()) {
			auto a = pq.top(); pq.pop();
			int v = a.uno(), w = a.otro(v);
			if (!cjtos.unidos(v, w)) {
				cjtos.unir(v, w);
				_ARM.push_back(a); coste = a.valor();			
			}

			if (_ARM.size() == g.V() - 1)
			{
				alcanzable = true;
				break;
			}
		}
	}
};
