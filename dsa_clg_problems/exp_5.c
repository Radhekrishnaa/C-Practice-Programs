/* 
==========================================================================================
   Subject= DS Lab     Practical No_4  Course code: CSL 301
   Roll NO- 21         Name- Radhekrishna Mishra
   Practical No :4
   AIM: Write a program that implement Circular Queue(it's operation) using Arrays
==========================================================================================
*/
#include <stdio.h>

#define SIZE 5   //Defining SIZE of constant 100
int queue[SIZE]; //Array declaration for storing value
int front = -1;  //Pointer for pointing the head and for getting the front element
int rear = -1;   //Pointer for pointing the end and for deleting the rear element

//======================***FUNCTIONS***===========================
//Function declaration part for following functions to be performed

void enQueue(); //Function for inserting the element
void deQueue(); //Function for deleting the element
void display(); //Function for displaying the element

//=================================================================

int main()
{
    int choice, element;
    do
    {
        printf("\n===============***MENU:***===============\n");
        printf("\t1.EnQueue=for entering values in queue\n");
        printf("\t2.DeQueue-for deleting values from queue\n");
        printf("\t3.Display-displaying values in the queue\n");
        printf("\t4.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element you want to insert:");
            scanf("%d", &element);
            enQueue(element); //Calling function for insertion of element
            break;
        case 2:
            deQueue(); //Calling function for deleltion of element
            break;
        case 3:
            display(); //Calling function for displaying the elements of queue
            break;
        }
    } while (choice != 4); //It will iterate itself in loop till the choice is 4

    return 0;
}

//=======================***FUNCTION***===========================

void enQueue(int value)
{

    if (front == 0 && rear == SIZE - 1 || (front == rear + 1)) // condition to check queue is full
    {
        printf("Queue is overflow : Insertion is not allowed\n");
        return;
    }
    if (front == -1) // condition to check queue is empty
    {
        front = 0; //Initializing the front
        rear = 0;
        //Assigning the value into queue
    }
    else
    {
        if (rear == SIZE - 1)
        {
            rear = 0;
        }
        else
            rear = rear + 1;
    }
    queue[rear] = value;
}

void deQueue()
{
    int deleted_elem;
    if (front == -1)
    { //Condition to check if it is empty or not
        printf("Queue is empty : NO deletion is possible\n");
        return;
    }
    printf("Element deleted from queue is : %d ", queue[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == SIZE - 1)
            front = 0;
        else
            front = front + 1;
    }
}

void display()
{
    int i = front, r = rear;
    if (front == -1) //checking if it is empty
    {
        printf("\n Queue is empty..");
        return;
    }
    printf("Queue elements are :\n");
    if (i <= r)
    //running it till null
    {

        while (i <= r)
        {
            printf("%d\n ", queue[i]);
            i++;
        }
    }
    else
    {
        while (i <= SIZE - 1)
        {
            printf("%d\n ", queue[i]);
            i++;
        }
        i = 0;
        while (i <= r)
        {
            printf("%d \n", queue[i]);
            i++;
        }
    }
}
