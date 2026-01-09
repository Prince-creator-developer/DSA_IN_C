#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int op1,op2,res,s[100],top=-1,i;
char postfix[100],symbol;
void push(int item){
    if (top >= 100) {
        printf("Error: Stack Overflow!\n");
        exit(1);
    }
    top++;
    s[top]=item;
}
int pop(){
    if (top == -1) {
        printf("Error: Stack Underflow (Invalid Expression)!\n");
        exit(1);
    }
    int item;
    item=s[top];
    top--;
    return item;
}
int main(){
    
    printf("Enter the expression for the postfix:\n");
    scanf("%s",&postfix);
    for(i=0;postfix[i]!='\0';i++){
        symbol=postfix[i];
        if(isdigit(symbol)){
            push(symbol-'0');
            
        }else{
            op2=pop();
            op1=pop();
            
            switch(symbol){
                case '+':push(op1+op2); break;
                case '-':push(op1-op2); break;
                case '*':push(op1*op2); break;
                case '/':push(op1/op2); break;
                case '^':
                case '$':push((int)pow(op1,op2)); break;
                default:
                printf("Enter the correct expression.\n");
                exit(0);
            }
        }
    }
    if (top > 0) {
        // This handles cases like "23+23+"
        printf("Error: Invalid Expression (Too many operands)!\n");
        return 1; // Exit with an error
    } else if (top < 0) {
        // This handles an empty string or other errors
        printf("Error: Invalid Expression (Stack is empty)!\n");
        return 1;
    }
    res=pop();
    printf("The result of the postfix expression is %d\n",res);
    return 0;
}