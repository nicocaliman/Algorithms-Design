/*@ <answer>
 *
 - Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/*@ <answer>

 El problema se resuelve mediante programación dinámica unidimensional. Para
 cada día i (0 <= i < N) con recaudación rec[i], se calcula la recaudación
 máxima sin actuar en dos días consecutivos eligiendo entre no actuar ese
 día (mejor acumulado hasta i-1) o actuar ese día y sumar lo acumulado
 hasta i-2.

 Como cada transición solo consulta los dos estados inmediatamente anteriores,
 se actualiza de forma iterativa en un único recorrido lineal.

 Coste temporal: O(N) por caso de prueba.
 Coste espacial: O(N) para almacenar los datos del caso (O(1) extra en DP).

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

void resuelveCaso() {
    int N;
    if (!(cin >> N)) return;

    vector<long long> rec(N);
    for (int i = 0; i < N; ++i) {
        cin >> rec[i];
    }

    if (N == 1) {
        cout << rec[0] << '\n';
        return;
    }

    long long ant2 = rec[0];                  // máximo hasta día 0
    long long ant1 = max(rec[0], rec[1]);     // máximo hasta día 1

    for (int i = 2; i < N; ++i) {
        long long actual = max(ant1, rec[i] + ant2);
        ant2 = ant1;
        ant1 = actual;
    }

    cout << ant1 << '\n';
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
