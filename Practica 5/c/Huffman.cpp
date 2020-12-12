#include <bits/stdtr1c++.h>
#include "HuffmanTree.hpp"
using namespace std;
void pruebaDeArchivo(char* pathArchivoEntrada, char* pathArchivoSalida, char* pathArchivoSalidaDoble){
    //Declaracion de variables
    int contador = 0, contador1 = 0;

    //Contar las concurrencias
    FILE *archivoEntrada = fopen(pathArchivoEntrada,"r");
    vector<pair<int,char>> concurrencias = obtenerConcurrencias(archivoEntrada, &contador);
    fclose(archivoEntrada);
    //Crear el arbol
    nodo arbol = crearArbolDeHuffman(concurrencias, &contador);

    //Imprimir la tabla de binarios
    for(int i = 0; i < concurrencias.size();i++){
        cout<<concurrencias[i].second<<" Tiene "<<concurrencias[i].first<<" apariciones y su binario es: "<<obtenerBinario(arbol,concurrencias[i].second,&contador1)<<'\n';
    }
    //Imprimir la cantidad de operaciones
    cout<<"Se genero el arbol en "<<contador<<" operaciones\n";

    //Reestablecer contador
    contador = 0;

    //Comprimir archivo
    comprimirArchivo(arbol,pathArchivoEntrada, pathArchivoSalida, &contador);
    cout<<"Se comprimio el archivo: "<<pathArchivoEntrada<<" en "<<pathArchivoSalida<<" en "<<contador<<" operaciones\n";

    //Reestablecer contador
    contador = 0;

    //Decomprimir archivo
    descomprimirArchivo(arbol, pathArchivoSalida, pathArchivoSalidaDoble, &contador);
    cout<<"Se descomprimio el archivo: "<<pathArchivoSalida<<" en "<<pathArchivoSalidaDoble<<" en "<<contador<<" operaciones\n";
}
void pruebasDeArchivos(){
    pruebaDeArchivo("prueba1.txt", "prueba1_compressed.txt", "prueba1_decompressed.txt");
    pruebaDeArchivo("prueba2.txt", "prueba2_compressed.txt", "prueba2_decompressed.txt");
    pruebaDeArchivo("prueba3.txt", "prueba3_compressed.txt", "prueba3_decompressed.txt");
    pruebaDeArchivo("prueba4.txt", "prueba4_compressed.txt", "prueba4_decompressed.txt");
    pruebaDeArchivo("prueba5.txt", "prueba5_compressed.txt", "prueba5_decompressed.txt");
    pruebaDeArchivo("prueba6.txt", "prueba6_compressed.txt", "prueba6_decompressed.txt");
    pruebaDeArchivo("prueba7.txt", "prueba7_compressed.txt", "prueba7_decompressed.txt");
    pruebaDeArchivo("prueba8.txt", "prueba8_compressed.txt", "prueba8_decompressed.txt");
    pruebaDeArchivo("prueba9.txt", "prueba9_compressed.txt", "prueba1¿9_decompressed.txt");
    pruebaDeArchivo("prueba10.txt", "prueba10_compressed.txt", "prueba10_decompressed.txt");
}

vector<int> pruebaDeCadena(string cadena){
    //Declaracion de variables
    int contadorCompresion = 0, contadorDecompresion = 0, contadorArbol, contador1;

    //Obtener las apariciones
    vector<pair<int,char>> concurrencias = obtenerConcurrencias(cadena, &contadorArbol);
    //Crear el arbol
    nodo arbol = crearArbolDeHuffman(concurrencias, &contadorArbol);

    //Imprimir la tabla de binarios
    for(int i = 0; i < concurrencias.size();i++){
        cout<<concurrencias[i].second<<" Tiene "<<concurrencias[i].first<<" apariciones y su binario es: "<<obtenerBinario(arbol,concurrencias[i].second,&contador1)<<'\n';
    }

    //Imprimir la cantidad de operaciones
    cout<<"Se genero el arbol en "<<contadorArbol<<" operaciones\n";

    //Comprimir cadena
    string cadenaCompresa = comprimirCadena(arbol,cadena, &contadorCompresion);
    cout<<"Se comprimio la cadena: "<<cadena<<" en "<<cadenaCompresa<<" en "<<contadorCompresion<<" operaciones\n";

    //Decomprimir archivo
    string cadenaDecompresa = descomprimirCadena(arbol, cadenaCompresa, &contadorDecompresion);
    cout<<"Se descomprimio la cadena: "<<cadenaCompresa<<" en "<<cadenaDecompresa<<" en "<<contadorDecompresion<<" operaciones\n";

    //Crear el vector de retorno
    vector<int> respuesta;
    respuesta.push_back(contadorArbol);
    respuesta.push_back(contadorCompresion);
    respuesta.push_back(contadorDecompresion);
    return respuesta;
}
void pruebasDeCadenasEspecificas(){
    vector<int> holaMundo = pruebaDeCadena("Hola esta es una prueba, quiero comprar el cyberpunk 2077");
    vector<int> lorem = pruebaDeCadena("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer porttitor turpis eget erat auctor varius. Vestibulum maximus scelerisque dui ac vulputate. Mauris eleifend mauris vel ex sodales, ut blandit odio dictum. Ut efficitur eu lectus nec ullamcorper. Integer hendrerit justo in augue consectetur, eget porttitor quam rutrum. Cras porta justo at fermentum condimentum. Nunc lacinia convallis tortor in tempor. Donec tincidunt tempor ipsum, sit amet aliquet justo semper at. Donec nibh urna, faucibus ac mauris eu, mattis imperdiet dolor. Nam et nulla at nisi efficitur efficitur. Morbi bibendum scelerisque risus, at sollicitudin ligula rutrum et. Cras sagittis eget velit aliquam cursus.Nunc magna metus, ullamcorper sed ante id, tincidunt ornare libero. Proin pharetra orci felis, eget pellentesque nisi venenatis eget. Morbi tincidunt ut risus non iaculis. Proin id consectetur metus, sed placerat eros. Aenean cursus augue a ipsum tempor interdum. Vivamus viverra efficitur felis a aenean");
}
string generarCadenaAleatoria(int n){
    //Declaracion de variables
    string salida;
    register int i;
    int aleatorio;

    //Asignacion de variables
    salida = "";

    //Generacion
    for(i = 0; i < n; i++){
        aleatorio = rand()%255;
        salida+=((char)aleatorio);
    }
    return salida;
}
void pruebasDeCadenasGenericas(int limite){
    //Definicion de variables
    register int n;
    FILE *resultados;
    resultados = fopen("resultados_cadenas.dat","w");
    for(n = 1; n < limite; n++){
        cout<<"Generando cadena de longitud "<<n<<'\n';
        string cadena = generarCadenaAleatoria(n);
        vector<int> resCadena = pruebaDeCadena(cadena);
        fprintf(resultados,"%d  %d  %d  %d  %d\n", n, resCadena[0], resCadena[1], resCadena[2], resCadena[0]+resCadena[1]+resCadena[2]); //Se imprimen en el archivo n, tiempo de arbol, tiempo de compresion, tiempo de decompresion, suma
    }
    fclose(resultados);
}
int main(void){
    /*Esta seccion es para las pruebas sobre archivos*/
    pruebasDeArchivos();
    /*Esta para las pruebas sobre cadenas*/
    pruebasDeCadenasEspecificas();
    /*Esta es la seccion de las pruebas para graficas*/
    pruebasDeCadenasGenericas(10001);
}
