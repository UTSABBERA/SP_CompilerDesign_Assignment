#include <stdio.h>

int interchangeSort(int arr[], int size) {
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
    int a[] = {2, 5, 3, 1, 6, 4}; //example array
    int n = sizeof(a)/sizeof(a[0]); //size
    
    interchangeSort(a, n); //sorting

    printf("After sorting:\n");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);

    return 0;
}