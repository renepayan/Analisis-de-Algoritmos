/**
 * @author Payán Téllez René
 * @email rpayant1500@alumno.ipn.mx
 * @create date 2020-12-03 01:00pm
 * @modify date 2020-12-04 07:05pm
 * @desc [Este archivo tiene la implementacion del QuickSort y todo lo necesario para medir su complejidad temporal]
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * Esta funcion intercambia 2 numeros
 * @param {int*} [a] primer numero
 * @param {int*} [b] segundo numero
 */
void intercambio(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}
/**
 * Esta funcion ordena de forma aleatoria un arreglo
 * @param {int*} [array] El arreglo a ordenar
 * @param {size_t} [n] tamaño del arreglo
 */
void shuffle(int *array, size_t n){
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}
/**
 * Esta funcion llena de forma aleatoria un arreglo
 * @param {int*} [array] El arreglo a llenar
 * @param {int} [n] tamaño del arreglo
 */
void llenarArreglo(int *arreglo, int n){
	register int i;
	for(i = 0; i < n; i++){
		arreglo[i] = rand()%999999;
	}
}
/**
 * Esta funcion llena de forma ascendete un arreglo iniciando en 1 y terminando en n
 * @param {int*} [array] El arreglo a llenar
 * @param {int} [n] tamaño del arreglo
 */
void llenarArregloAscendente(int* arreglo, int n){
    register int i;
    for(i = 0; i < n; i++){
        arreglo[i] = i+1;
    }
}
/**
 * Esta funcion imprime un arreglo
 * @param {int*} [array] El arreglo a imprimir
 * @param {int} [n] tamaño del arreglo
 */
void imprimirArreglo(int *arreglo, int n){
	register int i;
	for(i = 0; i < n; i++){
		if(i%16 == 0 && i > 0){
			printf("\n");
		}
		printf("%6d ",arreglo[i]);
	}
	printf("\n");
}
/**
 * Esta funcion invierte los valores dentro de un rango de posiciones en un arreglo
 * @param {int*} [array] El arreglo a invertir
 * @param {int} [desde] La posicion del primer elemento a invertir
 * @param {int} [hasta] La posicion elemento a invertir
 */
void invertirArreglo(int *arreglo, int desde, int hasta){
    register int i;
    int temp;
    for(i = desde; i < (desde+hasta)/2;i++){
        intercambio(&arreglo[i], &arreglo[hasta-i+desde-1]);
    }
}
/**
 * Esta funcion ordena el arreglo acorde a un pivote, garantizando que todo a la izquierda del mismo es menor y todo a la derecha es mayor
 * @param {int*} [array] El arreglo
 * @param {int} [desde] La posicion del primer elemento
 * @param {int} [hasta] La posicion del ultimo elemento
 * @return {int} Retorna el pivote
 */
int Partition(int *A, int *contador, int desde, int hasta){
    int x = A[hasta];(*contador)++;
    int i = desde-1;(*contador)++;
    for(int j = desde; j< hasta;j++){(*contador)++;
        (*contador)++;
        if(A[j]<=x){
            i++;(*contador)++;
            intercambio(&A[i],&A[j]);(*contador)+=3;
        }
    }
    (*contador)++;
    intercambio(&A[i+1],&A[hasta]);(*contador)+=3;
    (*contador)++;
    return i+1;
}
/**
 * Esta funcion ordena un arreglo acorde al algoritmo de QuickSort
 * @param {int*} [array] El arreglo a ordenar
 * @param {int} [desde] La posicion del primer elemento a ordenar
 * @param {int} [hasta] La posicion del ultimo elemento
 */
