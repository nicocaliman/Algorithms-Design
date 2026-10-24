
/*@ <answer>
 *
 * Nombre y Apellidos: Nicolae Gabriel Caliman
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include "CaminosDFS.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

Un grafo es libre si es conexo y acíclico. Un grafo con V vértices es libre si y solo si es conexo y tiene exactamente V-1 aristas, por lo que no hace falta detectar ciclos explícitamente. Primero se comprueba que A = V-1; si no se cumple, la respuesta es NO. Si se cumple, se hace un DFS desde el vértice 0 y se comprueba que todos los vértices son alcanzables.

Coste en tiempo: O(V + A), ya que el DFS visita cada vértice una vez y recorre cada lista de adyacencia una vez. Coste en espacio adicional: O(V).

Coste en espacio adicional: O(V), por los vectores visit y ant (tamaño V
cada uno) y por la pila de recursión del DFS, que en el peor caso
(grafo en forma de camino) alcanza profundidad V. 
 
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

void resuelveCaso() {

    // leer los datos de la entrada
    int V, A;
    cin >> V >> A;

    //creamos un grafo de v vertices
    Grafo g(V);

    //poner las aristas al grafo 
    for (int i = 0; i < A; i++)
    {
        int a, b; cin >> a >> b;

        g.ponArista(a,b);
    }

    CaminosDFS dfs(g, 0);

    cout << (dfs.esLibre(g) ? "SI\n" : "NO\n");
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
