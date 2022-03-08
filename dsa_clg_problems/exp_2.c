/* 
============================================================================
   Subject= DS Lab     Practical No_2   Course code: CSL 301
   Roll NO- 21         Name- Radhekrishna Mishra
   Practical No :2 
   AIM: Write a program to convert infix to postfix expression.
============================================================================
*/

#include<stdio.h>
#include<ctype.h> 
#include<stdlib.h>
#include<string.h>
/*We have included the ctype.h header file bcuz it will give us access to use the
isalnum function , basically what it does is to give a non zero value as output 
if the character is a alphabet or a numberical.
And so it will help us to differentiate btw character ,symbols & operators*/

#define SIZE 50

char stack[SIZE]; //A stack of fixed size 50 is declared to characters
int top = -1;  //The variable top indicates the position of stack

void push(char x){ //Function for PUSH operation or for storing/insertion elements in the stack
    if(top>=SIZE-1){
        printf("\n \tStack Overflow.");
    }
    else{
        top=top+1;
        stack[top]=x;
    }
    
}

char pop(){  //Function for POP operation basically it pops the element
    
    char poped;
    if(top<0){
        
        printf("\n \tStack underflow: invalid infix expression");
    		/* underflow may occur for invalid expression */
		/* where ( and ) are not matched */
    
    }
    else{
        poped=stack[top];
        top=top-1;
        return (poped);
    }

}
/* define function that is used to determine whether any symbol is operator or not
(that is symbol is operand)
* this fucntion returns 1 if symbol is opreator else return 0 */

int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}
/* define fucntion that is used to assign precendence to operator.
* Here ^ denotes exponent operator.
* In this fucntion we assume that higher integer value
* means higher precendence */

int precedence(char symbol){

    if(symbol == '^'){ //exponent operator ,highest precedence
        return (3);
    }
    
    else if (symbol =='*'||symbol =='/'){
        return (2);
    }
    
    else if (symbol == '+'|| symbol == '-'){ //lowest precedence
        return (1);
    }

    else{
        return (0);

    }
}


int main(){
    char infix[SIZE],postfix[SIZE];
    char item,element;
    int i=0,k=0,pr;
    printf("Enter an infix expression \n");
    gets(infix);
    push('(');  /* push '(' onto stack */
    strcat(infix,")");  /* add ')' to infix expression */

    item=infix[i];
    while((item != '\0')){  //Here the variable ch is storing every character infix till the strings finishes.
 //run loop till the end of infix expression
            if(item == '('){
                push(item);
            }

            else if( isalnum(item))
		    {
			    postfix[k] = item;              /* add operand symbol to postfix expr */
                k++;
               
		    }

            else if(is_operator(item)==1){  //means to check wheteher symbol is operator
              element=pop();
                while(is_operator(element) == 1 && precedence(element)>= precedence(item)){
				 postfix[k] = element;                  /* so pop all higher precendence operator and */
				 k++;
				element = pop();                       /* add them to postfix expresion */
			}
			push(element);
            /*because just above while loop will terminate we have opped one extra line
            for whick condition fails and loops terminates , so for that one */
             
             push(item);  //push current operator/symbol onto stack
                
                
            }
             else if (item == ')'){ /*if current symbol is ')' then pop*/
                 
                 element=pop();  //pop and keep popping until '(' encountered
                while( element != '('){
                    postfix[k]=element;
                    k++;
                    element = pop();
                }
            }
            else{ /* if current symbol is neither operand not '(' nor ')' and nor
			operator */
			printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
			getchar();
			exit(1);
		    }
            i++;

            item=infix[i];
          
           
    } 
    if(top>0){
        printf("\nInvalid infix expression");
        exit(1);
    }
  
    postfix[k]='\0';
    int a=0;
    printf("\nPostfix Expression :");
    while(postfix[a]!='\0'){  //prints postfix expression
        printf("%c",postfix[a]);
        a++;
    }
   

    
    return 0 ;
}