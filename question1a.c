#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--){ 
        int n, key, count = 0, found = 0;

        scanf("%d", &n); 
        int arr[n];
        
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        scanf("%d", &key);

        for(int i = 0; i < n; i++) {
            count++; 
            if(arr[i] == key) {
                found = 1;
                break; 
            }
        } 

        if(found)
            printf("Present.  comparisons  = %d\n", count);
        else
            printf("Not Present.  comparisons  =  %d\n", count); 
    }

    return 0;
}

