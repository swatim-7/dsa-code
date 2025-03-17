#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0, swaps = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

int partition(int arr[], int low, int high) {
    // Select a random pivot and swap it with last element
    int randomIndex = low + rand() % (high - low + 1);
    swap(&arr[randomIndex], &arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int T;
    scanf("%d", &T);

    srand(time(NULL));  // Seed for random pivot selection

    while (T--) {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        comparisons = 0;
        swaps = 0;

        quickSort(arr, 0, n - 1);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\nComparisons = %d\n", comparisons);
        printf("Swaps = %d\n", swaps);
    }

    return 0;
}
