
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

 Lo que intenta resolver el programa es comprobar si el grafo es libre. Es decir, si es conexo y aciclico. Para ello, vamos a usar un DFS para recorrer el grafo desde un origen S y ver si podemos alcanzar el resto de vertices.

 Para que un grafo sea conexo y sin ciclos debe cumplir que el  numero de aristas sea V() - 1. 

 El coste en tiempo en el peor de los casos de la solucion esta en O(V+A), pues los vertices solo se visitan 1 vez. La comprobación de A == V-1 es O(1) y el bucle final es O(V).

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
