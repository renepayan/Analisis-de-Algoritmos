#include <bits/stdtr1c++.h>
#include "HuffmanTree.hpp"
using namespace std;
nodo crearNodo(char caracter, int concurrencia, int* contador){
    nodo nuevoNodo = new st_nodo(); (*contador)++;
    nuevoNodo->caracter = caracter;(*contador)++;
    nuevoNodo->concurrencia = concurrencia;(*contador)++;
    nuevoNodo->hijoDerecho = nuevoNodo->hijoIzquierdo = nullptr;(*contador)++;
    (*contador)++;
    return nuevoNodo;
}
struct InvertirOrden{
    bool operator() (nodo const &a, nodo const &b) { return a->concurrencia > b->concurrencia; }
};
nodo crearArbolDeHuffman(vector<pair<int,char>> entrada, int *contador){
    priority_queue<nodo, vector<nodo>, InvertirOrden> cola;(*contador)++;
    register int i;
    for(i = 0; i < entrada.size(); i++){
        nodo x = crearNodo(entrada[i].second, entrada[i].first, contador);
        cola.push(x);
    }
    while(cola.size()>1){(*contador)++;
        nodo x = cola.top();(*contador)++;
        cola.pop();(*contador)++;
        nodo y = cola.top();(*contador)++;
        cola.pop();(*contador)++;
        nodo z = crearNodo('-',x->concurrencia+y->concurrencia, contador);(*contador)++;
        z->hijoDerecho = y;(*contador)++;
        z->hijoIzquierdo = x;(*contador)++;
        cola.push(z);(*contador)++;
    }
    (*contador)++;
    (*contador)++;
    return cola.top();
}
vector< pair<int, char> >obtenerConcurrencias(string cadena, int *contador){
    vector<pair<int, char>> retorno;(*contador)++;
    map<char, int> mapa;(*contador)++;
    for(char c: cadena){(*contador)++;
        if(mapa.find(c) == mapa.end()){(*contador)++;
            mapa[c] = 1;(*contador)++;
        }else{(*contador)++;
            mapa[c]+=1;(*contador)++;
        }
    }
    (*contador)++;
    for (auto const& x : mapa){(*contador)++;
        retorno.push_back(make_pair(x.second, x.first));(*contador)++;
    }(*contador)++;
    return retorno;
}

string obtenerBinario(nodo arbol, char caracter, int* contador){
    nodo actual = arbol;
    string retorno = "ENCONTRADO";
    string derecha = "";
    string izquierda = "";
    if(actual->hijoDerecho == nullptr && actual->hijoIzquierdo == nullptr){(*contador)++;
        if(actual->caracter == caracter){(*contador)++;
            retorno = "";(*contador)++;
        }else{(*contador)++;
            retorno = "NADA";(*contador)++;
        }
    }else{(*contador)++;
        izquierda = obtenerBinario(arbol->hijoIzquierdo, caracter, contador);
        derecha = obtenerBinario(arbol->hijoDerecho, caracter, contador);
        if(izquierda != "NADA"){(*contador)++;
            retorno = '0'+izquierda;(*contador)++;
        }else if(derecha!="NADA"){(*contador)++;
            retorno = '1'+derecha;(*contador)++;
        }else{(*contador)++;
            retorno = "NADA";(*contador)++;
        }
    }
    (*contador)++;
    return retorno;
}
string comprimirCadena(nodo arbol, string cadena, int *contador){
    string salida="";(*contador)++;
    for(char c: cadena){(*contador)++;
        salida+=obtenerBinario(arbol, c, contador);(*contador)++;
    }(*contador)++;
    (*contador)++;
    return salida;
}
string descomprimirCadena(nodo arbol, string cadenaComprimida, int *contador){
    register int i;(*contador)++;
    string salida="";(*contador)++;
    for(i = 0; i < cadenaComprimida.length();){(*contador)++;
        nodo actual = arbol;(*contador)++;
        while(actual->hijoIzquierdo != nullptr && actual->hijoDerecho != nullptr){(*contador)++;
            if(cadenaComprimida[i] == '0'){(*contador)++;
                actual = actual->hijoIzquierdo;(*contador)++;
            }else{(*contador)++;
                actual = actual->hijoDerecho;(*contador)++;
            }
            i++;(*contador)++;
        }(*contador)++;
        salida+=actual->caracter;(*contador)++;
    }(*contador)++;
    (*contador)++;
    return salida;
}
vector< pair<int, char> >obtenerConcurrencias(FILE *archivo, int *contador){
    vector<pair<int, char>> retorno;(*contador)++;
    map<char, int> mapa;(*contador)++;
    while(true){(*contador)++;
        char c = fgetc(archivo);(*contador)++;
        (*contador)++;
        if ( c == EOF )
        break ;
        if(mapa.find(c) == mapa.end()){(*contador)++;
            mapa[c] = 1;(*contador)++;
        }else{(*contador)++;
            mapa[c]+=1;(*contador)++;
        }
    }
    (*contador)++;
    for (auto const& x : mapa){(*contador)++;
        retorno.push_back(make_pair(x.second, x.first));(*contador)++;
    }(*contador)++;
    return retorno;
}
void comprimirArchivo(nodo arbol, char *pathArchivoEntrada, char *pathArchivoSalida, int *contador){
    FILE *archivoEntrada, *archivoSalida;
    archivoEntrada = fopen(pathArchivoEntrada,"r");
    archivoSalida = fopen(pathArchivoSalida,"w");
    string cadena = "";
    while(true){(*contador)++;
        char c = fgetc(archivoEntrada);(*contador)++;
        (*contador)++;
        if ( c == EOF )
        break ;
        cadena+=obtenerBinario(arbol, c, contador);(*contador)++;
        int buf = 0;
        if(cadena.length()>=8){(*contador)++;
            for(int i = 0; i < 8 ; i++){(*contador)++;
                if(cadena[i] == '1'){(*contador)++;
                    buf+=(1<<i);(*contador)++;
                }else{(*contador)++;
                }
            }(*contador)++;
            cadena.erase(0,8);(*contador)++;
        }else{(*contador)++;
        }
        char buffer = (char)buf;(*contador)++;
        fprintf(archivoSalida, "%c", buffer);(*contador)++;
    }
    fclose(archivoSalida);
    fclose(archivoEntrada);
}
char* chartobin ( unsigned char c ){
    static char bin[CHAR_BIT + 1] = { 0 };
    int i;
    for ( i = CHAR_BIT - 1; i >= 0; i-- ){
        bin[i] = (c % 2) + '0';
        c /= 2;
    }
    return bin;
}
void descomprimirArchivo(nodo arbol, char *pathArchivoEntrada, char* archivoSalida, int *contador){
    FILE *archivoEntrada;
    register int i;(*contador)++;
    string cadena = "";
    archivoEntrada = fopen(pathArchivoEntrada,"r");
    while(true){(*contador)++;
        char c = fgetc(archivoEntrada);(*contador)++;
        (*contador)++;
        if ( c == EOF )
            break;
        cadena+=chartobin(c);(*contador)++;
    }(*contador)++;
    (*contador)++;
    string salida = descomprimirCadena(arbol, cadena, contador);(*contador)++;
    std::ofstream out(archivoSalida);(*contador)++;
    out << salida;(*contador)++;
    out.close();(*contador)++;
}

