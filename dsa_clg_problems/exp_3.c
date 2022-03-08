/* 
============================================================================
   Subject= DS Lab     Practical No_2   Course code: CSL 301
   Roll NO- 21         Name- Radhekrishna Mishra
   Practical No :3 
   AIM: Write a program for  postfix evalautaion
============================================================================
*/
#include <stdio.h>
#include <ctype.h>
/*We have included the ctype.h header file bcuz it will give us access to use the
isdigit function , basically what it does is to give a non zero value as output 
if the character is a numberical ,so it helps in identifying whether the entered
element in the expression is a number or not*/

#define SIZE 100
#define POSTFIX 100
int top = -1;    //The variable top indicates the postition of index of stack
int stack[SIZE]; //A stack is declared with size of maximum 100

//--------------------------------------------FUNCTIONS------------------------------------------------

void push(int item)
{ //Function for PUSH operation or for storing/insertion elements in the stack
    if (top >= SIZE)
    {
        printf("Stack Overflow!\n");
        return;
    }
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}

int pop()
{ //Function for POP operation basically it pops the element
    int poped;
    if (top == -1)
    {
        printf("Stack Underflow!\n");
        return 0;
    }
    else
    {
        poped = stack[top];
        top = top - 1;
        return poped;
    }
}

void Evaluate_postfix(char postfix[])
{
    char ch;
    int i;
    int operand_1, operand_2;
    //This two variables are going to store the two elements are poped after encounter of operator
    int result; //This variable is for storing the result of above operands

    for (i = 0; postfix[i] != ')'; i++)
    {
        char ch = postfix[i];
        if (isdigit(ch)) //For checking if a character is a digit
        {
            push(ch - '0');
        }
        if (isalpha(ch)) //For checking if a character is alpha ,if it is print error
        {
            printf("\t ERROR! :You have entered a alphabet\n");
        }
        else if (ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-')
        {
            operand_1 = pop();
            operand_2 = pop();
            /*This two operand variable's are for storing the two elements poped after the encounter of one operator*/
            switch (ch)
            {
                //for performing function on the basis of entered operators
            case '^':
                result = operand_2 ^ operand_1;
                break;
            case '*':
                result = operand_2 * operand_1;
                break;
            case '/':
                result = operand_2 / operand_1;
                break;
            case '%':
                result = operand_2 % operand_1;
            case '+':
                result = operand_2 + operand_1;
                break;
            case '-':
                result = operand_2 - operand_1;
                break;
            }
            push(result); //pushing the above obtained value in stack
        }
    }
    printf("\nResult of the postfix expression evaluation is : %d\n", pop());
    //printing the result of postfix expression after doing evaluation
}

//-------------------------------MAIN FUNCTION-------------------------------------

int main()
{
    int i;
    char postfix_exp[POSTFIX]; //Variable postfix for taking input of postfix expression
    printf("\nAssumption :There are only six operators (^,*,/,%,+,-)\n");
    printf("\tIN an expression a operand is a single digit\n");
    printf("\tEnter the postfix expression :\n");
    printf("\t Compulsory :Press right parenthesis ')',for end of expression \n");
    for (i = 0; i <= POSTFIX - 1; i++)
    {
        scanf("%c", &postfix_exp[i]); //Taking input of postfix expression
        if (postfix_exp[i] == ')')    //Condition to check the end of entered expression
        {
            break;
        }
    }
    Evaluate_postfix(postfix_exp); //calling to evaluate_postfix expression to evaluate postfix_exp

    return 0;
}
