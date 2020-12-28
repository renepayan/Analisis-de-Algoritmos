/**
 * @author Payán Téllez René
 * @email rpayant1500@alumno.ipn.mx
 * @create date 2020-12-24
 * @modify date 2020-12-26
 * @desc [Este archivo tiene la implementacion del algoritmo de la subcadena comun mas larga y todo lo necesario para medir su complejidad temporal]
 */
#include <bits/stdtr1c++.h>

using namespace std;
/**
 * Esta funcion obtiene la sub cadena comun mas larga a partir de la matriz de la DP
 * @param {string} [x] cadena a ser comparada
 * @param {char**} [matrizRecorrido] matriz de la DP
 * @param {int} [i] indice sobre la cadena Y en la matriz
 * @param {int} [j] indice sobre la cadena X en la matriz
 * @param {int*} [contador] apuntador al contador de operaciones
 * @return {string} La subcadena comun mas larga
*/
string obtenerLCS(string x, char** matrizRecorrido, int i, int j, int* contador){
    if(i == 0 || j == 0){(*contador)++;
        (*contador)++;
        return "";
    }(*contador)++;
    if(matrizRecorrido[i][j] == '\\'){(*contador)++;
        (*contador)++;
        return obtenerLCS(x, matrizRecorrido, i-1, j-1, contador)+x[i-1];
    }else if(matrizRecorrido[i][j] == '|'){(*contador)++;
        (*contador)++;
        return obtenerLCS(x, matrizRecorrido, i-1, j, contador);
    }else{(*contador)++;
        (*contador)++;
        return obtenerLCS(x, matrizRecorrido, i, j-1, contador);
    }
}

/**
 * Esta funcion obtiene las matrices necesarias para calcular la subcadena comun mas larga
 * @param {string} [x] cadena a ser comparada
 * @param {string} [y] segunda cadena a ser comparada
 * @param {char**} [matrizDP] matriz de los maximos acumulados de la DP
 * @param {char**} [matrizRecorrido] matriz del recorrido de la DP
 * @param {int*} [contador] apuntador al contador de operaciones
*/
void generarLCS(string x, string y, int** matrizDP, char** matrizRecorrido, int* contador){
    register int i, j;(*contador)++;
    int n, m;(*contador)++;
    m = x.length();(*contador)++;
    n = y.length();(*contador)++;
    for(i = 1; i <= m; i++){(*contador)++;
        for(j = 1; j <= n; j++){(*contador)++;
            if(x[i-1] == y[j-1]){(*contador)++;
                matrizDP[i][j] = matrizDP[i-1][j-1]+1;(*contador)++;
                matrizRecorrido[i][j] = '\\';(*contador)++;
            }else if(matrizDP[i-1][j] >= matrizDP[i][j-1]){(*contador)++;
                matrizDP[i][j] = matrizDP[i-1][j];(*contador)++;
                matrizRecorrido[i][j] = '|';(*contador)++;
            }else{(*contador)++;
                matrizDP[i][j] = matrizDP[i][j-1];(*contador)++;
                matrizRecorrido[i][j] = '-';(*contador)++;
            }
        }(*contador)++;
    }(*contador)++;
}

/**
 * Esta funcion lee un archivo a partir de una ruta y elimina todos los espacios y saltos de linea
 * @param {string} [path] ruta del archivo
 * @return {string} retorna una cadena con el contenido del archivo despues de ser limpiado
*/
string leerArchivo(string path){
    ifstream t(path);
    string str((istreambuf_iterator<char>(t)),istreambuf_iterator<char>());
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    str.erase(remove(str.begin(), str.end(), '\n'), str.end());
    return str;
}

/**
 * Esta funcion obtiene e imprime la subsecuencia comun mas larga de dos cadenas junto a la informacion relacionada
 * @param {string} [x] primer cadena
 * @param {string} [x] segunda cadena
*/
void compararCadenas(string x, string y){
    string resultado;
    int contadorGenerar, contadorObtener, **matrizDP;
    register int i, j;
    char **matrizRecorrido;
    float porcentaje;

    //Creo las matrices
    matrizDP = (int**)malloc(sizeof(int**)*(x.length()+1));
    matrizRecorrido = (char**)malloc(sizeof(char**)*(x.length()+1));

    //Inicializo las matrices
    for(i = 0; i <= x.length(); i++){
        matrizDP[i] = (int*)malloc(sizeof(int)*(y.length()+1));
        matrizRecorrido[i] = (char*)malloc(sizeof(char)*(y.length()+1));
        matrizDP[i][0] = 0;
        matrizRecorrido[i][0] = '!';
    }
    for(j = 0; j <= y.length(); j++){
        matrizDP[0][j] = 0;
        matrizRecorrido[0][j] = '!';
    }

    contadorGenerar = contadorObtener = 0;
    //Ahora creo la matriz de la DP
    generarLCS(x, y, matrizDP, matrizRecorrido, &contadorGenerar);

    //Ahora obtengo la subsecuencia mas larga
    resultado = obtenerLCS(x, matrizRecorrido, x.length(), y.length(), &contadorObtener);
    porcentaje = ((float)resultado.length()*100.0f)/ ((float)x.length());

    //Impresion en pantalla
    cout<<"Las cadenas se parecen en un "<<porcentaje<<"%, generar las matrices le tomo "<<contadorGenerar<<" operaciones, obtener la cadena le tomo "<<contadorObtener<<" operaciones y la cadena comun mas larga es:\n\""<<resultado<<"\"\n";

    //Liberar memoria
    free(matrizDP);
    free(matrizRecorrido);
}

/**
 * Esta funcion obtiene e imprime la subsecuencia comun mas larga de dos archivos
 * @param {string} [pathArchivoOriginal] primer archivo
 * @param {string} [pathArchivoAComparar] segundo archivo
*/
void compararParDeArchivos(string pathArchivoOriginal, string pathArchivoAComparar){
    //Declaracion de variables
    string x, y;
    //Primero obtengo los archivos en un string
    x = leerArchivo(pathArchivoOriginal);
    y = leerArchivo(pathArchivoAComparar);
    cout<<"Para los archivos "<<pathArchivoOriginal<<" y "<<pathArchivoAComparar<<'\n';
    compararCadenas(x, y);
}

/**
 * Esta funcion obtiene ejecuta la comparacion en masa de 5 archivos
*/
void compararEnMasa(){
    compararParDeArchivos("archivo1.txt","archivo1.comparar.txt");
    compararParDeArchivos("archivo2.txt","archivo2.comparar.txt");
    compararParDeArchivos("archivo3.txt","archivo3.comparar.txt");
    compararParDeArchivos("archivo4.txt","archivo4.comparar.txt");
    compararParDeArchivos("archivo5.txt","archivo5.comparar.txt");
}
int main(){
    compararEnMasa();
    return 0;
}
