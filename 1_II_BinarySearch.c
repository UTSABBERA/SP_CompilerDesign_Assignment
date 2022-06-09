//Binary Search Implementation
#include <stdio.h>

int binarySearch(int arr[], int start, int end, int val) {
    if (start > end) return -1; //base case

    //checking the mid element and recursivly decreasing search range by half
    int mid = (start+end)/2;
    if (arr[mid] > val) return binarySearch(arr, start, mid-1, val);
    if (arr[mid] < val) return binarySearch(arr, mid+1, end, val);
    return mid;
}

int main() {
    int a[30], v, n;
    printf("Enter Array Size: ");
    scanf("%d", &n);
    printf("Enter Elements(sorted): ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter The Value To Be Searched: ");
    scanf("%d", &v);

    int res = binarySearch(a, 0, n-1, v);

    if (res != -1) printf("The index of the value in the array is %d", res);
    else printf("The value is not present in the array");

    return 0;
}