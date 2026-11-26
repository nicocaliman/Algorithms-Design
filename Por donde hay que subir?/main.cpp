
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

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

long long sumaMaxima(const Matriz<int>& matriz, int i, int j, Matriz<long long>& memo)
{
    if (i == 0) {
        memo[i][j] = matriz[0][j];
        return memo[i][j];
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    long long mejorArriba = 0;
    for (int dj = -1; dj <= 1; ++dj) {
        int col = j + dj;
        if (matriz.posCorrecta(i - 1, col)) {
            mejorArriba = max(mejorArriba, sumaMaxima(matriz, i - 1, col, memo));
        }
    }

    memo[i][j] = matriz[i][j] + mejorArriba;
    return memo[i][j];
}

void resuelveCaso() {

    // leer los datos de la entrada
    int N; cin >> N;

    Matriz<int> matriz(N, N, -1);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> matriz[i][j];
        }
    }

    Matriz<long long> memo(N, N, -1);

    long long mejorSuma = -1;
    int mejorColumna = 1;

    for (int j = 0; j < N; ++j) {
        long long actual = sumaMaxima(matriz, N - 1, j, memo);
        if (actual > mejorSuma) {
            mejorSuma = actual;
            mejorColumna = j + 1;
        }
    }

    cout << mejorSuma << " " << mejorColumna << "\n";

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
