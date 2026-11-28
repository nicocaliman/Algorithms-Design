
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

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

vector<string> leerLista() {
    string linea;
    getline(cin, linea);
    // Por si quedara algún retorno de carro '\r' en ficheros de Windows
    if (!linea.empty() && linea.back() == '\r') {
        linea.pop_back();
    }

    vector<string> lista;
    string actual = "";
    int n = linea.size();
    for (int i = 0; i < n; ++i) {
        if (linea[i] == ' ') {
            if (!actual.empty()) {
                lista.push_back(actual);
                actual = "";
            }
        }
        else {
            actual.push_back(linea[i]);
        }
    }
    if (!actual.empty()) {
        lista.push_back(actual);
    }
    return lista;
}


void resuelveCaso() {
    vector<string> manana = leerLista();
    vector<string> tarde = leerLista();

    int m = manana.size();
    int t = tarde.size();

    Matriz<int> d(m + 1, t + 1, 0);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= t; ++j) {
            if (manana[i - 1] == tarde[j - 1]) {
                d[i][j] = 1 + d[i - 1][j - 1];
            }
            else {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
        }
    }

    vector<string> sol;
    int i = m, j = t;
    while (i > 0 && j > 0) {
        if (manana[i - 1] == tarde[j - 1]) {
            sol.push_back(manana[i - 1]);
            --i;
            --j;
        }
        else if (d[i - 1][j] >= d[i][j - 1]) {
            --i;
        }
        else {
            --j;
        }
    }

    int len = sol.size();
    for (int k = len - 1; k >= 0; --k) {
        if (k < len - 1) cout << ' ';
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
    string aux;
    getline(std::cin, aux);
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
