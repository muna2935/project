#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

// Push a string onto the stack
void push(char str[]) {
    strcpy(stack[++top], str);
}

// Pop a string from the stack
char* pop() {
    return stack[top--];
}

int main() {
    char postfix[MAX];
    char op1[MAX], op2[MAX], temp[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        // If operand, push it onto stack
        if (isalnum(ch)) {
            char operand[2];
            operand[0] = ch;
            operand[1] = '\0';
            push(operand);
        }
        // If operator
        else {
            strcpy(op1, pop());
            strcpy(op2, pop());

            sprintf(temp, "(%s%c%s)", op2, ch, op1);
            push(temp);
        }
    }

    printf("Infix Expression: %s\n", pop());

    return 0;
}