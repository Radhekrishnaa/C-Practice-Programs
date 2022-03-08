/* 
============================================================================
   Subject= DS Lab     Practical No_2   Course code: CSL 301
   Roll NO- 21         Name- Radhekrishna Mishra
   Practical No :8
   AIM: Write a menu driven program that impelement stack(its operations)
        usnig Linked list (using Dynamic Implementation)
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>

/* Structure to create a node with data and pointer */

struct Node 
{
    int data;
    struct Node *next;
}*top = NULL; // Initially the list is empty

//======================***FUNCTION DECLARATION***==========================
void push(int); //function for inserting the values and nodes
void pop();     //function for deletion of the values and nodes
void display(); //function for displaying the values of nodes

//======================***MAIN FUNCTION***=================================
int main()
{
    int choice, value;

    printf("\nIMPLEMENTING STACKS USING LINKED LISTS\n");

    while(1){

    printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("\nEnter the value to insert: ");
        scanf("%d", &value);
        push(value);
        break;

        case 2: pop();
        break;

        case 3: display();
        break;

        case 4: exit(0);
        break;

        default: printf("\nInvalid Choice\n");
}
   }  

}

    void push(int value)
    {
        struct Node *newNode;
        newNode = (struct Node*)malloc(sizeof(struct Node));  //creation of new node
        newNode->data = value; // get value for the node
        if(top == NULL)
        newNode->next = NULL;  
        else
        newNode->next = top; // Make the node as TOP
        top = newNode;
        printf("Node is Inserted\n\n");
    }

    void pop()
    {
        if(top == NULL)  //checking if the linked list is empty
        printf("\nSTACK UNDERFLOW:EMPTY STACK\n");
        else{
        struct Node *temp = top;
        printf("\nPopped Element : %d", temp->data);  //deleting the top element
        printf("\n");
        top = temp->next; // After popping, make the next node as TOP
        free(temp);    //from using the free function releasing the memory heap
        }
    }

    void display()
    {
        // Print the stack
        if(top == NULL)
        printf("\nSTACK UNDERFLOW:EMPTY STACK\n");
        else
        {
        printf("The stack is \n");
        struct Node *temp = top;
        while(temp->next != NULL){
        printf("%d--->",temp->data); 
        temp = temp -> next;
       }
        printf("%d--->NULL\n\n",temp->data); 
    }  
}