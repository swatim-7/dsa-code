#include <stdio.h>

// Function to find first occurrence
int firstOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            result = mid;
            high = mid - 1;  // search in left part
        } else if (key < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

// Function to find last occurrence
int lastOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            result = mid;
            low = mid + 1;  // search in right part
        } else if (key < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
} 

int main() {
    int t;
    scanf("%d", &t);  // number of test cases

    while (t--) {
        int n, key;
        scanf("%d", &n);  // size of array
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);  // array elements
        }
        scanf("%d", &key);  // key to search

        int first = firstOccurrence(arr, n, key);
        int last = lastOccurrence(arr, n, key);

        if (first == -1) {
            printf("Key not present\n");
        } else {
            int count = last - first + 1;
            printf("%d - %d\n", key, count);
        }
    }

    return 0;
}
