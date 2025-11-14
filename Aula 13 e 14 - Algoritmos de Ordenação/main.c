#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "algoritmos.c"

/*
Implementeações dos algoritmos de ordenação estão no arquivo "algoritmos.c"
*/

void printArr(int* arr, int size) {
    for (int i = 0; i < size; i++) printf("%d, ", arr[i]);
    printf("\n");
}

void exercicio2() {
    int trocas = 0, comps = 0;

    int arr1[] = {1, 2, 3, 4, 5};
    int n1 = (int)sizeof(arr1) / sizeof(int);
    bobbleSort(arr1, n1, &comps, &trocas);
    printf("Ex2 - Ordem crescente\nTrocas: %d\nComparacoes: %d\n", trocas,
           comps);

    int arr2[] = {5, 4, 3, 2, 1};
    int n2 = (int)sizeof(arr2) / sizeof(int);
    bobbleSort(arr2, n2, &comps, &trocas);
    printf("Ex2 - Ordem decrescente\nTrocas: %d\nComparacoes: %d\n", trocas,
           comps);

    int arr3[] = {7, 2, 9, 4, 1};
    int n3 = (int)sizeof(arr3) / sizeof(int);
    bobbleSort(arr3, n3, &comps, &trocas);
    printf("Ex2 - Aleatoria\nTrocas: %d\nComparacoes: %d\n", trocas, comps);
}

void exercicio6() {
    int n = 16;
    int arr[16];
    for (int i = 0; i < n; i++) arr[i] = (n - i) * 3;

    int merges = 0, maxDepth = 0;
    mergeSort_instrumented(arr, 0, n - 1, &merges, &maxDepth);
    printf("Ex6 - MergeSort\nMerges: %d\nNiveis: %d\n", merges, maxDepth);
}

void exercicio7() {
    srand(123);
    const int n = 1000;
    static int arr[1000];
    int comps;
    double ms;
    clock_t t0, t1;

    for (int i = 0; i < n; i++) // crescente
        arr[i] = i + 1;
    comps = 0;
    t0 = clock();
    quickSort(arr, 0, n - 1, &comps);
    t1 = clock();
    ms = (double)(t1 - t0) * 1000.0 / CLOCKS_PER_SEC;
    printf("Ex7 - 1000 crescente\ncomps=%d tempo=%.3f ms\n", comps, ms);

    for (int i = 0; i < n; i++) // decrescente
        arr[i] = n - i;
    comps = 0;
    t0 = clock();
    quickSort(arr, 0, n - 1, &comps);
    t1 = clock();
    ms = (double)(t1 - t0) * 1000.0 / CLOCKS_PER_SEC;
    printf("Ex7 - 1000 decrescente\ncomps=%d tempo=%.3f ms\n", comps, ms);

    for (int i = 0; i < n; i++) // aleatoria
        arr[i] = rand();
    comps = 0;
    t0 = clock();
    quickSort(arr, 0, n - 1, &comps);
    t1 = clock();
    ms = (double)(t1 - t0) * 1000.0 / CLOCKS_PER_SEC;
    printf("Ex7 - 1000 aleatoria\ncomps=%d tempo=%.3f ms\n", comps, ms);
}

int main() {
    exercicio2();
    printf("\n");
    exercicio6();
    printf("\n");
    exercicio7();

    return 0;
}
