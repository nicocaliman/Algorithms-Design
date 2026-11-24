
    /*@ <answer>
     *
     * Nombre y Apellidos:
     *
     *@ </answer> */

    #include <iostream>
    #include <fstream>
    using namespace std;

    #include <limits>
    #include <vector>

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
        int V, S; cin >> V >> S;

        if (!std::cin)  // fin de la entrada
            return false;

        vector<int> sectores(S);

        for (int i = 0; i < S; i++)
        {
            int sector; cin >> sectores[i];
        }

        int n = sectores.size();
        vector<EntInf> sectoresElegidos(V+1, Infinito);
        sectoresElegidos[0] = 0;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = sectores[i-1]; j <= V; ++j)
            {
                sectoresElegidos[j] = min(sectoresElegidos[j], sectoresElegidos[j - sectores[i-1]] + 1);
            }
        }

        vector<int> sol;

        if (sectoresElegidos[V] != Infinito)
        {
            int i = n, j = V;

            while (j > 0)
            {
                if (sectores[i - 1] <= j && sectoresElegidos[j] == sectoresElegidos[j - sectores[i - 1]] + 1)
                {
                    sol.push_back(sectores[i - 1]);
                    j = j - sectores[i - 1];
                }
                else
                    --i;
            }

            cout << sol.size() << ":";

            for (int i = 0; i < sol.size(); i++)
            {
                cout << " " << sol[i];
            }

            cout << "\n";
        }

        else
            cout << "Imposible\n";



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
