#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char title[50];
    int duration;
    struct Node* next;
} Node;

Node* head = NULL;

void addSong(char* title, int duration) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->title, title);
    newNode->duration = duration;
    newNode->next = NULL;
    if (!head) { head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void displayPlaylist() {
    Node* temp = head;
    while (temp) {
        printf("%s (%ds) -> ", temp->title, temp->duration);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    addSong("Song A", 180);
    addSong("Song B", 210);
    displayPlaylist();
    return 0;
}
