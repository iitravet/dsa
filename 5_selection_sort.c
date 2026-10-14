#include <stdio.h>

typedef struct {
    int roll_no;
    char name[50];
    float sgpa;
} Student;

void selectionSort(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].sgpa > arr[max_idx].sgpa) max_idx = j;
        }
        Student temp = arr[max_idx];
        arr[max_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    Student s[] = {{1, "Alice", 8.2}, {2, "Bob", 9.5}, {3, "Charlie", 9.1}};
    selectionSort(s, 3);
    printf("Toppers:\n");
    for(int i = 0; i < 3; i++) printf("%s - %.2f\n", s[i].name, s[i].sgpa);
    return 0;
}
