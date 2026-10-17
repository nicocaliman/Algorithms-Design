
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include "ConjuntosDisjuntos.h" // propios o los de las estructuras de datos de clase

const vector < pair<int, int >> dirs = { {0, 1}, { 1,1 }, { 1,0 }, { 1,-1 }, {0,-1}, {-1,-1}, {-1,0}, {-1,1} };


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool posicionCorrecta(int i, int j, int dimi, int dimj) {
    return i >= 0 && i < dimi&& j >= 0 && j < dimj;
}

void resuelveCaso() {

    // leer los datos de la entrada
    int F, C; cin >> F >> C;

    ConjuntosDisjuntos dsu(F*C);
    vector<vector<bool>> esPetroleo(F, vector<bool>(C, false));
    int maxTam = 0;

    //leemos tablero
    for (int i = 0; i < F; i++)
    {
        for (int j = 0; j < C; j++)
        {
            char simbolo; cin >> simbolo;

            //si es una mancha
            if (simbolo == '#')
            {
                //es mancha
                esPetroleo[i][j] = true;
                if (maxTam == 0) maxTam = 1;

                int u = i * C + j; // Identificador 1D para el DSU

                // Comprobar los 8 vecinos
                for (int w = 0; w < 8; ++w) {
                    int ni = i + dirs[w].first;
                    int nj = j + dirs[w].second;

                    // Si el vecino está dentro del tablero Y ya es petróleo
                    if (posicionCorrecta(ni, nj, F, C) && esPetroleo[ni][nj]) {
                        int v = ni * C + nj;
                        dsu.unir(u, v);
                        maxTam = max(maxTam, dsu.cardinal(u));
                    }
                }
            }
        }
    }

    // 1. Imprimir la superficie de la mancha más grande inicial
    cout << maxTam;

    // 2. Procesar las N imagenes/vertidos adicionales
    int N;
    cin >> N;
    for (int k = 0; k < N; ++k) {
        int r, c;
        cin >> r >> c;
        --r; --c; // Convertir de base 1 a base 0

        // Solo procesamos si la casilla estaba limpia
        if (!esPetroleo[r][c]) {
            esPetroleo[r][c] = true;
            if (maxTam == 0) maxTam = 1;

            int u = r * C + c; // Identificador 1D

            for (int w = 0; w < 8; ++w) {
                int ni = r + dirs[w].first;
                int nj = c + dirs[w].second;

                if (posicionCorrecta(ni, nj, F, C) && esPetroleo[ni][nj]) {
                    int v = ni * C + nj;
                    dsu.unir(u, v);
                    maxTam = max(maxTam, dsu.cardinal(u));
                }
            }
        }

        cout << " " << maxTam;
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
