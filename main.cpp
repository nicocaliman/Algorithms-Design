
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

struct Tarea {
    int ini;
    int fin;
    int periodo;
};

struct ComparadorTareas {
    bool operator()(Tarea const& a, Tarea const& b) const {
        return a.ini < b.ini;
    }
};

void resuelveCaso() {

    // leer los datos de la entrada
    int N, M, T; cin >> N >> M >> T;
    
    PriorityQueue<Tarea, ComparadorTareas> pq;

    for (int i = 0; i < N; i++)
    {
        int ini, fin; cin >> ini >> fin;
        pq.push({ini, fin, 0});
    }

    for (int i = 0; i < M; i++) {
        int ini, fin, periodo;
        cin >> ini >> fin >> periodo;
        if (ini < T) {
            pq.push({ ini, fin, periodo });
        }
    }

    bool conflicto = false;
    int ultimo_fin = 0;

    // 3. Procesar cronológicamente las tareas
    while (!pq.empty() && !conflicto) {
        Tarea curr = pq.top();
        pq.pop();

        if (curr.ini >= T) {
            break; // Las siguientes tareas empiezan fuera de la ventana de interés
        }

        if (curr.ini < ultimo_fin) {
            conflicto = true; // Se pisan los intervalos
        }
        else {
            ultimo_fin = curr.fin;

            // Si es periódica y vuelve a ocurrir dentro de [0, T), reinsertar
            if (curr.periodo > 0 && curr.ini + curr.periodo < T) {
                pq.push({ curr.ini + curr.periodo, curr.fin + curr.periodo, curr.periodo });
            }
        }
    }

    if (conflicto) cout << "SI\n";
    else cout << "NO\n";
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