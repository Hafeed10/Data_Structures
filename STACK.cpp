#include <stdio.h>
#include <string.h>
#define SIZE 20

int top = -1;
char stack[SIZE];

void push(char ch)
{
    if (top == (SIZE - 1))
    {
        printf("Stack is Overflow\n");
    }
    else
    {
        stack[++top] = ch;
    }
}

char pop()
{
    if (top == -1)
    {
        printf("Stack is Underflow\n");
        return '\0'; // Return null character if stack is empty
    }
    else
    {
        return stack[top--];
    }
}

int main()
{
    char str[SIZE];
    int i;
    printf("Enter the string (max %d characters): ", SIZE - 1);
    scanf("%19s", str); // Safely read input with a maximum limit
    // Push characters onto the stack
    for (i = 0; i < strlen(str); i++)
    {
        push(str[i]);
    }
    // Pop characters from the stack to reverse the string
    for (i = 0; i < strlen(str); i++)
    {
        str[i] = pop();
    }
    printf("Reversed string is: %s\n", str);
    return 0;
}