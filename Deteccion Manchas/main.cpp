
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include "Manchas.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Se pide calcular el número de manchas de un mapa y el tamaño de la
mayor. Una mancha es un conjunto de casillas '#' conectadas entre sí
en horizontal o vertical. El mapa se interpreta como un grafo implícito
en el que cada casilla '#' es un vértice y sus vecinos son las cuatro
casillas adyacentes (arriba, abajo, izquierda, derecha) que también
sean '#'.

Se recorre el mapa casilla a casilla. Cada vez que se encuentra una
casilla '#' no visitada, se cuenta una mancha nueva y se lanza un DFS
que recorre toda la mancha y devuelve el número de casillas que ha
visitado, es decir, su tamaño. Se mantiene el máximo de esos tamaños.
Como la matriz visitado no se reinicia, cada casilla se visita una sola
vez en total.

Coste en tiempo: O(F · C), ya que se recorre cada casilla una vez en
el bucle y el DFS visita cada casilla de una mancha una sola vez,
mirando únicamente sus 4 vecinas (coste constante por casilla).

Coste en espacio adicional: O(F · C), por la matriz visitado (F · C
booleanos) y por la pila de recursión del DFS, que en el peor caso
(una mancha que ocupa todo el mapa en forma de serpiente) alcanza
profundidad F · C.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>



void resuelveCaso() {

    // leer los datos de la entrada
    int F, C; cin >> F >> C;

    vector<string> mapa(F);

    for (int i = 0; i < F; i++)
    {
        cin >> mapa[i];
    }

    Manchas manchas(mapa);

    cout << manchas.numeroManchas() << " " << manchas.masGrande() << "\n";

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
