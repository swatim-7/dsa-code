#include <stdio.h>

int main() {
    int t;

    scanf("%d", &t);

    while(t--) {
        int n, key, count = 0;

        scanf("%d", &n);
        int arr[n];

        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        scanf("%d", &key);

        int i = 0;
        int found = 0;

        for(i = 0; i < n; i += 2) {
            count++;
            if(arr[i] == key) {
                found = 1;
                break;
            }
            else if(arr[i] > key) {
                break;  // Key must be between arr[i-2] and arr[i]
            }
        }
 
        // Linear search in previous block if key wasn't found
        if(!found) {
            int start = (i >= 2) ? i - 2 : 0;
            for(int j = start; j < n && j < i; j++) {
                count++;
                if(arr[j] == key) {
                    found = 1;
                    break;
                }
            }
        }

        if(found)
            printf("Present.  comparisons  = %d\n", count);
        else
            printf("Not Present.  comparisons  =  %d\n", count); 
    }
    return 0;
}
 