#include <bits/stdtr1c++.h>
/**
 * @author Payán Téllez René
 * @email rpayant1500@alumno.ipn.mx
 * @create date 2020-12-25
 * @modify date 2020-12-27
 * @desc [Este archivo tiene la implementacion del algoritmo de la multiplicacion de matrices mas optima y todo lo necesario para medir su complejidad temporal]
 */
using namespace std;
/**
 * Esta funcion convierte un numero entero en un string para poderlo concatenar
 * @param {int} [entero] numero a ser convertido
 * @return {string} El numero convertido
*/
string enteroAString(int entero){
    stringstream ss;
    ss<<entero;
    string s;
    ss>>s;
    return s;
}
/**
 * Esta funcion genera las matrices de recorrido y de comparacion para obtener la parentizacion optima para la multiplicacion de una configuracion de matrices dada
 * @param {int*} [p] configuracion de las matrices
 * @param {int} [n] numero de matrices
 * @param {int**} [m] matriz de resultados
 * @param {int**} [s] matriz de recorrido
 * @param {int*} [contador] apuntador al contador de operaciones
 * @return {int} El minimo numero de operaciones unitarias
*/
int getMatrixSequence(int *p, int n, int **m, int **s, int* contador){
    register int i, j, k, l;(*contador)++;
    int q;(*contador)++;
    for(l = 2; l <= n; l++){(*contador)++;
        for(i = 1; i <= n-l+1; i++){(*contador)++;
            j = i+l-1;(*contador)++;
            m[i][j] = INT_MAX;(*contador)++;
            for(k = i; k <= j-1; k++){(*contador)++;
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];(*contador)++;
                if(q < m[i][j]){(*contador)++;
                    m[i][j] = q;(*contador)++;
                    s[i][j] = k;(*contador)++;
                }
            }(*contador)++;
        }(*contador)++;
    }(*contador)++;
    return m[1][n];
}
/**
 * Esta funcion genera la parentizacion optima para la multiplicacion de una configuracion de matrices dada
 * @param {int**} [s] matriz de recorrido
 * @param {int} [i] indice sobre las columnas de la matriz de recorrido
 * @param {int} [j] indice sobre las filas de la matriz de recorrido
 * @param {int*} [contador] apuntador al contador de operaciones
 * @return {String} La parentizacion mas optima
*/
string getOptimalParens(int **s, int i, int j, int *contador){
    if(i == j){(*contador)++;
        return "A"+enteroAString(i);(*contador)++;
    }else{(*contador)++;
        (*contador)++;
        return "("+getOptimalParens(s, i, s[i][j], contador)+getOptimalParens(s, s[i][j]+1,j, contador)+")";
    }
    (*contador)++;
    return "";
}
/**
 * Esta funcion reserva la memoria necesaria para una matriz de enteros
 * @param {int} [n] columnas de la matriz
 * @param {int} [m] filas de la matriz
 * @return {int**} La memoria reservada
*/
int** reservarMemoria(int n, int m){
    register int i, j;
    int **memoria;
    memoria = (int**)malloc(sizeof(int*)*n);
    for(i = 0; i < n; i++){
        memoria[i] = (int*)malloc(sizeof(int)*m);
        for(j = 0; j < m; j++){
            memoria[i][j] = 0;
        }
    }
    return memoria;
}
/**
 * Esta funcion imprime una matriz de enteros en pantalla
 * @param {int} [n] columnas de la matriz
 * @param {int} [m] filas de la matriz
*/
void imprimirMatriz(int** matriz, int n, int m){
    register int i,j;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%4d ",matriz[i][j]);
        }
        cout<<'\n';
    }
}
/**
 * Esta funcion convierte un arreglo de enteros a una cadena de texto
 * @param {int*} [arreglo] el arreglo a convertir
 * @param {int} [n] cantidad de elementos en el arreglo
 * @return {string} El arreglo en formato de cadena
*/
string arregloAString(int *arreglo, int n){
    register int i;
    string salida;
    salida = "[";
    for(i = 0; i < n-1; i++){
        salida+=enteroAString(arreglo[i])+',';
    }

    salida+=(n>=1)?enteroAString(arreglo[i])+"]":"]";
    return salida;
}
/**
 * Esta funcion obtiene e imprime la parentizacion mas optima de una configuracion de matrices
 * @param {int} [n] numero de matrices
 * @param {int*} [p] configuracion de las matrices
*/
void procesarMatriz(int n, int *p){
    //Declaracion de variables
    int **matrizCamino, **matrizResultado, resultado, contadorGenerar, contadorObtener;
    string cadena;
    string configuracion;

    //Inicializacion de variables
    matrizResultado = reservarMemoria(n+1, n+1);
    matrizCamino = reservarMemoria(n, n+1);
    contadorGenerar = contadorObtener = 0;

    //Creacion de las matrices
    resultado = getMatrixSequence(p, n, matrizResultado, matrizCamino, &contadorGenerar);
    cadena = getOptimalParens(matrizCamino, 1, n, &contadorObtener);

    //Obtener la configuracion en un string
    configuracion = arregloAString(p, n+1);

    //Impresion de los resultados
    cout<<"Para la matriz de tamanio "<<n<<" con la configuracion "<<configuracion<<" la configuracion optima es "<<cadena<<"\ncon "<<resultado<<" operaciones unitarias\nLe tomo "<<contadorGenerar<<" operaciones generar las matrices y "<<contadorObtener<<" operaciones obtener la secuencia\n";
    cout<<"Matriz resultado\n";
    imprimirMatriz(matrizResultado, n+1, n+1);
    cout<<"Matriz camino\n";
    imprimirMatriz(matrizCamino, n, n+1);

    //Liberar memoria
    free(matrizResultado);
    free(matrizCamino);
}
int main(){
    int n, *arreglo;
    register int i;
    cout<<"Ingrese el numero de matrices: ";
    cin>>n;
    arreglo = (int*)malloc(sizeof(int)*(n+1));
    for(i = 0; i <= n; i++){
        cout<<"Ingrese la configuracion ("<<(i+1)<<"): ";
        cin>>arreglo[i];
    }
    procesarMatriz(n, arreglo);
    return 0;
}
