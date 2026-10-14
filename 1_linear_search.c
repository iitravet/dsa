#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

int linearSearchRecursive(int arr[], int n, int key, int index) {
    if (index >= n) return -1;
    if (arr[index] == key) return index;
    return linearSearchRecursive(arr, n, key, index + 1);
}

int main() {
    int arr[] = {10, 25, 30, 45, 50};
    int key = 30;
    printf("Non-Recursive: Index %d\n", linearSearch(arr, 5, key));
    printf("Recursive: Index %d\n", linearSearchRecursive(arr, 5, key, 0));
    return 0;
}
