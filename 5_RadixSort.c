//Radix Sort Implementation
#include <stdio.h>

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > mx) mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int output[100]; // output array
    int i, count[10] = {0};
    for (i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++) count[i] += count[i - 1]; //poses for output[] 
    for (i = n - 1; i >= 0; i--) { //building the output[]
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++) arr[i] = output[i];
}

void radixsort(int arr[], int n) {
    int m = getMax(arr, n);
    //sort with countSort() for every digit(least to most significant)
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main() {
    int a[100], n;
    printf("Enter Array Size: ");
    scanf("%d", &n);
    printf("Enter Elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    radixsort(a, n); //sorting

    printf("After sorting:\n");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);

    return 0;
}