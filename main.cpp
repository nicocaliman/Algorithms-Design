
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "BFS_Serpientes.h" // propios o los de las estructuras de datos de clase

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
    int N, K, S, E;
    cin >> N >> K >> S >> E;

    int totalCasillas = N * N;

    //Array para serpientes y escaleras
    vector<int> salto(totalCasillas + 1);
    for (int i = 1; i <= totalCasillas; ++i) {
        salto[i] = i; // Por defecto no hay salto
    }

    //Leemos las S serpientes y E escaleras
    for (int i = 0; i < S + E; ++i) {
        int a, b;
        cin >> a >> b;
        salto[a] = b; // Caer en 'a' te lleva a 'b'
    }

    //Creación del grafo 
    Digrafo grafo(totalCasillas + 1);

    //Ponemos las aristas según las tiradas del dado
    for (int u = 1; u <= totalCasillas; ++u) {
        for (int d = 1; d <= K; ++d) { // Dado con caras de 1 a K
            int destino = u + d;
            if (destino <= totalCasillas) {
                int destinoFinal = salto[destino];
                grafo.ponArista(u, destinoFinal);
            }
        }
    }

    // 5. Lanzamos BFS desde la casilla 1 para llegar a totalCasillas
    BFS_Serpientes bfs(grafo, 1);
    cout << bfs.distancia(totalCasillas) << "\n";


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