
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

#include "Maquina.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

const int TAM = 10000;

Digrafo inicializaGrafo() {
    Digrafo g(TAM);
    for (int i = 0; i < TAM; ++i) {
        g.ponArista(i, (i + 1) % TAM);
        g.ponArista(i, (i * 2) % TAM);
        g.ponArista(i, i / 3);
    }
    return g;
}

void resuelveCaso() {

    // Leer los datos de la entrada
    int marcador, objetivo;
    cin >> marcador >> objetivo;
        
     static Digrafo grafo = inicializaGrafo();

    // Instanciamos la máquina pasándole el grafo y el marcador origen
    Maquina m(grafo, marcador);

    // Mostramos la distancia al objetivo (necesitas un getter en Maquina.h para esto)
    cout << m.distanciaMinima(objetivo) << "\n";
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