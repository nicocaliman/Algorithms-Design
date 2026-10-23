/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "Dijkstra.h"

/*@ <answer>

 Comentario general sobre la solución:
 Se modela el problema utilizando un digrafo valorado bidireccional. Se ejecutan 
 dos algoritmos de Dijkstra multiorigen (uno para las aldeas galas y otro para las romanas).
 Posteriormente, se evalúan todas las aldeas neutrales calculando la diferencia absoluta 
 de distancias a ambos bandos, seleccionando la que minimice dicha diferencia y aplicando 
 la regla de desempate por índice menor.

 Coste: O(C log N) por caso de prueba, donde N es el número de aldeas y C el de caminos.

 @ </answer> */

//@ <answer>

void resuelveCaso() {
    int N, C; 
    if (!(cin >> N >> C)) return;

    DigrafoValorado<int> grafo(N);

    for (int i = 0; i < C; i++) {
        int origen, destino, valor; 
        cin >> origen >> destino >> valor;
        grafo.ponArista({origen - 1, destino - 1, valor});
        grafo.ponArista({destino - 1, origen - 1, valor});
    }

    int G;
    cin >> G;
    vector<bool> galos(N, false);
    for (int i = 0; i < G; i++) {
        int origen;
        cin >> origen;
        galos[origen - 1] = true;
    }

    int R;
    cin >> R;
    vector<bool> romanos(N, false);
    for (int i = 0; i < R; i++) {
        int origen;
        cin >> origen;
        romanos[origen - 1] = true;
    }

    Dijkstra<int> dijkGalos(grafo, galos);
    Dijkstra<int> dijkRomanos(grafo, romanos);

    int mejorAldea = -1;
    int minDiferencia = INT_MAX;

    for (int i = 0; i < N; i++) {
        if (!galos[i] && !romanos[i]) {
            if (dijkGalos.hayCamino(i) && dijkRomanos.hayCamino(i)) {
                int dif = std::abs(dijkGalos.distancia(i) - dijkRomanos.distancia(i));
                if (dif < minDiferencia) {
                    minDiferencia = dif;
                    mejorAldea = i;
                }
            }
        }
    }

    cout << mejorAldea + 1 << " " << minDiferencia << "\n";
}

//@ </answer>

int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    if (std::cin >> numCasos) {
        for (int i = 0; i < numCasos; ++i)
            resuelveCaso();
    }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
