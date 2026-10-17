
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include "GrafoValorado.h"


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

#include "GrafoValorado.h"

/*@ <answer>

 El problema pide determinar si existe un camino entre dos intersecciones donde todas las
 calles del camino tengan una anchura mayor o igual a la del camión.

 Como el número de consultas K es muy pequeño (K <= 10), realizamos una búsqueda en anchura (BFS)
 por cada consulta a partir del vértice origen. Durante el recorrido BFS, únicamente visitamos
 las aristas con un valor (anchura) >= anchura_camion.

 Coste Temporal: O(K * (V + E)) por caso de prueba. Al ser K <= 10, V <= 10.000 y E <= 100.000,
 la solución procesa alrededor de 10^6 operaciones en el peor caso, ejecutándose holgadamente
 dentro del límite de tiempo.
 Coste Espacial: O(V) por consulta para mantener el vector de visitados y la cola de la BFS.

 @ </answer> */

 // Recorrido BFS que solo transita por aristas con valor >= anchura
void dfs(GrafoValorado<int> const& G, int v, int umbral, vector<bool>& visitado) {
    visitado[v] = true;
    for (auto const& a : G.ady(v)) {
        // El camión solo cabe si la anchura de la calle es mayor o igual a la suya
        if (a.valor() >= umbral) {
            int w = a.otro(v);
            if (!visitado[w]) {
                dfs(G, w, umbral, visitado);
            }
        }
    }
}

void resuelveCaso() {
    int V, E;
    cin >> V >> E;

    GrafoValorado<int> grafo(V);

    for (int i = 0; i < E; ++i) {
        int v, w, valor;
        cin >> v >> w >> valor;
        grafo.ponArista({ v - 1, w - 1, valor }); // Pasar a base 0
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        int origen, destino, anchura;
        cin >> origen >> destino >> anchura;

        // Vector de visitados limpio para cada consulta
        vector<bool> visitado(V, false);
        dfs(grafo, origen - 1, anchura, visitado);

        if (visitado[destino - 1]) {
            cout << "SI\n";
        }
        else {
            cout << "NO\n";
        }
    }
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