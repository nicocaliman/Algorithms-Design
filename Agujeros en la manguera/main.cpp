
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include <vector>

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

// Función voraz auxiliar que recibe las posiciones y la longitud del parche
int parches(const vector<int>& agujeros, int L) {
    int parches = 0;
    int cubiertoHasta = -1;

    for (int pos : agujeros) {
        if (pos > cubiertoHasta) {
            parches++;
            cubiertoHasta = pos + L; // El parche cubre desde 'pos' hasta 'pos + L'
        }
    }
    return parches;
}


void resuelveCaso() {

    // leer los datos de la entrada
    int N, L; cin >> N >> L;

    vector<int> agujeros(N);

    for (int i = 0; i < N; i++)
    {
        int longitudAgujero; cin >> longitudAgujero;

        agujeros[i] = longitudAgujero;
    }

    cout << parches(agujeros, L) << "\n";
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
