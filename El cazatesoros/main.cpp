
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

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

void resuelveCaso() {

    // leer los datos de la entrada
    int T; cin >> T;
    int N; cin >> N;

    vector<pair<int, int>> cofres(N);

    for (int i = 0; i < N; i++)
    {
        cin >> cofres[i].first >> cofres[i].second;
    }

    //me construyo primero la matriz
    Matriz<int> beneficioMaximo(N+1, T+1, 0);

    beneficioMaximo[0][0] = 0;
    for (int i = 1; i <= cofres.size(); ++i) {
        beneficioMaximo[i][0] = 0;
        for (int j = 1; j <= T; ++j)
            if (3*cofres[i - 1].first > j)
                beneficioMaximo[i][j] = beneficioMaximo[i - 1][j];
            else
                beneficioMaximo[i][j] = max(beneficioMaximo[i - 1][j], beneficioMaximo[i-1][j - 3*cofres[i - 1].first] + cofres[i-1].second);
    }

    //reconstruyo
    vector<pair<int, int>> cofresRecogidos;
    int i = cofres.size(), j = T;
    while (i > 0 && j > 0) {
        if (3*cofres[i-1].first <= j && beneficioMaximo[i][j] != beneficioMaximo[i - 1][j]) {
            cofresRecogidos.push_back(cofres[i-1]);
            j -= 3*cofres[i-1].first;
        }
        --i;
    }

    cout << beneficioMaximo[N][T] << "\n";
    cout << cofresRecogidos.size() << "\n";

    for (int i = 0; i < cofresRecogidos.size(); i++)
    {
        cout << cofresRecogidos[i].first << " " << cofresRecogidos[i].second << "\n";
    }

    cout << "---\n";
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
