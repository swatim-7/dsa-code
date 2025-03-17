#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

int partition(int arr[], int l, int r, int x) {
    int i;
    for (i = l; i < r; i++)
        if (arr[i] == x)
            break;
    swap(&arr[i], &arr[r]);

    i = l;
    for (int j = l; j < r; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int findMedian(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    return arr[n/2];
}

int kSmallest(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int n = r - l + 1;
        int i, median[(n+4)/5]; // groups of 5
        for (i = 0; i < n/5; i++)
            median[i] = findMedian(arr + l + i*5, 5);
        if (i*5 < n) {
            median[i] = findMedian(arr + l + i*5, n%5);
            i++;
        }
        int medOfMed = (i == 1) ? median[i-1] : kSmallest(median, 0, i-1, i/2);
        int pos = partition(arr, l, r, medOfMed);

        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return kSmallest(arr, l, pos - 1, k);
        return kSmallest(arr, pos + 1, r, k - pos + l - 1);
    }
    return -1;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, k;
        scanf("%d", &n);
        int arr[n];
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        scanf("%d", &k);
        if(k <= 0 || k > n) {
            printf("not present\n");
        } else {
            int result = kSmallest(arr, 0, n - 1, k);
            printf("%d\n", result);
        }
    }
    return 0;
}
