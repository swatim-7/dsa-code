#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n, key, count = 0, found = 0;

        scanf("%d", &n);
        int arr[n];

        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        scanf("%d", &key);

        int low = 0, high = n - 1;
        while(low <= high) {
            count++;
            int mid = (low + high) / 2;

            if(arr[mid] == key) {
                found = 1;
                break;
            } else if(key < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } 
 
        if(found)
            printf("Present.  comparisons  = %d\n", count);
        else
            printf("Not Present.  comparisons  =  %d\n", count); 
    }

    return 0;
}
