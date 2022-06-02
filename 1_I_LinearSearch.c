//Linear Search implementation
#include <stdio.h>

int linearSearch(int arr[], int size, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) return i;
    }
    return -1;
}

int main() {
    int a[] = {1, 5, 3, 2, 6}; //example array
    int v = 5; //value to be searched
    int n = sizeof(a)/sizeof(a[0]); //size

    int res = linearSearch(a, n, v); //result : index or -1

    if (res != -1) printf("The index of the value in the array is %d", res);
    else printf("The value is not present in the array");

    return 0;
}