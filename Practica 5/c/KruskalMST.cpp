#include <bits/stdtr1c++.h>
#include "KruskalMST.hpp"
using namespace std;
int calcularMST(Grafo *g, int* contador){
	int mst_wt = 0;(*contador)++;
	g->ordenarAristas();(*contador)++;
	Arbol ds(g->V);(*contador)++;
	vector< pair< int, pair< int, int> > >::iterator it;(*contador)++;
	for (it=g->aristas.begin(); it!=g->aristas.end(); it++) {(*contador)++;

        int u = it->second.first;(*contador)++;
        int v = it->second.second;(*contador)++;

        int set_u = ds.encontrar(u);(*contador)++;
        int set_v = ds.encontrar(v);(*contador)++;

        if (set_u != set_v) {(*contador)++;
            cout << u << " - " << v << endl;
            mst_wt += it->first;(*contador)++;
            ds.unir(set_u, set_v);(*contador)++;
        }
        (*contador)++;
    }
    (*contador)++;
    (*contador)++;
	return mst_wt;
}
