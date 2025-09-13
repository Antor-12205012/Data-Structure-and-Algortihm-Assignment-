#include <stdio.h>
#include <stdlib.h>

struct Bucket {
    int count;
    int* values;
};
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void bucketSort(int arr[], int n) {
    int i, j, k;
    int max = arr[0];
    int min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    int bucketCount = max - min + 1; 
    struct Bucket buckets[bucketCount];
    for (i = 0; i < bucketCount; i++) {
        buckets[i].count = 0;
        buckets[i].values = (int*)malloc(n * sizeof(int));
    }
    for (i = 0; i < n; i++) {
        int bucketIndex = arr[i] - min;
        buckets[bucketIndex].values[buckets[bucketIndex].count++] = arr[i];
    }
    k = 0;
    for (i = 0; i < bucketCount; i++) {
        if (buckets[i].count > 0) {
            insertionSort(buckets[i].values, buckets[i].count);
            for (j = 0; j < buckets[i].count; j++) {
                arr[k++] = buckets[i].values[j];
            }
        }
        free(buckets[i].values); 
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {42, 32, 33, 52, 37, 47, 51};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
