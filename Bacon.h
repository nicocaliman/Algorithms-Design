#pragma once
#include "Grafo.h"
#include <queue>
#include <vector>

using namespace std;

class Bacon {
private:
    vector<int> dist;
    std::vector<bool> visit;

    void bfs(Grafo const& g, int origen) {
        queue<int> q;
        dist[origen] = 0;
        q.push(origen);
        visit[origen] = true;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int w : g.ady(v)) {
                if (!visit[w]) { // Si no ha sido visitado
                    dist[w] = dist[v] + 1;
                    visit[w] = true;
                    q.push(w);
                }
            }
        }
    }

public:
    Bacon(Grafo const& g, int origen) : dist(g.V(), -1), visit(g.V(), false) {
        bfs(g, origen);
    }

    int numBacon(int idActor) const {
        if (idActor >= dist.size() || dist[idActor] == -1) {
            return -1;
        }
        return dist[idActor] / 2; // Dividimos entre 2 por el paso de la película
    }
};