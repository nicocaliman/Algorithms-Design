
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, A, B; cin >> N >> A >> B;

    if (!std::cin)  // fin de la entrada
        return false;

    PriorityQueue<int, greater<int>> pA;
    PriorityQueue<int, greater<int>> pB;

    //agregamos al vector las horas que tienen las pilas de la caja A
    for (int i = 0; i < A; i++)
    {
        int horas; cin >> horas;
        pA.push(horas);
    }

    //agregamos al vector las horas que tienen las pilas de la caja B
    for (int i = 0; i < B; i++)
    {
        int horas; cin >> horas;
        pB.push(horas);
    }

    //mientras se puedan poner 2 pilas en el dron
    while (!pA.empty() && !pB.empty())
    {
        int horasTotalesVoladasSabado = 0;

        for (int i = 0; i < N && !pA.empty() && !pB.empty(); i++)
        {
            int hPA = pA.top(); pA.pop();
            int hPB = pB.top(); pB.pop();

            int horasVoladasDron = min(hPA, hPB);

            if (hPA - hPB > 0)
            {
                pA.push(hPA - horasVoladasDron);
            }
            else if (hPB - hPA > 0)
            {
                pB.push(hPB - horasVoladasDron);
            }

            horasTotalesVoladasSabado += horasVoladasDron;
        }

        cout << horasTotalesVoladasSabado << " ";
    }

    cout << "\n";

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
