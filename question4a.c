#include <stdio.h>

int comparisons = 0, inversions = 0;

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        comparisons++;
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int temp[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        int arr[n], temp[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        comparisons = 0;
        inversions = 0;

        mergeSort(arr, temp, 0, n - 1);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\nComparisons = %d\n", comparisons);
        printf("Inversions = %d\n", inversions);
    }

    return 0;
}
