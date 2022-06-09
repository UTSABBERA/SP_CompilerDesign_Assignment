//Shell Sort Implementation
#include <stdio.h>

void shellSort(int arr[], int size) {
    for (int i = size/2; i > 0; i/=2) { //i = interval : decreasing by half
        for (int j = i; j < size; j++) {
            int val = arr[j], k; // value to be inserted
            for (k = j-i; k >= 0 && arr[k] > arr[k+i]; k-=i) {
                arr[k+i] = arr[k];
            }
            arr[k+i] = val;
        }
    }
}

int main () {
    int a[100], n;
    printf("Enter Array Size: ");
    scanf("%d", &n);
    printf("Enter Elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    shellSort(a, n); //sorting

    printf("After sorting:\n");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);

    return 0;
}