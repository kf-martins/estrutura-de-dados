#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bobbleSort(int* arr, int size, int* out_comps, int* out_swaps) {
    int temp;
    *out_comps = 0;
    *out_swaps = 0;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                *out_swaps += 1;
            }
            *out_comps += 1;
        }
    }
}

void selectionSort(int* arr, int size) {
    int min;

    for (int i = 0; i < size - 1; i++) {
        min = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) min = j;
        }

        swap(&arr[min], &arr[i]);
    }
}

void merge(int* arr, int start, int mid, int end) {
    int p = start, q = mid + 1, k = 0;
    int aux[end - start + 1];

    for (int i = start; i <= end; i++) {
        if (p > mid)
            aux[k++] = arr[q++];
        else if (q > end)
            aux[k++] = arr[p++];
        else if (arr[p] < arr[q])
            aux[k++] = arr[p++];
        else
            aux[k++] = arr[q++];
    }

    for (int p = 0; p < k; p++) {
        arr[start++] = aux[p];
    }
}

void mergeSort(int* arr, int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;

        mergeSort(arr, s, m);
        mergeSort(arr, m + 1, e);

        merge(arr, s, m, e);
    }
}

void mergeSort_count(int* arr, int s, int e, int* out_merges, int* out_max_depth, int depth) {
    if (s < e) {
        if (depth > *out_max_depth) 
            *out_max_depth = depth;
        int m = (s + e) / 2;

        mergeSort_count(arr, s, m, out_merges, out_max_depth, depth + 1);
        mergeSort_count(arr, m + 1, e, out_merges, out_max_depth, depth + 1);
        merge(arr, s, m, e);
        *out_merges += 1;
    }
}

void mergeSort_instrumented(int* arr, int s, int e, int* out_merges, int* out_max_depth) {
    *out_merges = 0;
    *out_max_depth = 0;
    mergeSort_count(arr, s, e, out_merges, out_max_depth, 1);
}

int partition(int* arr, int low, int high, int* out_comps) {
    int pivotIndex = low + rand() % (high - low + 1);
    swap(&arr[pivotIndex], &arr[high]);
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        *out_comps += 1;

        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int* arr, int low, int high, int* out_comps) {
    if (low < high) {
        int p = partition(arr, low, high, out_comps);
        
        quickSort(arr, low, p - 1, out_comps);
        quickSort(arr, p + 1, high, out_comps);
    }
}
