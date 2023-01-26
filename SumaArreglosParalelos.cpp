// SumaArreglosParalelos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
/*
* Maestría en Inteligencia Artificial
* Computo en la nube
* Desarrollado por: Luis Hermenegildo
*/

#include <iostream>
//#ifdef _OPENMP
    #include<omp.h>
//#else
//    #define omp_get_thread_num() 0
//#endif

using namespace std;
//int tid;


//Definiendo variables a utilizar

#define N 1000
#define chunk 100
#define mostrar 20

void imprimeArreglo(double *d);

int main()
{
    //Creando arreglos de longitud N
    double a[N], b[N], c[N];
    //Asignando valores aleatorios
    for (int i = 0; i < N; i++) {
        a[i] = i * 2;
        b[i] = i * 3;
    }
   
    int partes = chunk;
    int i = 0;
    //Creación de un for paralelo con OpenMP
    #pragma omp parallel for \
    shared(a,b,c, partes) private(i) \
    schedule(static, partes)

    for (i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }

    cout << "Imprimientdo los primeros " << mostrar << " valores del arreglo a: " << endl;
    imprimeArreglo(a);
    cout << "Imprimientdo los primeros " << mostrar << " valores del arreglo b: " << endl;
    imprimeArreglo(b);
    cout << "Imprimientdo los primeros " << mostrar << " valores del arreglo c: " << endl;
    imprimeArreglo(c);

}

void imprimeArreglo(double *arr) {
    for (int j = 0; j < mostrar; j++) {
        cout << arr[j] << " - ";
    }
    cout << endl;
}
