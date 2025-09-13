#include <stdio.h>
#include <string.h>  

void countingSort(int arr[], int n) {
    int output[n]; 
    int max = arr[0];
    int i;

    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    int count[max + 1];
    memset(count, 0, sizeof(count));

    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {2,5,3,0,2,3,0,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    printArray(arr, n);
    countingSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
