/**
 * @author Payán Téllez René
 * @email rpayant1500@alumno.ipn.mx
 * @create date 2020-11-10 01:41pm
 * @modify date 2020-11-10 11:00pm
 * @desc [Este archivo tiene los 2 algoritmos para la secuencia de fibonacci (iterativo y recursivo) y lo necesario para medir su complejidad]
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * La solucion itreativa para encontrar el termino n en la secuencia de fibonacci
 * @param {int} [n] n (El termino limite de la secuencia)
 * @param {int*} [contador] La referencia al contador de operaciones
 */
long long int fibonacciIterativo(int n, long long int *contador){
    long long int a = 0,b = 1; (*contador)++;
    for(int i = 1;i<=n;i++){
        (*contador)++;
        long long int c = a;(*contador)++;
        a = b;(*contador)++;
        b+=c;(*contador)++;
    }
    (*contador)++;
    return a;
}
/**
 * La solucion recursiva para encontrar el termino n en la secuencia de fibonacci
 * @param {int} [n] n
 * @param {int*} [contador] La referencia al contador de operaciones
 * @return {int} Retorna la respuesta del termino n
 */
long long int  fibonacciRecursivo(int n, long long int *contador){
    if(n == 0){
        (*contador)++;
        (*contador)++;
        return 0;
    }else if(n ==1){
        (*contador)++;
        (*contador)++;
        return 1;
    }else{
        (*contador)++;
        (*contador)++;
        (*contador)++;
        return fibonacciRecursivo(n-1,contador)+fibonacciRecursivo(n-2,contador);
    }
}

int main(){
    long long int  limite = 41;
    long long int  contador1, contador2;
    register int i;
    int resultadoIterativo, resultadoRecursivo;
    FILE* archivo1, *archivo2, *archivo3, *archivo4;
    /*
        Se definen los 3 apuntadores a archivo
        Los cuales son:
            - archivo1: resultado de la funcion iterativa
            - archivo2: resultado de la funcion recursiva
            - archivo3: resultado de las 2 funciones
    */
    archivo1 = fopen("parte1_1.dat","w");
    archivo2 = fopen("parte1_2.dat","w");
    archivo3 = fopen("parte1_combinado.dat","w");
    //Se definen los 2 contadores para la suma de operaciones
    contador1 = contador2 = 0;
    for(i = 0; i < limite; i++ ){
        //Guardamos los resultados en un archivo
        resultadoIterativo = fibonacciIterativo(i, &contador1);
        resultadoRecursivo = fibonacciRecursivo(i, &contador2);
        printf("El termino %d de la secuencia de fibonacci es: %d (iterativo), %d (recursivo) y termino en %d y %d operaciones respectivamente\n", i, resultadoIterativo, resultadoRecursivo, contador1, contador2);
        fprintf(archivo1,"%d    %d\n",i,contador1);
        fprintf(archivo2,"%d    %d\n",i,contador2);
        fprintf(archivo3,"%d    %d    %d\n",i,contador1,contador2);
        contador1 = contador2 = 0;
    }
    //Se cierran los archivos
    fclose(archivo1);
    fclose(archivo2);
    fclose(archivo3);
    return 0;
}
