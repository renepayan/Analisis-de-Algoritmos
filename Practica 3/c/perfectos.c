/**
 * @author Payán Téllez René
 * @email rpayant1500@alumno.ipn.mx
 * @create date 2020-11-12 01:00am
 * @modify date 2020-11-12 02:30am
 * @desc [Este archivo tiene las 2 funciones para obtener los numeros perfectos Perfecto(n) y MostrarPerfectos(n)]
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXIMO 77232999
short Perfecto(long long int n, int* contador);
void MostrarPerfectos(long long int n, int* contador);

int main(){
    int limite1 = 10000;
    int limite2 = 4;
    long long int  contador1, contador2;
    register int i;
    int resultadoPerfecto;
    FILE* archivo1, *archivo2;
    /*
        Se definen los 3 apuntadores a archivo
        Los cuales son:
            - archivo1: resultado de la funcion Perfecto
            - archivo2: resultado de la funcion MostrarPerfectos
    */
    archivo1 = fopen("parte2_1.dat","w");
    archivo2 = fopen("parte2_2.dat","w");
    //Se definen los 2 contadores para la suma de operaciones
    contador1 = contador2 = 0;
    for(i = 2; i <= limite1; i++ ){
        //Guardamos los resultados en un archivo
        resultadoPerfecto = Perfecto(i, &contador1);
        if(resultadoPerfecto)
            printf("El numero %d es perfecto y tomo %d operaciones determinarlo\n", i, contador1);
        else
            printf("El numero %d no es perfecto y tomo %d operaciones determinarlo\n", i, contador1);
        fprintf(archivo1,"%d    %d\n",i,contador1);
        contador1 = 0;
    }
    for(i = 0; i <= limite2; i++ ){
        //Guardamos los resultados en un archivo
        MostrarPerfectos(i, &contador2);
        printf("La funcion termino con %d operaciones\n",contador2);
        fprintf(archivo2,"%d    %d\n",i,contador2);
        contador2 = 0;
    }
    //Se cierran los archivos
    fclose(archivo1);
    fclose(archivo2);

    return 0;
}

/**
 * Esta funcion imprime los primeros n numeros perfectos
 * @param {int} [n] n
 * @param {int*} [contador] La referencia al contador de operaciones
 */
void MostrarPerfectos(long long int n, int *contador){
    int i = 6;(*contador)++;
    while(n>0){
        (*contador)++;
        if(Perfecto(i,contador)){
            (*contador)+=2;
            printf("%d, ",i);
            (*contador)++;
            n-=1;
        }else{
            (*contador)++;
        }
        (*contador)++;
        i++;
    }
    printf("\n");
    (*contador)++;
}
/**
 * La implementacion para la funcion Perfecto(n)
 * @param {int} [n] n
 * @param {int*} [contador] La referencia al contador de operaciones
 * @return {short} Retorna 1 si el numero es perfecto, si no retorna 0
 */
short Perfecto(long long int n, int *contador){
    //Definimos las variables a utilizar
    long long int raiz = 0; (*contador)++;
    long long int suma = 0; (*contador)++;
    //Especificamos el valor de la raiz
    raiz = (long long int) sqrt(n); (*contador)++;
    //Suma va a valer 1 porque el 1 siempre es divisor
    suma = 1; (*contador)++;
    for(int i = 2;i<=raiz;i++){
        (*contador)++;
        if(n%i == 0){
            (*contador)++;
            if(n/i>raiz){
                (*contador)+=2;
                suma+=(n/i);
            }else{
                (*contador)++;
            }
            (*contador)++;
            suma+=i;
        }else{
            (*contador)++;
        }
    }
    (*contador)+=3;
    if(suma == n){
        return 1;
    }else{
        return 0;
    }
}
