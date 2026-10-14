#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) { stack[++top] = x; }
char pop() { return (top == -1) ? -1 : stack[top--]; }
int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

void infixToPostfix(char* exp) {
    char x;
    while (*exp != '\0') {
        if (isalnum(*exp)) printf("%c", *exp);
        else if (*exp == '(') push(*exp);
        else if (*exp == ')') {
            while ((x = pop()) != '(') printf("%c", x);
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(*exp))
                printf("%c", pop());
            push(*exp);
        }
        exp++;
    }
    while (top != -1) printf("%c", pop());
    printf("\n");
}

int main() {
    char exp[] = "A+B*C";
    printf("Postfix: ");
    infixToPostfix(exp);
    return 0;
}
