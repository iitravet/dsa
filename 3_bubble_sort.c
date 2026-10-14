#include <stdio.h>
#include <string.h>

typedef struct {
    int roll_no;
    char name[50];
    float sgpa;
} Student;

void bubbleSort(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].roll_no > arr[j + 1].roll_no) {
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    Student s[] = {{3, "Alice", 9.2}, {1, "Bob", 8.5}, {2, "Charlie", 9.8}};
    bubbleSort(s, 3);
    printf("Sorted by Roll No:\n");
    for(int i = 0; i < 3; i++) printf("%d - %s\n", s[i].roll_no, s[i].name);
    return 0;
}
