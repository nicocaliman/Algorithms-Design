
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

#include "IndexPQ.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct Pais
{
    string nombre;
    int puntos;
};

struct ComparadorPaises {
    bool operator()(Pais const& a, Pais const& b) const {
        if (a.puntos == b.puntos)
        {
            return a.nombre < b.nombre;
        }

        return a.puntos > b.puntos;
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int N; cin >> N;

    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    unordered_map<string, int> nombre_a_id;
    vector<int> puntosTotales(N,0);

    IndexPQ<Pais, ComparadorPaises> pqVariable(N);
    int id = 0;
    
    while (N>0)
    {
        string cadena; cin >> cadena;

        if (cadena == "?")
        {
            //consulta
            auto top = pqVariable.top(); 

            cout << top.prioridad.nombre << " " << top.prioridad.puntos << "\n";
        }

        else {
            int puntos; cin >> puntos;

            //si es un nuevo pais
            if (nombre_a_id.count(cadena) == 0)
            {
                //insertar en la tabla hash
                nombre_a_id.insert({cadena, id});
                puntosTotales[id] += puntos;
                pqVariable.push( id, {cadena, puntosTotales[id]});
                id++;
            }
            else {
                int id = nombre_a_id[cadena];
                puntosTotales[id] += puntos;

                pqVariable.update(id, { cadena, puntosTotales[id]});
            }
        }

        --N;
    }

    cout << "---\n";

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