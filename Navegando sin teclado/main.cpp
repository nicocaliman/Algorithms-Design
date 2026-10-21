
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
    int N; cin >> N;

    vector<int> carga(N);

    for (int i = 0; i < N; i++)
    {
        int tiempo; cin >> tiempo;
        carga[i] = tiempo;
    }

    int M; cin >> M;

    DigrafoValorado<int> grafo(N);

    //poner aristas al digrafo
    for (int i = 0; i < M; i++)
    {
        int origen, destino, peso; cin >> origen >> destino >> peso;
        grafo.ponArista({origen-1, destino-1, peso});
    }

    Dijkstra<int> dijk(grafo, 0, carga);

    if (!dijk.hayCamino(N-1))
    {
        cout << "IMPOSIBLE\n";
    }
    else {
        cout << dijk.distancia(N-1) << "\n";
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
