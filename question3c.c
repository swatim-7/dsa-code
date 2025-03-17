#include <stdio.h>

// Function to sort the array using selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);  // Number of test cases

    while (t--) {
        int n;
        scanf("%d", &n);  // Size of array

        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        // Sort the array
        selectionSort(arr, n);

        // Check for duplicates
        int duplicateFound = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] == arr[i + 1]) {
                duplicateFound = 1;
                break;
            }
        }

        if (duplicateFound)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
