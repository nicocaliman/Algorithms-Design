
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Grupo.h"  // propios o los de las estructuras de datos de clase

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
    int N, M; cin >> N >> M;

    //creamos un grafo con N vertices
    Grafo g(N);

    //poner aristas
    for (int i = 0; i < M; ++i) {
        int numMiembros;
        cin >> numMiembros;

        if (numMiembros > 0) {
            int primerMiembro;
            cin >> primerMiembro;

            for (int j = 1; j < numMiembros; ++j) {
                int miembro;
                cin >> miembro;
                g.ponArista(primerMiembro-1, miembro-1);
            }
        }
    }

    Grupo grupo(g);
    
    // escribir la solución
    for (int i = 0; i < N; i++)
    {
        cout << grupo.conocenLaNoticia(i) << " ";
    }

    cout << "\n";
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
