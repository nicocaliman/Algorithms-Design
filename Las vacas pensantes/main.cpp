
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


    #pragma once
    /*
     * Implementación de enteros con +infinito.
     * Copyright (c) 2020  Alberto Verdejo
     */

    #ifndef ENTEROSINF_H_
    #define ENTEROSINF_H_

    #include <limits>
    #include <iostream>

    class EntInf {
        int num;
    public:
        static const int _intInf = 1000000000;

        EntInf(int n = 0) : num(n) {}

        EntInf operator+(EntInf const& b) const {
            if (num == _intInf || b.num == _intInf || num >= (_intInf - b.num))
                return _intInf;
            else return num + b.num;
        }

        bool operator==(EntInf const& b) const {
            return num == b.num;
        }

        bool operator!=(EntInf const& b) const {
            return !(*this == b);
        }

        bool operator<(EntInf const& b) const {
            if (num == _intInf) return false;
            else if (b.num == _intInf) return true;
            else return num < b.num;
        }

        bool operator>(EntInf const& b) const {
            return b < *this;
        }

        void print(std::ostream& out = std::cout) const {
            if (num == _intInf) out << "+Inf";
            else out << num;
        }
    };

    const EntInf Infinito(EntInf::_intInf);

    inline std::ostream& operator<<(std::ostream& out, EntInf const& e) {
        e.print(out);
        return out;
    }

    #endif


    /*@ <answer>

     Escribe aquí un comentario general sobre la solución, explicando cómo
     se resuelve el problema y cuál es el coste de la solución, en función
     del tamaño del problema.

     @ </answer> */


     // ================================================================
     // Escribe el código completo de tu solución aquí debajo
     // ================================================================
     //@ <answer>

    int vacas_rec(vector<int> const& cubos, int i, int j, Matriz<int>& dp) {
        if (i > j) return 0;
        if (i == j) return cubos[i];

        int& res = dp[i][j];
        if (res == -1) {
            // Opción 1: nuestra vaca elige el cubo izquierdo (i)
            int comeIzq = cubos[i];
            if (cubos[i + 1] > cubos[j])
                comeIzq += vacas_rec(cubos, i + 2, j, dp);
            else
                comeIzq += vacas_rec(cubos, i + 1, j - 1, dp);

            // Opción 2: nuestra vaca elige el cubo derecho (j)
            int comeDer = cubos[j];
            if (cubos[i] > cubos[j - 1])
                comeDer += vacas_rec(cubos, i + 1, j - 1, dp);
            else
                comeDer += vacas_rec(cubos, i, j - 2, dp);

            res = max(comeIzq, comeDer);
        }
        return res;
    }

    void resuelveCaso() {
        int N;
        cin >> N;

        vector<int> cubos(N);
        for (int i = 0; i < N; ++i) {
            cin >> cubos[i];
        }

        Matriz<int> dp(N, N, -1);
        cout << vacas_rec(cubos, 0, N - 1, dp) << '\n';
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
