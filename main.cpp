
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

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
    int edad, parejas; cin >> edad >> parejas;

    if (edad == 0 && parejas == 0)
        return false;

    PriorityQueue<int, greater<int>> pqIz;
    PriorityQueue<int> pqDer;

    pqIz.push(edad);

    for (int i = 0; i < parejas; i++)
    {
        int e1, e2; cin >> e1 >> e2;
     
        if (e1 < pqIz.top())
        {
            pqIz.push(e1);
        }        
        else {
            pqDer.push(e1);
        }

        if (e2 < pqIz.top())
        {
            pqIz.push(e2);
        }
        else {
            pqDer.push(e2);
        }

        //tiene que cumplirse el invariante de un monticulo (diferencias de alturas = 1)
        while (pqIz.size()-pqDer.size() > 1)
        {
            pqDer.push(pqIz.top()); pqIz.pop();
        }
        while (pqDer.size() > pqIz.size())
        {
            pqIz.push(pqDer.top()); pqDer.pop();
        }

        cout << pqIz.top() << " ";
    }

    cout << "\n";

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