void QuickSort(int *A, int *contador, int desde, int hasta){
    (*contador)++;
    if(desde<hasta){
        int q = Partition(A, contador, desde, hasta);(*contador)++;
        QuickSort(A, contador, desde, q-1);
        QuickSort(A, contador, q+1, hasta);
    }
}
int main(){
    srand(time(NULL));
    register int n;
    int *arregloQuickSort, *arregloPartition, contadorQuickSort, contadorPartition;
    FILE *nContraOperacionesQuickSort, *nContraOperacionesPartition;
    nContraOperacionesQuickSort = fopen("quickSort_quickSort.dat","w");
    nContraOperacionesPartition = fopen("quickSort_partition.dat","w");
    for(n = 1; n < 100000;n++){
        contadorQuickSort = contadorPartition = 0;

        arregloQuickSort = (int*)malloc(sizeof(int)*n);
        llenarArreglo(arregloQuickSort, n);

        arregloPartition = (int*)malloc(sizeof(int)*n);
        llenarArreglo(arregloPartition, n);

        Partition(arregloPartition,&contadorPartition, 0, n-1);
        fprintf(nContraOperacionesPartition,"%d    %d\n",n,contadorPartition);

        //imprimirArreglo(arregloQuickSort,n);
        QuickSort(arregloQuickSort, &contadorQuickSort, 0, n-1);
        //imprimirArreglo(arregloQuickSort,n);
        fprintf(nContraOperacionesQuickSort,"%d    %d\n",n,contadorQuickSort);
        printf("%d %d\n", n, contadorQuickSort);
        free(arregloQuickSort);
        free(arregloPartition);
    }
    fclose(nContraOperacionesQuickSort);
    fclose(nContraOperacionesPartition);

    //Esta es la seccion de los 4 casos particulares
    FILE *nContraOperacionesCaso1, *nContraOperacionesCaso2, *nContraOperacionesCaso3, *nContraOperacionesCaso4, *nContraOperacionesCombinandoCasos;
    int *arregloAscendente, *arregloDescendente, *arregloAleatorio, *arregloMitad, contadorAscendente, contadorDescendente, contadorAleatorio, contadorMitad;
    nContraOperacionesCaso1 = fopen("quickSort_quickSort_caso1.dat","w");
    nContraOperacionesCaso2 = fopen("quickSort_quickSort_caso2.dat","w");
    nContraOperacionesCaso3 = fopen("quickSort_quickSort_caso3.dat","w");
    nContraOperacionesCaso4 = fopen("quickSort_quickSort_caso4.dat","w");
    nContraOperacionesCombinandoCasos = fopen("quickSort_quickSort_combinado.dat","w");
    for(n = 1; n < 100000; n++){
        arregloAscendente = (int*)malloc(sizeof(int)*n);
        arregloDescendente = (int*)malloc(sizeof(int)*n);
        arregloAleatorio = (int*)malloc(sizeof(int)*n);
        arregloMitad = (int*)malloc(sizeof(int)*n);

        llenarArregloAscendente(arregloAscendente,n);
        llenarArregloAscendente(arregloAleatorio,n);
        llenarArregloAscendente(arregloDescendente,n);
        llenarArregloAscendente(arregloMitad,n);

        invertirArreglo(arregloDescendente, 0, n);
        invertirArreglo(arregloMitad,n/2,n);
        shuffle(arregloAleatorio,n);

        contadorAscendente = contadorDescendente = contadorAleatorio = contadorMitad = 0;

        QuickSort(arregloAscendente,&contadorAscendente, 0, n);
        QuickSort(arregloDescendente,&contadorDescendente, 0, n);
        QuickSort(arregloAleatorio,&contadorAleatorio, 0, n);
        QuickSort(arregloMitad,&contadorMitad, 0, n);

        fprintf(nContraOperacionesCaso1,"%d    %d\n",n,contadorAscendente);
        fprintf(nContraOperacionesCaso2,"%d    %d\n",n,contadorDescendente);
        fprintf(nContraOperacionesCaso3,"%d    %d\n",n,contadorAleatorio);
        fprintf(nContraOperacionesCaso4,"%d    %d\n",n,contadorMitad);
        fprintf(nContraOperacionesCombinandoCasos,"%d    %d    %d    %d    %d\n",n,contadorAscendente, contadorDescendente, contadorAleatorio, contadorMitad);

        printf("%d\n",n);

        //free(arregloAscendente);
        //free(arregloDescendente);
        //free(arregloAleatorio);
        //free(arregloMitad);
    }
    fclose(nContraOperacionesCaso1);
    fclose(nContraOperacionesCaso2);
    fclose(nContraOperacionesCaso3);
    fclose(nContraOperacionesCaso4);
    fclose(nContraOperacionesCombinandoCasos);
    return 0;
}
