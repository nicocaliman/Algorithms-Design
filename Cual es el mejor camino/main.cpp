
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

#include "Dijkstra.h" // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

vector<int> bfs(DigrafoValorado<int> const& g, int o) {
    vector<int> calles(g.V(), -1);   // -1 = no visitado / sin camino
    queue<int> q;
    calles[o] = 0;
    q.push(o);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto a : g.ady(v)) {
            int w = a.hasta();
            if (calles[w] == -1) {
                calles[w] = calles[v] + 1;
                q.push(w);
            }
        }
    }
    return calles;
}

void resuelveCaso() {

    // leer los datos de la entrada
    int N, C; cin >> N >> C;

    DigrafoValorado<int> grafo(N);

    for (int i = 0; i < C; i++)
    {
        int origen, destino, valor; cin >> origen >> destino >> valor;

        grafo.ponArista({origen-1, destino-1, valor});
        grafo.ponArista({ destino - 1, origen - 1, valor });
    }

    int k; cin >> k;

    for (int i = 0; i < k; i++)
    {
        int o, d; cin >> o >> d;

        Dijkstra<int> dijk(grafo, o-1);

        if (!dijk.hayCamino(d-1))
        {
            cout << "SIN CAMINO\n";
        }
        else {
            vector<int> minCalles = bfs(grafo, o-1);
            cout << dijk.distancia(d-1) << " "
                << (dijk.aristas(d-1) == minCalles[d-1] ? "SI" : "NO") << "\n";
        }
    }

    cout << "---\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
