
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

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

void resuelveCaso() {

    // leer los datos de la entrada
    int N, S, T, P; cin >> N >> S >> T >> P;

    DigrafoValorado<int> grafo(N);

    for (int i = 0; i < P; i++)
    {
        int origen, destino, peso; cin >> origen >> destino >> peso;

        grafo.ponArista({origen-1, destino-1, peso});
    }

    auto g = grafo.inverso();

    Dijkstra<int> dijk(g, S-1, T);
    int ratas = 0;

    for (int i = 0; i < N; i++)
    {
        if (dijk.distancia(i) <= T)
        {
            ratas++;
        }
    }

    cout << ratas - 1 << "\n";
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