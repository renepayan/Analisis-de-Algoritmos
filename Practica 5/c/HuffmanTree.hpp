/**
 * @author Payán Téllez René
 * @email rpayant1500@alumno.ipn.mx
 * @create date 2020-12-10
 * @modify date 2020-12-11
 * @desc [Este archivo tiene la implementacion del algoritmo de Huffman y todo lo necesario para medir su complejidad temporal]
 */
#include <bits/stdtr1c++.h>
/**
 * Estructura que almacena los nodos del arbol de huffman, donde concurrencia es la cantidad de apariciones, caratcer el simbolo, y los hijos izquierdo y derecho
*/
struct st_nodo{
    int concurrencia;
    char caracter;
    struct st_nodo *hijoDerecho, *hijoIzquierdo;
};
typedef st_nodo* nodo;

//Funciones generales
/**
 * Esta funcion crea un nodo
 * @param {char} [caracter] simbolo
 * @param {int} [concurrencia] cantidad de apariciones
 * @return {nodo} retorna el nodo generado
*/
nodo crearNodo(char caracter, int concurrencia, int* contador);
/**
 * Esta funcion crea un nodo
 * @param {nodo} [arbol] raiz del arbol
 * @param {char} [caracter] simbolo a buscar dentro del arbol
 * @return {string} retorna el binario del simbolo
*/
std::string obtenerBinario(nodo arbol, char caracter, int* contador);

//Funciones relacionadas al arbol de Huffman
/**
 * Esta funcion crea un arbol de Huffman a partir de un arreglo de simbolos y concurrencias
 * @param {vector<pair<int,char>>} [entrada] arreglo de simbolos y concurrencias
 * @param {int*} [contador] apuntador al contador de operaciones
 * @return {nodo} retorna la raiz del arbol
*/
nodo crearArbolDeHuffman(std::vector<std::pair<int,char>> entrada, int *contador);

//Funciones generales para cadenas
/**
 * Esta funcion retorna un arreglo de simbolos y apariciones, desde una cadena
 * @param {string} [cadena] cadena sobre la cual se obtendran los simbolos y apariciones de cada uno
 * @param {int*} [contador] apuntador al contador de operaciones
 * @return {vector<pair<int,char>>} retorna un arreglo de simbolos y cantidad de apariciones
*/
std::vector< std::pair<int, char> >obtenerConcurrencias(std::string cadena, int *contador);

//Funciones generales para archivos
/**
 * Esta funcion retorna un arreglo de simbolos y apariciones, desde un archivo
 * @param {FILE*} [archivo] archivo sobre el cual se obtendran los simbolos y apariciones de cada uno
 * @param {int*} [contador] apuntador al contador de operaciones
 * @return {vector<pair<int,char>>} retorna un arreglo de simbolos y cantidad de apariciones
*/
std::vector< std::pair<int, char> >obtenerConcurrencias(FILE *archivo, int *contador);

//Funciones de compresion y descompresion para cadenas
/**
 * Esta funcion comprime una cadena utilizando un arbol de Huffman
 * @param {nodo} [arbol] raiz del arbol de huffman
 * @param {string} [cadena] cadena a comprimir
 * @param {int*} [contador] apuntador al contador de operaciones
 * @return {string} retorna la cadena comprimida en un string con '0' y '1' como unicos caracter
*/
std::string comprimirCadena(nodo arbol, std::string cadena, int *contador);
/**
 * Esta funcion descomprime una cadena utilizando un arbol de Huffman
 * @param {nodo} [arbol] raiz del arbol de huffman
 * @param {string} [cadena] cadena a descomprimir
 * @param {int*} [contador] apuntador al contador de operaciones
 * @return {string} retorna la cadena descomprimida
*/
std::string descomprimirCadena(nodo arbol, std::string cadenaComprimida, int *contador);

//Funciones de compresion y descompresion para archivos
/**
 * Esta funcion comprime un archivo utilizando un arbol de Huffman
 * @param {nodo} [arbol] raiz del arbol de huffman
 * @param {char*} [pathArchivoEntrada] direccion del archivo a comprimir
 * @param {char*} [pathArchivoSalida] direccion del archivo en el cual se guardara la salida
 * @param {int*} [contador] apuntador al contador de operaciones
*/
void comprimirArchivo(nodo arbol, char *pathArchivoEntrada, char *pathArchivoSalida, int *contador);
/**
 * Esta funcion descomprime un archivo utilizando un arbol de Huffman
 * @param {nodo} [arbol] raiz del arbol de huffman
 * @param {char*} [pathArchivoEntrada] direccion del archivo a descomprimir
 * @param {char*} [pathArchivoSalida] direccion del archivo en el cual se guardara la salida
 * @param {int*} [contador] apuntador al contador de operaciones
*/
void descomprimirArchivo(nodo arbol, char *pathArchivoEntrada, char *pathArchivoSalida, int *contador);
