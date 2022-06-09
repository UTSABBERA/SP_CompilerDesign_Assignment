//Interchange Sort Implementation
#include <stdio.h>

void interchangeSort(int arr[], int size) {
    for (int i = 0; i < size; i++) 
        for (int j = i; j < size; j++) 
            if (arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
    //elements are sorted
}

int main() {
    int a[30], v, n;
    printf("Enter Array Size: ");
    scanf("%d", &n);
    printf("Enter Elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    interchangeSort(a, n); //sorting

    printf("After sorting:\n");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);

    return 0;
}