
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#pragma once
/*
 * Implementación de matrices (arrays bidimensionales)
 * Copyright (c) 2020  Alberto Verdejo
 * Modificado por 2023 Ignacio Fábregas
 */

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

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

void reconstruir(string const& palabra, Matriz<int> const& patin,
    int i, int j, string& sol) {
    int n = palabra.length();
    if (i > j) return;
    if (i == j) {
        sol.push_back(palabra[i]);
    }
    else if (palabra[i] == palabra[j]) {
        sol.push_back(palabra[i]);
        reconstruir(palabra, patin, i + 1, j - 1, sol);
        sol.push_back(palabra[j]);
    }
    else {
        int cDer = (i + 1 < n && j >= 0 && patin[i + 1][j] != -1) ? patin[i + 1][j] : 0;
        if (patin[i][j] == 1 + cDer) {
            sol.push_back(palabra[i]);
            reconstruir(palabra, patin, i + 1, j, sol);
            sol.push_back(palabra[i]);
        }
        else {
            sol.push_back(palabra[j]);
            reconstruir(palabra, patin, i, j - 1, sol);
            sol.push_back(palabra[j]);
        }
    }
}

int patin_rec(string const& palabra, int i, int j, Matriz<int>& patindromo) {
    int& res = patindromo[i][j];
    if (res == -1) {
        if (i >= j) res = 0;
        else if (palabra[i] == palabra[j])
            res = patin_rec(palabra, i + 1, j - 1, patindromo);
        else
            res = 1 + min(patin_rec(palabra, i + 1, j, patindromo),
                patin_rec(palabra, i, j - 1, patindromo));
    }
    return res;
}

void resuelveCaso() {

    // leer los datos de la entrada
    string palabra; cin >> palabra;

    int n = palabra.size();

    Matriz<int> patindromo(n, n, -1);

    cout << patin_rec(palabra, 0, n - 1, patindromo) << " ";

    string sol;
    reconstruir(palabra, patindromo, 0, n - 1, sol);

    cout << sol << "\n";

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
