
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

Se pide, para cada usuario, cuántos usuarios acabarían conociendo una
noticia que él publica. Una noticia llega a todos los miembros de los
grupos a los que pertenece quien la publica, y de ahí a todos los
grupos de esos miembros, y así sucesivamente. Por tanto, el número de
usuarios que la conocen es el tamaño de la componente conexa del
usuario en el grafo de usuarios.

Se modela como un grafo no dirigido con un vértice por usuario. Para
cada grupo no hace falta unir a todos los miembros entre sí: basta
unir el primer miembro con cada uno de los demás (una "estrella"), ya
que eso deja a todos los miembros del grupo en la misma componente
conexa y genera muchas menos aristas.

Se recorre el grafo con DFS: para cada vértice no visitado se lanza un
DFS que recoge los vértices de su componente, y a todos ellos se les
asigna el tamaño de esa componente. Como el vector visitado no se
reinicia, cada vértice se visita una sola vez. Después, cada consulta
se responde en O(1).

Sea N el número de usuarios y S la suma de los tamaños de todos los
grupos. El grafo tiene N vértices y A <= S aristas.

Coste en tiempo: O(N + S), ya que construir el grafo cuesta O(S), el
DFS visita cada vértice una vez y recorre cada lista de adyacencia una
vez, y asignar el tamaño a los vértices de cada componente suma O(N)
en total. Imprimir los N resultados es O(N).

Coste en espacio adicional: O(N + S), por el grafo construido (N
listas y A aristas), los vectores visitado y conocenNoticia (tamaño N),
el vector de la componente en curso (como mucho N) y la pila de
recursión del DFS, que en el peor caso (componente en forma de camino)
alcanza profundidad N.

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
