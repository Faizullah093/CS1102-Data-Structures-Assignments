#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if(top == -1) return -1;
    return stack[top--];
}

int priority(char x) {
    if(x == '(') return 0;
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char exp[] = "a+b*(c-d)"; // Örnek ifade
    char *e, x;
    printf("Infix ifade: %s\n", exp);
    printf("Postfix sonuc: ");
    e = exp;

    while(*e != '\0') {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')') {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ", pop());
            push(*e);
        }
        e++;
    }
    while(top != -1) {
        printf("%c ", pop());
    }
    printf("\n");
    return 0;
}