
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

#include "CicloDirigido.h" // propios o los de las estructuras de datos de clase
#include "OrdenTopologico.h"

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

    // Leer los datos de la entrada
    int N, M; cin >> N >> M;

    Digrafo grafo(N);

    for (int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        grafo.ponArista(a-1,b-1);
    }

    CicloDirigido ciclo(grafo);

    if (ciclo.hayCiclo())
    {
        cout << "Imposible\n";
    }
    else {
        OrdenTopologico tareas(grafo);
        for (int i = 0; i < N; i++) {
            cout << tareas.orden()[i] + 1 << " ";            
        }
        cout << "\n";
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