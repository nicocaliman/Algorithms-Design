
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#pragma once
/*
 * Implementación de matrices (arrays bidimensionales)
 * Copyright (c) 2020  Alberto Verdejo
 * Modificado por 2023 Ignacio Fábregas
 */

#ifndef MATRIZ_H
#define MATRIZ_H

#include <vector>
#include <ostream>

template <typename Object>
class Matriz {
public:
    // crea una matriz con fils filas y cols columnas,
    // con todas sus celdas inicializadas al valor e
    Matriz(int fils = 0, int cols = 0, Object e = Object()) : datos(fils, std::vector<Object>(cols, e)) {}

    // operadores para poder utilizar notación M[i][j]
    std::vector<Object> const& operator[](int f) const {
        return datos[f];
    }

    std::vector<Object>& operator[](int f) {
        return datos[f];
    }

    // Métodos que lanzan una excepción si la posición no existe
    Object const& at(int f, int c) const {
        return datos.at(f).at(c);
    }

    Object& at(int f, int c) {
        return datos.at(f).at(c);
    }

    int numfils() const { return datos.size(); }

    int numcols() const { return numfils() > 0 ? datos[0].size() : 0; }

    bool posCorrecta(int f, int c) const {
        return 0 <= f && f < numfils() && 0 <= c && c < numcols();
    }

private:
    std::vector<std::vector<Object>> datos;
};

//Escritura de la Matriz
template <typename Object>
inline std::ostream& operator<<(std::ostream& out, Matriz<Object> const& m) {
    for (int i = 0; i < m.numfils(); ++i) {
        for (int j = 0; j < m.numcols(); ++j) {
            out << m[i][j] << ' ';
        }
        out << '\n';
    }
    return out;
}

#endif /* MATRIZ_H */


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int colecta_rec(vector<vector<int>> const& pago, int i, int j,
    Matriz<int>& beneficioMaximo) {
    if (beneficioMaximo[i][j] != -1) // subproblema ya resuelto
        return beneficioMaximo[i][j];
    if (i == 0 || j == 0) {
        beneficioMaximo[i][j] = 0;
    }
    else {
        int mejor = colecta_rec(pago, i - 1, j, beneficioMaximo); // 0 cajas al vecino i
        for (int x = 1; x <= 4 && x <= j; ++x) {
            mejor = max(mejor,
                colecta_rec(pago, i - 1, j - x, beneficioMaximo) + pago[x - 1][i - 1]);
        }
        beneficioMaximo[i][j] = mejor;
    }
    return beneficioMaximo[i][j];
}   

void resuelveCaso() {

    // leer los datos de la entrada
    int V, C; cin >> V >> C;
    
    vector<vector<int>> pago(4, vector<int>(V));

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> pago[i][j];
        }
    }

    Matriz<int> beneficioMaximo(V + 1, C + 1, -1);
    int maxBeneficio = colecta_rec(pago, V, C, beneficioMaximo);

    // Reconstrucción de cuántas cajas recibe cada vecino
    vector<int> sol(V, 0);
    int i = V, j = C;
    while (i > 0 && j > 0) {
        for (int x = 0; x <= 4 && x <= j; ++x) {
            int ganancia = (x == 0) ? 0 : pago[x - 1][i - 1];
            if (beneficioMaximo[i][j] == colecta_rec(pago, i - 1, j - x, beneficioMaximo) + ganancia) {
                sol[i - 1] = x;
                j -= x;
                break;
            }
        }
        --i;
    }

    cout << maxBeneficio << '\n';
    for (int k = 0; k < V; ++k) {
        if (k > 0) cout << ' ';
        cout << sol[k];
    }
    cout << '\n';

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