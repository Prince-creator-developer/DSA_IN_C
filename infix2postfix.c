#include <stdio.h>
#include <string.h>


int input(char symbol) {
    switch(symbol) {
        case '+':
        case '-': return 1;
        case '*':
        case '%':
        case '/': return 3;
        case '^':
        
        case '$': return 6;
        case '(': return 9;
        case ')': return 0;
        default: return 7;  // operands
    }
}

int stack(char symbol) {
    switch(symbol) {
        case '+':
        case '-': return 2;
        case '*':
        case '%':
        case '/': return 4;
        case '^':
        case '$': return 5;
        case '(': return 0;
        case '#': return -1;  // bottom marker
        default: return 8;    // operands
    }
}
void Infix_to_postfix(char infix[], char postfix[]) {
    int top = -1, i, j = 0;
    char s[20], symbol;
    s[++top] = '#';
    
    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        while (stack(s[top]) > input(symbol)) {
            postfix[j++] = s[top--];
        }

        if (stack(s[top]) != input(symbol)) {
            s[++top] = symbol;
        } else {
            top--;  // discard matching '('
        }
    }

    while (s[top] != '#') {
        postfix[j++] = s[top--];
    }

    postfix[j] = '\0';
}

int main() {
    char infix[20], postfix[20];
    printf("Enter the infix expression:\n");
    scanf("%s", infix);

    Infix_to_postfix(infix, postfix);

    printf("Infix expression: %s\n", infix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
//gcc infix2postfix.c -o infix2postfix.exe
//./infix2postfix.exe
