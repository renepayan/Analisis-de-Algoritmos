/**
 * @author Bejar Valencia Angel Ivan, Payán Téllez René
 * @email ivanbejar07@gmail.com,rpayant1500@alumno.ipn.mx
 * @create date 2020-10-28 05:00pm
 * @modify date 2020-10-29 04:25am
 * @desc [Este archivo tiene las 3 funciones de producto y lo necesario para medir su complejidad]
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * La primer funcion a implementar
 * @param {int} [n] n
 * @param {int} [m] m
 * @param {int*} [contador] La referencia al contador de operaciones
 * @return {int} Retorna la respuesta del producto
 */
int prod1(int n, int m, int* contador){
    int r = 0; (*contador)++;
    while(n>0){
        (*contador)++;
        r = r+m;
        (*contador)++;
        n--;
        (*contador)++;
    }
    (*contador)++;
    (*contador)++;
    return r;
}
/**
 * La segunda funcion a implementar
 * @param {int} [n] n
 * @param {int} [m] m
 * @param {int*} [contador] La referencia al contador de operaciones
 * @return {int} Retorna la respuesta del producto
 */
int prod2(int n, int m, int* contador){
    int r = 0;(*contador)++;
    while(n>0){
        (*contador)++;
        (*contador)++;
        if (n & 1){
            (*contador)++;
            r = r+m;
        }
        (*contador)++;
        m = 2*m;
        (*contador)++;
        n = n/2;
    }
    (*contador)++;
    (*contador)++;
    return r;

}
/**
 * La tercer funcion a implementar
 * @param {int} [a] n
 * @param {int} [b] m
 * @param {int*} [contador] La referencia al contador de operaciones
 * @return {int} Retorna la respuesta del producto
 */
int prod3(int a, int b, int* contador){
    (*contador)++;
    if(b == 1){
        (*contador)++;
        return a;
    }else{
        (*contador)++;
        return a+prod3(a,b-1,contador);
    }
}
int main(){
    /*
        Se definen los 4 apuntadores a archivo
        Los cuales son:
            - archivo1: resultado de la funcion 1
            - archivo2: resultado de la funcion 2
            - archivo3: resultado de la funcion 3
            - archivo4: resultado de todas las funciones
    */
    FILE* archivo1, *archivo2, *archivo3, *archivo4;
    archivo1 = fopen("parte1_1.dat","w");
    archivo2 = fopen("parte1_2.dat","w");
    archivo3 = fopen("parte1_3.dat","w");
    archivo4 = fopen("parte1_combinado.dat","w");
    //Se definen los 4 contadores para la suma de operaciones
    int contador1, contador2, contador3;
    contador1 = contador2 = contador3 = 0;
    //Las variables de los 2 for
    register int i,j;
    for(i = 1; i <= 1000; i++){
        for(j = 10; j <= 10; j++){
            //Se ejecutan las funciones
            int res1 = prod1(i,j,&contador1);
            int res2 = prod2(i,j,&contador2);
            int res3 = prod3(j,i,&contador3);
            //Se almacena el resultado en el archivo
            fprintf(archivo1,"%d    %d\n",i,contador1);
            fprintf(archivo2,"%d    %d\n",i,contador2);
            fprintf(archivo3,"%d    %d\n",i,contador3);
            fprintf(archivo4,"%d    %d    %d    %d\n",i,contador1,contador2, contador3);
            //Se imprime el resultado en pantalla
            printf("funcion 1, n: %d m: %d resultado: %d, operaciones: %d\n",i,j,res1,contador1);
            printf("funcion 2, n: %d m: %d resultado: %d, operaciones: %d\n",i,j,res2,contador2);
            printf("funcion 3, n: %d m: %d resultado: %d, operaciones: %d\n",i,j,res3,contador3);
            //Se inicializan los contadores
            contador1 = contador2 = contador3 = 0;
        }
    }
    //Se cierran los archivos
    fclose(archivo1);
    fclose(archivo2);
    fclose(archivo3);
    return 0;
}
