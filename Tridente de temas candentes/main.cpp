/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

#include "IndexPQ.h"

struct Tema {
    int numCitadas;
    int llegadaUltimoEvento;
};

struct ComparadorTemas {
    bool operator()(Tema const& a, Tema const& b) const {
        if (a.numCitadas == b.numCitadas) {
            return a.llegadaUltimoEvento > b.llegadaUltimoEvento; // Más reciente primero[cite: 3]
        }
        return a.numCitadas > b.numCitadas; // Más citas primero
    }
};

/*@ <answer>

 Explicación de la solución:
 Se utiliza una cola de prioridad indexada (IndexPQ) para mantener los temas ordenados
 por su número de citas y por la reciencia de su último evento 'C'[cite: 3].
 Se mantiene un mapeo entre el nombre del tema (string) y su identificador único (int).
 Para las consultas TC se extraen hasta 3 elementos del montículo, se imprimen y se vuelven
 a reinsertar inmediatamente para conservar el estado de la cola.

 Coste:
 - Tiempo: O(N log U), donde N es el número de eventos y U <= N es el número de temas únicos.
   Cada actualización (C o E) y cada extracción de la consulta TC toma O(log U).
 - Espacio: O(U) para almacenar la cola de prioridad, las cadenas y el estado de cada tema.

 @ </answer> */

 //@ <answer>

bool resuelveCaso() {
    int n;
    cin >> n;

    if (!std::cin) // fin de la entrada
        return false;

    unordered_map<string, int> nombre_a_entero;
    IndexPQ<Tema, ComparadorTemas> pq(n + 1);

    // Posición 0 vacía para alinear el vector con IDs base 1
    vector<string> temas(1, "");
    vector<Tema> estadoTemas(n + 1, { 0, 0 });

    int aparicionEvento = 0;

    while (n > 0) {
        string evento;
        cin >> evento;

        // 1. Consulta de podio
        if (evento == "TC") {
            vector<pair<int, Tema>> auxiliar;

            for (int i = 0; i < 3 && !pq.empty(); i++) {
                auto p = pq.top();

                // Si el tema más citado tiene 0 citas, los temas sin citas no cuentan[cite: 3]
                if (p.prioridad.numCitadas <= 0) break;

                pq.pop();
                cout << i + 1 << " " << temas[p.elem] << "\n";
                auxiliar.push_back({ p.elem, p.prioridad });
            }

            // Re-insertar en la cola para no perder el estado
            for (auto const& par : auxiliar) {
                pq.push(par.first, par.second);
            }
        }
        // 2. Eventos C o E
        else {
            string tema;
            int numCitadas;
            cin >> tema >> numCitadas;

            int id;
            if (nombre_a_entero.count(tema) == 0) {
                id = nombre_a_entero.size() + 1;
                nombre_a_entero[tema] = id;
                temas.push_back(tema);
            }
            else {
                id = nombre_a_entero[tema];
            }

            if (evento == "C") {
                estadoTemas[id].numCitadas += numCitadas;
                estadoTemas[id].llegadaUltimoEvento = ++aparicionEvento; // Marca de tiempo de C[cite: 3]
                pq.update(id, estadoTemas[id]);
            }
            else { // evento == "E"
                estadoTemas[id].numCitadas -= numCitadas; // NO modifica llegadaUltimoEvento[cite: 3]
                pq.update(id, estadoTemas[id]);
            }
        }

        n--;
    }

    cout << "---\n";

    return true;
}

//@ </answer>

int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
