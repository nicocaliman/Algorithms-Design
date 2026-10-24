
/*@ <answer>
 *
 * Nombre y Apellidos: Nicolae Gabriel Caliman
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include "MaximaComponente.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Se pide calcular el tamaño de la mayor componente conexa del grafo.
Se recorre el grafo con DFS: para cada vértice no visitado se lanza un
DFS que recorre toda su componente conexa y devuelve el número de
vértices que ha visitado, es decir, el tamaño de esa componente. Se
mantiene el máximo de todos esos tamaños. Como el vector visit no se
reinicia, cada vértice se visita una sola vez en total.

Coste en tiempo: O(V + A), ya que cada vértice se visita una vez y cada
lista de adyacencia se recorre una vez, sumando todas las componentes.

Coste en espacio adicional: O(V), por el vector visit (tamaño V) y por
la pila de recursión del DFS, que en el peor caso (componente en forma
de camino) alcanza profundidad V.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

void resuelveCaso() {

    // leer los datos de la entrada
    int N, M; cin >> N >> M;

    //Creamos grafo con N vertices
    Grafo g(N);

    //colocamos aristas
    for (int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        g.ponArista(a-1,b-1);
    }

    MaximaComponente maxComponente(g);

    cout << maxComponente.maxiComponente() << "\n";
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
