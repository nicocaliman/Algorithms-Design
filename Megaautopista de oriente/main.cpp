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

 El problema se resuelve mediante programación dinámica de derecha a izquierda
 (i de N-1 a 0) con doble puntero sobre los N puntos kilométricos ordenados.
 Para cada área i, sig[i] guarda el menor índice j > i tal que
 km[j] - km[i] >= K (o N si no existe ninguno compatible a la derecha), y
 ben[i] guarda el beneficio máximo obtenible desde i hasta N-1.

 Como km está ordenado crecientemente y el índice i decrece, el puntero j
 retrocede en total como máximo N veces a lo largo de todo el bucle.
 En la reconstrucción se recorre de izquierda a derecha: si se toma i, se
 guarda km[i] en sol y se salta a sig[i]; en caso contrario, se avanza a i + 1.

 Coste temporal: O(N) por caso de prueba.
 Coste espacial: O(N) memoria adicional.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {
    // leer los datos de la entrada
    int N;
    long long K;
    if (!(cin >> N >> K)) // fin de la entrada
        return false;

    vector<long long> km(N);
    vector<long long> B(N);

    for (int i = 0; i < N; ++i) {
        cin >> km[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    // resolver el caso
    vector<int> sig(N, N);           // siguiente índice compatible desde i
    vector<long long> ben(N + 1, 0); // ben[N] = 0 como caso base
    vector<bool> tomado(N, false);   // indica si se toma el área i en el óptimo

    int j = N;
    for (int i = N - 1; i >= 0; --i) {
        // buscamos el primer compatible desde i hacia la derecha
        while (j > i && km[j - 1] - km[i] >= K) {
            --j;
        }
        sig[i] = j;

        long long tomar = B[i] + ben[sig[i]];
        long long noTomar = ben[i + 1];
        if (tomar >= noTomar) {
            ben[i] = tomar;
            tomado[i] = true;
        }
        else {
            ben[i] = noTomar;
            tomado[i] = false;
        }
    }

    // reconstrucción
    vector<long long> sol;
    int i = 0;
    while (i < N) {
        j = sig[i]; // el siguiente
        if (tomado[i]) {
            // hemos cogido i
            sol.push_back(km[i]);
            i = j;
        }
        else {
            ++i;
        }
    }

    // escribir la solución
    cout << ben[0] << '\n';
    for (size_t idx = 0; idx < sol.size(); ++idx) {
        if (idx > 0) cout << ' ';
        cout << sol[idx];
    }
    cout << '\n';

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
