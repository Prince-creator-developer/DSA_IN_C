#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* * Returns the input precedence of the symbol.
 * + - : 1
 * * / % : 3
 * ( : 9 (Highest to ensure it gets pushed)
 * ) : 0 (Lowest to ensure it forces pops)
 * Operands : 7
 */
int input(char symbol) {
    switch(symbol) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': 
        case '%': return 3; // Added Modulus
        case '(': return 9;
        case ')': return 0;
        default: return 7;  // operands (alphanumeric)
    }
}

/* * Returns the stack precedence of the symbol.
 * + - : 2 (Higher than input to force left-associativity)
 * * / % : 4
 * ( : 0 (Lowest so nothing pops it except matching parenthesis)
 * # : -1 (Bottom marker)
 * Operands : 8
 */
int stack(char symbol) {
    switch(symbol) {
        case '+':
        case '-': return 2;
        case '*':
        case '/': 
        case '%': return 4; // Added Modulus
        case '(': return 0;
        case '#': return -1;  // bottom marker
        default: return 8;    // operands
    }
}

void Infix_to_postfix(char infix[], char postfix[]) {
    int top = -1, i, j = 0;
    char s[30], symbol;
    s[++top] = '#'; // Push bottom marker
    
    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        // While priority of stack top > priority of input symbol
        while (stack(s[top]) > input(symbol)) {
            postfix[j++] = s[top--];
        }

        // Check if we need to push the symbol or discard parenthesis
        if (stack(s[top]) != input(symbol)) {
            s[++top] = symbol;
        } else {
            top--;  // discard matching '(' when ')' is encountered
        }
    }

    // Pop remaining symbols until stack is empty (marker '#')
    while (s[top] != '#') {
        postfix[j++] = s[top--];
    }

    postfix[j] = '\0'; // Null-terminate the string
}

int main() {
    char infix[30], postfix[30];
    
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    Infix_to_postfix(infix, postfix);

    printf("Infix expression: %s\n", infix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}