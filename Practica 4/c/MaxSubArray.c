/**
 * @author Payán Téllez René
 * @email rpayant1500@alumno.ipn.mx
 * @create date 2020-12-03 01:00pm
 * @modify date 2020-12-04 07:05pm
 * @desc [Este archivo tiene la implementacion del MaxSubArray y todo lo necesario para medir su complejidad temporal]
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct{
    int maximaSuma, indexIzquierdo, indexDerecho;
} retorno;

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
 * Esta funcion llena de forma aleatoria un arreglo
 * @param {int*} [array] El arreglo a llenar
 * @param {int} [n] tamaño del arreglo
 */
void llenarArreglo(int *arreglo, int n){
	register int i;
	int signo;
	for(i = 0; i < n; i++){
        signo = rand()%10;
		arreglo[i] = rand()%999999;
		if(signo%2 == 0){
            arreglo[i]*=-1;
        }
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
    for(i = desde; i < (desde+hasta)/2;i++){
        intercambio(&arreglo[i], &arreglo[hasta-i+desde-1]);
    }
}
/**
 * Esta funcion retorna la suma del maximo sub arreglo, utilizando fuerza bruta
 * @param {int*} [arreglo] El arreglo
 * @param {int} [n] El tamaño del arreglo
 * @param {int*} [contador] Contador de operaciones
 * @return {retorno} Retorna la suma del maximo sub arreglo y los index
 */
retorno fuerzaBruta(int* arreglo, int n, int *contador){
    register int i;(*contador)++;
    register int j;(*contador)++;
    int maximaSuma, sumaLocal, lIndex, rIndex;(*contador)++;
    maximaSuma = INT_MIN;(*contador)++;
    for(i = 0; i < n; i++){(*contador)++;
        sumaLocal = 0;(*contador)++;
        for( j = i; j < n; j++){(*contador)++;
            sumaLocal+=arreglo[j];(*contador)++;
            if(sumaLocal > maximaSuma){(*contador)++;
                maximaSuma = sumaLocal;(*contador)++;
                lIndex = i;(*contador)++;
                rIndex = j;(*contador)++;
            }else{
                (*contador)++;
            }
        }
        (*contador)++;
    }
    (*contador)++;
    retorno rt = {maximaSuma, lIndex, rIndex};(*contador)++;
    (*contador)++;
    return rt;
}

retorno MaxCrossingSubArray(int* arreglo, int bajo, int mitad, int alto, int *contador){
    int max_izq, max_der, suma, suma_izq, suma_der;(*contador)++;
    register int i;(*contador)++;
    max_izq = max_der = INT_MIN;(*contador)++;
    suma = 0;(*contador)++;
    for(i = mitad; i >= bajo; i--){(*contador)++;
        suma+=arreglo[i];(*contador)++;
        if(suma>suma_izq){(*contador)++;
            max_izq = i;(*contador)++;
            suma_izq = suma;(*contador)++;
        }else{
            (*contador)++;
        }
    }
    (*contador)++;
    suma = 0;(*contador)++;
    for(i = mitad+1; i < alto; i++){(*contador)++;
        suma+=arreglo[i];(*contador)++;
        if(suma>suma_der){(*contador)++;
            max_der = i;(*contador)++;
            suma_der = suma;(*contador)++;
        }else{
            (*contador)++;
        }
    }
    (*contador)++;
    retorno rt;(*contador)++;
    rt.maximaSuma = suma_der+suma_izq;(*contador)++;
    rt.indexIzquierdo = max_izq;(*contador)++;
    rt.indexDerecho = max_der;(*contador)++;
    (*contador)++;
    return rt;
}
retorno MaxSubArrayDC(int *arreglo, int bajo, int alto, int *contador){
    retorno rt; (*contador)++;
    if(bajo == alto){(*contador)++;
        rt.maximaSuma = arreglo[bajo];(*contador)++;
        rt.indexIzquierdo = bajo;(*contador)++;
        rt.indexDerecho = alto;(*contador)++;
    }else{(*contador)++;
        int mitad = (bajo+alto)/2;(*contador)++;
        retorno izquierda, derecha, cruzado;(*contador)++;
        izquierda = MaxSubArrayDC(arreglo, bajo, mitad, contador);
        derecha = MaxSubArrayDC(arreglo, mitad+1, alto, contador);
        cruzado = MaxCrossingSubArray(arreglo, bajo, mitad, alto, contador);
        if(izquierda.maximaSuma > derecha.maximaSuma && izquierda.maximaSuma > cruzado.maximaSuma){(*contador)++;
            rt = izquierda;(*contador)++;
        }else if(derecha.maximaSuma > izquierda.maximaSuma && derecha.maximaSuma > cruzado.maximaSuma){(*contador)++;
            rt = derecha;(*contador)++;
        }else{(*contador)++;
            rt = cruzado;(*contador)++;
        }
    }
    (*contador)++;
    return rt;
}
int main(){
    srand(time(NULL));
    register int n;
    int *arreglo, contadorDivideYVenceras,contadorFuerzaBruta,contadorCruzado;
    retorno retornoFuerzaBruta, retornoDivideYVenceras, retornoCruzado;
    FILE *nContraoperacionesDivideYVenceras, *nContraoperacionesFuerzaBruta, *nContraOperacionesCombiando, *nContraoperacionesCruzado;
    nContraoperacionesDivideYVenceras = fopen("maxsubarray_divideyvenceras.dat","w");
    nContraoperacionesCruzado = fopen("maxsubarray_maximoCruzado.dat","w");
    nContraoperacionesFuerzaBruta = fopen("maxsubarray_fuerzabruta.dat","w");
    nContraOperacionesCombiando = fopen("maxsubarray_combinado.dat","w");
    for(n = 1; n < 10000;n++){
        arreglo = (int*)malloc(sizeof(int)*n);
        contadorDivideYVenceras = contadorFuerzaBruta = contadorCruzado = 0;

        llenarArreglo(arreglo, n);

        retornoCruzado = MaxCrossingSubArray(arreglo, 0, n/2, n, &contadorCruzado);
        retornoFuerzaBruta = fuerzaBruta(arreglo, n, &contadorFuerzaBruta);
        retornoDivideYVenceras = MaxSubArrayDC(arreglo, 0, n, &contadorDivideYVenceras);

        fprintf(nContraoperacionesDivideYVenceras,"%d    %d\n",n,contadorDivideYVenceras);
        fprintf(nContraoperacionesFuerzaBruta,"%d    %d\n",n,contadorFuerzaBruta);
        fprintf(nContraOperacionesCombiando,"%d    %d     %d\n",n,contadorDivideYVenceras,contadorFuerzaBruta);
		fprintf(nContraoperacionesCruzado, "%d    %d\n",n,contadorCruzado);
		
        printf("%d %d %d %d\n", n, contadorCruzado, contadorDivideYVenceras, contadorFuerzaBruta);
        free(arreglo);
    }
    fclose(nContraoperacionesCruzado);
    fclose(nContraoperacionesDivideYVenceras);
    fclose(nContraoperacionesFuerzaBruta);
    fclose(nContraOperacionesCombiando);
    return 0;
}
