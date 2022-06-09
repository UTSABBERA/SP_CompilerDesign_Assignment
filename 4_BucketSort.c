//Bucket Sort Implementation (Simple version for single digit numbers)
#include <stdio.h>

void bucketSort(int arr[], int n) {
    int bucket[10] = {0}; //bucket for every number
    for (int i = 0; i < n; i++) bucket[arr[i]]++; //distributing
    for (int i = 0, j = 0; i < 10; i++) {
        for (; bucket[i] > 0; bucket[i]--) arr[j++] = i; //marging
    } 
}

int main() {
    int a[100], n;
    printf("Enter Array Size: ");
    scanf("%d", &n);
    printf("Enter Elements(0-9): ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    bucketSort(a, n); //sorting

    printf("After sorting:\n");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);

    return 0;
}
