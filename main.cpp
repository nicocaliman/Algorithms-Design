
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include "Digrafo.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int V, A; cin >> V >> A;

    if (!std::cin)  // fin de la entrada
        return false;

    Digrafo grafo(V);
    
    for (int i = 0; i < A; i++)
    {
        int a, b; cin >> a >> b;

        grafo.ponArista(a,b);
    }

    bool sumidero = false;
    int vSumidero = -1;

    Digrafo  grafoInverso = grafo.inverso();

    for (int v = 0; v < grafo.V() && !sumidero; v++)
    {
        if ((grafo.ady(v).size() == 0) && (grafoInverso.ady(v).size() == (grafo.V()-1)))
        {
            sumidero = true;
            vSumidero = v;
        }
    }

    if (sumidero)
    {
        cout << "SI " << vSumidero << "\n";
    }
    else {
        cout << "NO\n";
    }

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}