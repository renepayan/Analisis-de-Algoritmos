/**
 * @author Payán Téllez René
 * @email rpayant1500@alumno.ipn.mx
 * @create date 2020-12-10
 * @modify date 2020-12-11
 * @desc [Este archivo tiene la implementacion del algoritmo de Huffman y todo lo necesario para medir su complejidad temporal]
 */
#include<bits/stdc++.h>
using namespace std;
/**
	Estructura necesaria para definir un grafo, donde V es el numero de vertices o nodos, E el numero de aristas, y aristas la relacion de las aristas y sus pesos
*/
struct Grafo {
    int V, E;
    std::vector< std::pair<int, std::pair<int, int> > > aristas;
	
    Grafo(int V, int E) {
        this->V = V;
        this->E = E;
    }
	/**
	 * Esta funcion agrega un arista al arreglo de aristas
	 * @param {int} [u] nodo origen
	 * @param {int} [v] nodo destino
	 * @param {int} [peso] peso de la union	 
	 */
	void agregarArista(int u, int v, int peso){
		aristas.push_back(std::make_pair(peso, make_pair(u,v)));
	}
	/**
	 * Esta funcion ordena los aristas por su peso 
	 */
	void ordenarAristas(){
        sort(aristas.begin(), aristas.end());
	}
};
/**
	Estructura del union-find
*/
struct Arbol{
    int *parent, *rnk;
    int n;
    Arbol(int n) {
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];
        for (int i = 0; i <= n; i++) {
            rnk[i] = 0;
            parent[i] = i;
        }
    }
	/**
	 * Esta funcion determina, con complejidad amortizada si un arista se encuentra dentro del union-find
	 * @param {int} [u] nodo a buscar
	 * @return {int} El padre del nodo en caso de encontrarlo, de lo contrario nada
	 */
    int encontrar(int u) {
        if (u != parent[u])
            parent[u] = encontrar(parent[u]);
        return parent[u];
    }
	/**
	 * Esta funcion agrega un arista al union-find
	 * @param {int} [x] nodo uno
	 * @param {int} [y] nodo dos	 
	 */
    void unir(int x, int y) {
        x = encontrar(x), y = encontrar(y);
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else
            parent[x] = y;
        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};
/**
 * Esta funcion calcula el MST de un grafo
 * @param {Grafo*} [g] el grafo al cual se le va a obtener el MST
 * @param {int*} [contador] apuntador al contador de operaciones
 * @return {int} el peso del MST del grafo
*/
int calcularMST(Grafo *g, int* contador);
