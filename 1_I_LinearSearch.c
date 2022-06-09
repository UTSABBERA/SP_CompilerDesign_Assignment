//Linear Search implementation
#include <stdio.h>

int linearSearch(int arr[], int size, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) return i;
    }
    return -1;
}

int main() {
    int a[30], v, n;
    printf("Enter Array Size: ");
    scanf("%d", &n);
    printf("Enter Elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter The Value To Be Searched: ");
    scanf("%d", &v);

    int res = linearSearch(a, n, v); //result : index or -1

    if (res != -1) printf("The index of the value in the array is %d", res);
    else printf("The value is not present in the array");

    return 0;
}