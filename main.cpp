
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

#include "Juego.h"  // propios o los de las estructuras de datos de clase

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
    int M, S, T; cin >> M >> S >> T;
        
    int N; cin >> N;

    //me guardo todas las operaciones
    vector<pair<int, int>> operaciones(N);

    //leemos y guardamos las operaciones
    for (int i = 0; i < N;i++)
    {
        int a, b; cin >> a >> b;

        operaciones[i].first = a;
        operaciones[i].second = b;
    }

    //creamos el digrafo con M vertices
    Digrafo grafo(M);

    //ponemos las aristas
    for (int i = 0; i < grafo.V(); i++)
    {
        for (int j = 0; j < N; j++)
        {
            grafo.ponArista(i, (operaciones[j].first*i+operaciones[j].second) % M);
        }
    }

    Juego juego(grafo, S);

    //preguntamos por la distancia minima 
    cout << juego.distanciaMinima(T) << "\n";

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