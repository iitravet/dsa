#include <stdio.h>
#include <string.h>

typedef struct {
    int roll_no;
    char name[50];
    float sgpa;
} Student;

void insertionSort(Student arr[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = arr[i];
        int j = i - 1;
        while (j >= 0 && strcmp(arr[j].name, key.name) > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    Student s[] = {{1, "Charlie", 9.2}, {2, "Alice", 8.5}, {3, "Bob", 9.8}};
    insertionSort(s, 3);
    printf("Sorted Alphabetically:\n");
    for(int i = 0; i < 3; i++) printf("%s\n", s[i].name);
    return 0;
}
