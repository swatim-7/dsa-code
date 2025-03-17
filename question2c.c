#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);   

    while(t--) {
        int n, k, count = 0;
        scanf("%d", &n);  
        int arr[n];
        
        // Reading array elements
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        scanf("%d", &k);  // key difference value

        // Check all pairs
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(abs(arr[i] - arr[j]) == k) {
                    count++;
                }
            }
        }

        // Print the number of such pairs
        printf("%d\n", count);
    }

    return 0;
}
