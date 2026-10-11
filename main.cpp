
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

#include "Bacon.h"  // propios o los de las estructuras de datos de clase

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
    int P;
    cin >> P;

    //creamos el grafo con N nodos
    unordered_map<string, int> nameToId;
    int idActual = 0;
    vector<pair<int, int>> aristas;

    for (int i = 0; i < P; ++i) {
        string peli;
        int numActores;
        cin >> peli >> numActores;

        // 1. Si la película no está en el mapa, le asignamos el siguiente ID
        if (nameToId.count(peli) == 0) {
            nameToId[peli] = idActual;
            idActual++;
        }
        int idPeli = nameToId[peli];

        // 2. Leemos cada actor y hacemos lo mismo
        for (int j = 0; j < numActores; ++j) {
            string actor;
            cin >> actor;

            if (nameToId.count(actor) == 0) {
                nameToId[actor] = idActual;
                idActual++;
            }
            int idActor = nameToId[actor];

            // Guardamos la relación entre película y actor
            aristas.push_back({ idPeli, idActor });
        }
    }

    // Al terminar, idActual tiene el número TOTAL de vértices (películas + actores)
    Grafo g(idActual);
    for (int i = 0; i < aristas.size(); ++i) {
        g.ponArista(aristas[i].first, aristas[i].second);
    }

    int N;
    cin >> N;

    // CASO 1: Kevin Bacon NO está en la base de datos de este caso
    if (nameToId.count("KevinBacon") == 0) {
        for (int i = 0; i < N; ++i) {
            string actor;
            cin >> actor;
            cout << actor << " INF\n";
        }
    }
    // CASO 2: Kevin Bacon SÍ está, hacemos UN solo BFS y respondemos las N consultas
    else {
        int idBacon = nameToId["KevinBacon"];
        Bacon bacon(g, idBacon); // Instanciación normal en la pila

        for (int i = 0; i < N; ++i) {
            string actor;
            cin >> actor;

            if (nameToId.count(actor) == 0) {
                cout << actor << " INF\n";
            }
            else {
                int idActor = nameToId[actor];
                int res = bacon.numBacon(idActor);

                if (res == -1) {
                    cout << actor << " INF\n";
                }
                else {
                    cout << actor << " " << res << "\n";
                }
            }
        }
    }

    cout << "---\n";
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