#include <stdio.h>
#include <stdbool.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
    } else {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1) {
        return '\0'; // empty
    } else {
        return stack[top--];
    }
}

bool isEmpty() {
    return top == -1;
}


bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}


bool isBalanced(char expression[]) {
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty()) {
                return false;
            }
            char topChar = pop();
            if (!isMatching(topChar, ch)) {
                return false;
            }
        }
    }
    return isEmpty(); 

int main() {
    char exp1[] = "{[()]}";
    char exp2[] = "{[(])}";

    if (isBalanced(exp1))
        printf("%s is Balanced\n", exp1);
    else
        printf("%s is Not Balanced\n", exp1);

    if (isBalanced(exp2))
        printf("%s is Balanced\n", exp2);
    else
        printf("%s is Not Balanced\n", exp2);

    return 0;
}
