/*
===================================================================================================================================
                  Subject: Data Structure          Lab Name: Data Structure Lab          Course Code: CSL301
                       Roll No: 28                  Name: Sachin Kumar Maheshwar Sahu       Practical No: 3
                                    Practical-Aim: Write a program for postfix evalautaion
===================================================================================================================================
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 50 // Defining "SIZE" constant with value 50

int stack[SIZE]; // Defining an array  with a size of constant "SIZE"
int top = -1;    // Defining a variable indicating position of stack

void push(int x); // Defining function push
int pop();        // Defining function pop

int main()
{

    int i, val, A, B, postfix;
    char ch, expression[SIZE];
    for (i = 0; i <= SIZE - 1; i++)
    {
        scanf("%c", &expression[i]);
        if (expression[i] == ')')
        {
            break;
        }
    }
    i = 0;

    do
    {
        ch = expression[i];
        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            A = pop();
            B = pop();
            switch (ch)
            {
            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;

            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;
            }

            push(val);
        }
        i++;
    } while (ch != ')');

    postfix = pop();
    printf("Value of Postfix Expression: %d", postfix);
}

//------------------------------------------------------FUNCTIONS--------------------------------------------------------------------
void push(int x)
{
    if (top >= SIZE)
    { // Until stack size limit reached
        puts("STACK OVERFLOW!!!");
    }
    else
        stack[++top] = x; // Function pushing stack to next place/element in stack
}

int pop()
{
    int poped;
    if (top == -1)
    {
        puts("STACK UNDERFLOW!!!");
    }
    else

        poped = stack[top--]; // Popping to previous place
    return poped;
}