#pragma once
#include "Digrafo.h"
#include <queue>
#include <vector>

using namespace std;

class Maquina {
private:
    std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
    std::vector<int> dist; // dist[v] = aristas en el camino s->v más corto
    int s;

    void bfs(Digrafo const& g) {
        std::queue<int> q;
        dist[s] = 0; visit[s] = true;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int w : g.ady(v)) {
                if (!visit[w]) {
                    dist[w] = dist[v] + 1; visit[w] = true;
                    q.push(w);
                }
            }
        }
    }

public:
    Maquina(Digrafo const& g, int s) : visit(g.V(), false), dist(g.V()), s(s) {
        bfs(g);
    }

    int distanciaMinima(int objetivo) const {
        return dist[objetivo];
    }
};
