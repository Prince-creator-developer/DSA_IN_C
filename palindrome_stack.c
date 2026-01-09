
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For exit()

#define MAX_SIZE 100

// --- Stack Functions (Assumed to be here) ---
char stack[MAX_SIZE];
int top = -1; 
void push(char c);
char pop();
int isEmpty();
// --- End of Stack Functions ---


int main() {
    char inputString[MAX_SIZE];
    int length,i;
    int isPalindrome = 1;// Flag, 1 = true, 0 = false

    // 1. Get the input string (CHANGED to the simple way)
    printf("Enter a string to check for palindrome: ");
    // WARNING: This is simple, but it is DANGEROUS (buffer overflow)
    // and it will NOT work for strings with spaces (e.g., "race car").
    scanf("%s", inputString);

    length = strlen(inputString); // This line is still correct

    // 2. Push all characters of the string onto the stack
    for (i = 0; i < length; i++) {
        push(inputString[i]);
    }

    // 3. Pop and Compare
    for (i = 0; i < length; i++) {
        char poppedChar = pop();
        if (inputString[i] != poppedChar) {
            isPalindrome = 0; 
            break;            
        }
    }

    // 4. Check the flag and print the result
    if (isPalindrome == 1) {
        printf("'%s' is a palindrome.\n", inputString);
    } else {
        printf("'%s' is NOT a palindrome.\n", inputString);
    }

    return 0;
}

/* // --- STACK FUNCTION DEFINITIONS (Must be included) ---
// (You must also include the full definitions for
//  push, pop, and isEmpty for this code to compile.)
*/

// Example push implementation
void push(char c) {
    if (top < MAX_SIZE - 1) {
        top++;
        stack[top] = c;
    }
}

// Example pop implementation
char pop() {
    if (top != -1) {
        return stack[top--];
    }
    return '\0'; // Return null char on underflow
}

// Example isEmpty implementation
int isEmpty() {
    return top == -1;
}