
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "CicloDirigido.h"  // propios o los de las estructuras de datos de clase

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
    int L; cin >> L;

    //creamos el digrafo
    Digrafo grafo(L+1);

    //ponemos aristas
    for (int v = 0; v < L; v++)
    {
        char op; cin >> op;

        if (op == 'A')
        {
            grafo.ponArista(v, v + 1);
        }
        else if (op == 'J' || op == 'C')
        {
            int inst; cin >> inst;

            if (op == 'J')
            {
                grafo.ponArista(v, inst-1);
            }
            else {
                grafo.ponArista(v, inst - 1);
                grafo.ponArista(v, v + 1);
            }
        }
    }

    CicloDirigido ciclo(grafo);

    CicloDirigido analisis(grafo);

    // Aplicamos las 3 condiciones
    if (!analisis.esAlcanzable(L)) {
        cout << "NUNCA\n"; 
    }
    else if (analisis.hayCiclo()) {
        cout << "A VECES\n"; 
    }
    else {
        cout << "SIEMPRE\n"; 
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
