/**
 * @author Payán Téllez René
 * @email rpayant1500@alumno.ipn.mx
 * @create date 2020-12-17
 * @modify date 2020-12-19
 * @desc [Este archivo tiene la implementacion para calcular el problema de la mochila 0-1 con programacion dinamica]
 */
#include <bits/stdtr1c++.h>
#define MAXIMO_PESO 500

using namespace std;
/**
 * Esta funcion llena un arreglo con valores aleatorios
 * @param {int*} [arreglo] arreglo a llenar
 * @param {int} [n] tamanio del arreglo
*/
void llenarArreglo(int *arreglo, int n){
    register int i;
    for(i = 0; i < n; i++){
        arreglo[i] = rand()%MAXIMO_PESO;
    }
}
/**
 * Esta funcion imprime un arreglo
 * @param {int*} [arreglo] arreglo a imprimir
 * @param {int} [n] tamanio del arreglo
*/
void imprimirArreglo(int *arreglo, int n){
    register int i;
    for(i = 0; i < n; i++){
        printf("%4d ",arreglo[i]);
    }
    cout<<'\n';
}
/**
 * Esta funcion imprime una matriz (arreglo bi dimensional o doble apuntador)
 * @param {int**} [matriz] matriz a imprimir
 * @param {int} [n] renglones de la matriz
 * @param {int} [m] columnas de la matriz
*/
void imprimirMatriz(int **matriz, int n, int m){
    register int i;
    for(i = 0; i < n; i++){
        imprimirArreglo(matriz[i], m);
    }
}
/**
 * Esta funcion reserva un arreglo de enteros
 * @param {int} [tamanio] tamanio del arreglo
 * @return {int*} retorna un apuntador a entero con la memoria
*/
int* reservarMemoria(int tamanio){
    int *memoria;
    memoria = (int*) malloc(sizeof(int)*tamanio);
    return memoria;
}
/**
 * Esta funcion crea la matriz necesaria para la funcion test
 * @param {int} [W] peso maximo de la mochila
 * @param {int} [n] cantidad de objetos
 * @param {int*} [wt] arreglo de pesos
 * @param {int*} [val] arreglo de valores
 * @param {int*} [contador] contador de operaciones
 * @return {int**} retorna una matriz con los valores de la DP
*/
int** mochila01(int W, int n, int *wt, int *val, int *contador){
    //Declaracion de variables
    int **retorno;(*contador)++;
    register int c, j;(*contador)++;
    retorno = (int**) malloc(sizeof(int*)*(n+1));(*contador)++;

    //Inicializacion del arreglo
    for(j = 0; j <= n; j++){(*contador)++;
        retorno[j] = reservarMemoria(W+1); (*contador)++;
        retorno[j][0] = 0;(*contador)++;
    }(*contador)++;
    for(c = 0; c <= W; c++){(*contador)++;
        retorno[0][c] = 0;(*contador)++;
    }(*contador)++;


    //Creacion de la matriz
    for(j = 1; j <= n; j++){(*contador)++;
        for(c = 1; c <= W; c++){(*contador)++;
            if(c<wt[j-1]){(*contador)++;
                retorno[j][c] = retorno[j-1][c];(*contador)++;
            }else{(*contador)++;
                if(retorno[j-1][c] >= retorno[j-1][c-wt[j-1]]+val[j-1]){(*contador)++;
                    retorno[j][c] = retorno[j-1][c];(*contador)++;
                }else{(*contador)++;
                    retorno[j][c] = retorno[j-1][c-wt[j-1]]+val[j-1];(*contador)++;
                }
            }
        }(*contador)++;
    }(*contador)++;
    (*contador)++;
    return retorno;
}
/**
 * Esta funcion determina que objetos se deben almacenar en la mochila
 * @param {int} [j] index sobre los objetos
 * @param {int} [c] index sobre el peso de la mochila
 * @param {int*} [val] arreglo de valores
 * @param {int*} [wt] arreglo de pesos
 * @param {int**} [matriz] matriz con los valores de la DP
 * @param {int*} [contador] contador de operaciones
*/
void test(int j, int c, int *val, int *wt, int **matriz, int* contador){
    if(j > 0 ){(*contador)++;
        if (c < wt[j-1]){(*contador)++;
            test(j-1,c,val,wt,matriz,contador);(*contador)++;
        }else{(*contador)++;
            if(matriz[j-1][c-wt[j-1]]+val[j-1]>matriz[j-1][c]){
                test(j-1,c-wt[j-1],val,wt,matriz,contador);
                cout<<"Guardar objeto "<<j<<'\n';
            }else{(*contador)++;
                test(j-1,c,val,wt,matriz,contador);
            }
        }
    }else
        (*contador)++;
}
/**
 * Esta funcion hace lo necesario para probar un caso especifico
 * @param {int} [W] tamanio de la mochila
 * @param {int} [n] cantidad de objetos
 * @param {int*} [pesos] arreglo de pesos
 * @param {int*} [valores] arreglo de valores
 * @param {int*} [contadorMochila01] contador de operaciones para la funcion de mochila
 * @param {int*} [contadorTest] contador de operaciones para la funcion test
*/
void probarParaCasoEspecifico(int W, int n, int *pesos, int *valores, int* contadorMochila01, int *contadorTest){
    //Declaracion de variables
     int **matriz;


    //Impresion de los datos iniciales
    cout<<"El peso maximo de la mochila es: "<<W<<" y hay "<<n<<" elementos\n";
    cout<<"Los pesos son los siguientes:\n";
    imprimirArreglo(pesos,n);
    cout<<"Los valores son los siguientes:\n";
    imprimirArreglo(valores,n);

    //Llenar la matriz
    matriz = mochila01(W, n, pesos, valores, contadorMochila01);


    //Impresion de la matriz
    cout<<"La matriz es:\n";
    imprimirMatriz(matriz, n+1, W+1);

    //Ejecucion de la funcion test
    test(n,W, valores, pesos, matriz, contadorTest);

    //Liberar memoria
    free(matriz);
}
/**
 * Esta funcion hace prueba a granel sobre n
 * @param {int} [limite] tope a probar
*/
void probarParaN(int limite){
    //declaracion de variables
    int *valores, *pesos, contadorMochila01, contadorTest, n, W;
    FILE* archivoSalida;

    //asignacion de variables
    archivoSalida = fopen("mochila_n.dat","w");
    //Para poder obtener una grafica valida, mantendre el peso constante
    W = MAXIMO_PESO;
    for(n = 1;n <= limite; n++){
        //definir valores para el caso de prueba
        valores = reservarMemoria(n);
        pesos = reservarMemoria(n);

        //llenar aleatoriamente los arreglos de los casos de prueba
        llenarArreglo(valores,n);
        llenarArreglo(pesos,n);

        //inicializar contadores
        contadorMochila01 = contadorTest = 0;

        //Ejecucion del caso de prueba
        probarParaCasoEspecifico(W, n, pesos, valores, &contadorMochila01, &contadorTest);

        //Impresion en consola
        cout<<"Para n = "<<n<<" y W =  "<<W<<" la funcion mochila01 termino en: "<<contadorMochila01<<" operaciones y test en "<<contadorTest<<" operaciones\n";

        //Impresion en archivo
        fprintf(archivoSalida, "%d    %d    %d\n",n,contadorMochila01,contadorTest);

        //Liberar memoria
        free(valores);
        free(pesos);
    }
    //Cerrar el archivo
    fclose(archivoSalida);
}
/**
 * Esta funcion hace prueba a granel sobre W
 * @param {int} [limite] tope a probar
*/
void probarParaM(int limite){
    //declaracion de variables
    int *valores, *pesos, contadorMochila01, contadorTest, n, W;
    FILE* archivoSalida;

    //asignacion de variables
    archivoSalida = fopen("mochila_W.dat","w");
    //Para poder obtener una grafica valida, mantendre el peso constante
    n = MAXIMO_PESO;
    for(W = 1;W <= limite; W++){
        //definir valores para el caso de prueba
        valores = reservarMemoria(n);
        pesos = reservarMemoria(n);

        //llenar aleatoriamente los arreglos de los casos de prueba
        llenarArreglo(valores,n);
        llenarArreglo(pesos,n);

        //inicializar contadores
        contadorMochila01 = contadorTest = 0;

        //Ejecucion del caso de prueba
        probarParaCasoEspecifico(W, n, pesos, valores, &contadorMochila01, &contadorTest);

        //Impresion en consola
        cout<<"Para n = "<<n<<" y W =  "<<W<<" la funcion mochila01 termino en: "<<contadorMochila01<<" operaciones y test en "<<contadorTest<<" operaciones\n";

        //Impresion en archivo
        fprintf(archivoSalida, "%d    %d    %d\n",W,contadorMochila01,contadorTest);

        //Liberar memoria
        free(valores);
        free(pesos);
    }
    //Cerrar el archivo
    fclose(archivoSalida);
}
int main(){
    /*srand(TIME(NULL));
    int *pesos, *valores, contador, contador1;
    pesos = reservarMemoria(3);
    valores = reservarMemoria(3);
    valores[0] = 38;
    valores[1] = 40;
    valores[2] = 24;

    pesos[0] = 9;
    pesos[1] = 6;
    pesos[2] = 5;

    probarParaCasoEspecifico(15,3,pesos,valores,&contador,&contador1);*/
    probarParaN(10000);
    probarParaM(2001);
    return 0;
}
