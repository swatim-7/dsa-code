#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);  // number of test cases

    while(t--) {
        int n;
        scanf("%d", &n);  // size of array
        int arr[n];
        
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);  // array elements
        }

        int found = 0;

        // Try each k from index 2 to n-1
        for(int k = 2; k < n; k++) {
            int i = 0, j = k - 1;

            // Two pointer search
            while(i < j) {
                int sum = arr[i] + arr[j];
                if(sum == arr[k]) {
                    printf("%d %d %d\n", i, j, k);
                    found = 1;
                    break;
                } else if(sum < arr[k]) {
                    i++;
                } else {
                    j--;
                }
            }

            if(found)
                break;
        }

        if(!found) {
            printf("No sequence found\n");
        }
    }

    return 0;
}
