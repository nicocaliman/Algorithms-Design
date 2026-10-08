
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <climits>
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

struct Comic
{
    int id;
    int numPila;
};

struct ComparadorComics {
    bool operator()(Comic const& a, Comic const& b) const {
        return a.id < b.id;
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int N; cin >> N;

    if (!std::cin)  // fin de la entrada
        return false;

    PriorityQueue<Comic, ComparadorComics> pq;
    vector<stack<Comic>> pilas;
    int minimo = INT_MAX;
    
    for (int i = 0; i < N; i++)
    {
        int elems; cin >> elems;
        stack<Comic> pila;

        for (int j = 0; j < elems; j++)
        {
            int id; cin >> id;

            if (id < minimo)
            {
                minimo = id;
            }

            pila.push({id,i});
        }

        pilas.push_back(pila);
    }

    // resolver el caso posiblemente llamando a otras funciones
    int contador = 0;

    for (int i = 0; i < N; ++i) {
        if (!pilas[i].empty()) {
            pq.push(pilas[i].top());
        }
    }

    bool encontrado = false;

    while (!encontrado)
    {
        contador++;

        Comic c = pq.top(); pq.pop();

        if (c.id == minimo)
        {
            encontrado = true;
        }
        else {
            pilas[c.numPila].pop();
            if (!pilas[c.numPila].empty())
            {
                pq.push(pilas[c.numPila].top());
            }
        }
    }

    // escribir la solución
    cout << contador << "\n";

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
