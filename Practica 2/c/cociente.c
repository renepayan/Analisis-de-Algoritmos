/**
 * @author Bejar Valencia Angel Ivan, Payán Téllez René
 * @email ivanbejar07@gmail.com,rpayant1500@alumno.ipn.mx
 * @create date 2020-10-28 06:13pm
 * @modify date 2020-10-29 04:25am
 * @desc [Este archivo tiene las 3 funciones de producto y lo necesario para medir su complejidad]
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * La primer funcion a implementar
 * @param {int} [n] n
 * @param {int} [div] divisor
 * @param {int*} [r] La referencia del residuo
 * @param {int*} [contador] La referencia al contador de operaciones
 * @return {int} Retorna la respuesta del cociente
 */
int div1(int n, int div, int* r, int* contador){
    int q = 0; (*contador)++;
    while(n>0){
        (*contador)++;
        n = n-div;
        (*contador)++;
        q++;
        (*contador)++;
    }
    (*contador)++;
    *r=n;(*contador)++;
    (*contador)++;
    return q;
}
/**
 * La segunda funcion a implementar
 * @param {int} [n] n
 * @param {int} [div] divisor
 * @param {int*} [r] La referencia del residuo
 * @param {int*} [contador] La referencia al contador de operaciones
 * @return {int} Retorna la respuesta del cociente
 */
int div2(int n, int div, int* r, int* contador){
    int dd = div;(*contador)++;
    int q = 0;(*contador)++;
    *r = n;(*contador)++;
    while(dd<=n){
        (*contador)++;
        dd=2*dd;(*contador)++;
    }
    (*contador)++;
    while(dd>div){
        dd = dd/2;(*contador)++;
        q = 2*q;(*contador)++;
        if(dd<=*r){
            (*contador)++;
            *r = *r-dd;(*contador)++;
            q++;(*contador)++;
        }
        (*contador)++;
    }
    (*contador)++;
    (*contador)++;
    return q;

}
/**
 * La tercer funcion a implementar
 * @param {int} [a] n
 * @param {int} [div] divisor
 * @param {int*} [contador] La referencia al contador de operaciones
 * @return {int} Retorna la respuesta del cociente
 */
int div3(int n, int div, int* contador){
    (*contador)++;
    if(div>n){
        (*contador)++;
        return 0;
    }else{
        (*contador)++;
        return 1+div3(n-div,div,contador);
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
    archivo1 = fopen("parte2_1.dat","w");
    archivo2 = fopen("parte2_2.dat","w");
    archivo3 = fopen("parte2_3.dat","w");
    archivo4 = fopen("parte2_combinado.dat","w");
    //Se definen los 4 contadores para la suma de operaciones
    int contador1, contador2, contador3;
    contador1 = contador2 = contador3 = 0;
    //inicializaos los resiudos
    int residuo1, residuo2, residuo3;
    residuo1 = residuo2 = residuo3 = 0;
    //Las variables de los 2 for
    register int i,j;
    for(i = 1; i <= 1000; i++){
        for(j = 10; j <= 10; j++){
            //Se ejecutan las funciones
            int res1 = div1(i, j, &residuo1, &contador1);
            int res2 = div2(i, j, &residuo2, &contador2);
            int res3 = div3(i, j, &contador3);
            //Se almacena el resultado en el archivo
            fprintf(archivo1,"%d    %d\n",i,contador1);
            fprintf(archivo2,"%d    %d\n",i,contador2);
            fprintf(archivo3,"%d    %d\n",i,contador3);
            fprintf(archivo4,"%d    %d    %d    %d\n",i,contador1,contador2, contador3);
            //Se imprime el resultado en pantalla
            printf("funcion 1, n: %d div: %d resultado: %d, operaciones: %d\n",i,j,res1,contador1);
            printf("funcion 2, n: %d div: %d resultado: %d, operaciones: %d\n",i,j,res2,contador2);
            printf("funcion 3, n: %d div: %d resultado: %d, operaciones: %d\n",i,j,res3,contador3);
            //Se inicializan los contadores
            contador1 = contador2 = contador3 = 0;
            //Se inicializan los residuos
            residuo1 = residuo2 = residuo3 = 0;
        }
    }
    //Se cierran los archivos
    fclose(archivo1);
    fclose(archivo2);
    fclose(archivo3);
    fclose(archivo4);
    return 0;
}
