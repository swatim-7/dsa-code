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

        int comparisons = 0, shifts = 0;

        // Insertion Sort
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            // Compare and shift elements greater than key
            while (j >= 0) {
                comparisons++;
                if (arr[j] > key) {
                    arr[j + 1] = arr[j];
                    shifts++;
                    j--;
                } else {
                    break;
                }
            }

            arr[j + 1] = key;
            shifts++; // placing the key at its position is also considered a shift
        }

        // Print sorted array
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // Print number of comparisons and shifts
        printf("Comparisons = %d\n", comparisons);
        printf("Shifts = %d\n", shifts);
    }

    return 0;
}
