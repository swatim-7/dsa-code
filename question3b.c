#include <stdio.h>

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

        int comparisons = 0, swaps = 0;

        // Selection Sort
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                comparisons++;
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            // Swap only if needed
            if (minIndex != i) {
                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
                swaps++;
            }
        }

        // Print sorted array
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // Print comparisons and swaps
        printf("Comparisons = %d\n", comparisons);
        printf("Swaps = %d\n", swaps);
    }

    return 0;
}
