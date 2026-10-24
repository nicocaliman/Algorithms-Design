
/*@ <answer>
 *
 * Nombre y Apellidos: Nicolae Gabriel Caliman
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include "Red.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Se pide, para varias consultas (nodo inicial, TTL), cuántos nodos de la
red quedan sin recibir un mensaje que se propaga como mucho TTL pasos.
Se modela la red como un grafo no dirigido con N nodos y C conexiones.

Para cada consulta se hace un BFS desde el nodo inicial. El BFS visita
los nodos por niveles, de modo que dist[v] es el número mínimo de
aristas desde el origen. Solo se encolan los nodos con dist <= TTL, así
que el BFS cuenta exactamente los nodos alcanzables dentro del TTL
(incluido el propio origen). La respuesta es N menos ese número.

Coste en tiempo: cada consulta crea los vectores visit y dist (O(N)) y
hace un BFS que visita cada nodo una vez y recorre cada lista de
adyacencia una vez, O(N + C). Con K consultas el coste es O(K·(N + C)),
más O(N + C) de construir el grafo, que queda absorbido.

Coste en espacio adicional: O(N), por los vectores visit y dist (tamaño
N cada uno) y la cola del BFS (como mucho N nodos). La memoria de cada
consulta se libera al terminar, así que no se acumula entre consultas.
Contando también el grafo construido, sería O(N + C).

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

void resuelveCaso() {

    // leer los datos de la entrada
    int N, C; cin >> N >> C;

    //creamos el grafo con N nodos
    Grafo g(N);

    //ponemos las aristas al grafo
    for (int i = 0; i < C; i++)
    {
        int a, b; cin >> a >> b;

        g.ponArista(a-1,b-1);
    }

    int k; cin >> k;

    //hacer consultas
    while (k>0)
    {
        int nodoInicial, TTL; cin >> nodoInicial >> TTL;

        Red red(g, nodoInicial-1, TTL);

        cout << red.numNoVisitadas(g) << "\n";

        --k;
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
