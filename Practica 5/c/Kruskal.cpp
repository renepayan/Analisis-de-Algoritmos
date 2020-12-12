#include <iostream>
#include "KruskalMST.hpp"
using namespace std;
Grafo* crearGrafoAleatorio(int n, int m){
    Grafo* g = new Grafo(n,m);
    for(int i = 0; i < m; i++){
        int u = rand()%n;
        int v = rand()%n;
        while(u == v){
            v = (rand())%n;
        }
        int peso = rand()%255;
        g->agregarArista(u,v,peso);
    }
    return g;
}
void hacerPruebasConGrafosAleatorios(int limite){
    FILE *resultados;
    resultados = fopen("resultados_kruskal.dat","w");
    for(int i = 2; i < limite; i++){
        int contador = 0;
        Grafo *g = crearGrafoAleatorio(i,i);
        int mst = calcularMST(g,&contador);
        cout<<"Para "<<i<<" El algoritmo termino en "<<contador<<" operaciones\n";
        fprintf(resultados, "%d    %d\n", i, contador);
    }
    fclose(resultados);
}
int main(){
    srand(time(NULL));
    hacerPruebasConGrafosAleatorios(10001);
    return 0;
}
