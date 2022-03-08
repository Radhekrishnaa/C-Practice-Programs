/* 
============================================================================
   Subject= DS Lab     Practical No_4  Course code: CSL 301
   Roll NO- 21         Name- Radhekrishna Mishra
   Practical No :4
   AIM: Write a program that implement queue(its operations) using Arrays
============================================================================
*/

#include <stdio.h>

#define SIZE 50            //Defining SIZE of constant 50
int queue[SIZE];           //Declaring a variable named queue with size 50
int front = -1, rear = -1; //Defining front and rear section of queue

void EnQueue(); //Defining function Enqueue
void DeQueue(); //Defining function Dequeue
void Display(); //Defining function Display

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
            EnQueue(element); //Calling function for insertion of element
            break;
        case 2:
            DeQueue(); //Calling function for deleltion of element
            break;
        case 3:
            Display(); //Calling function for displaying the elements of queue
            break;
        }
    } while (choice != 4); //It will iterate itself in loop till the choice is 4

    return 0;
}

//=========================*FUNCTION*===============================

void EnQueue(int value)
{
    if (rear == SIZE - 1) //Checking whether the queue is full or not
        printf("Queue is full : Insertion is not allowed\n");
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = value; //For inserting value in queue we have to insert it
    }
    else
    {
        rear++;
        queue[rear] = value; //As we are inserting the elements from rear we increment it by 1
    }
    printf("%d item is inserted in queue\n", value);
}

void DeQueue()
{
    int deleted_elem;
    if (front == -1 && rear == -1 || front > rear)
    {
        //Checking whether the queue is empty or not
        printf("Queue is Empty: Deletion is not possible\n");
    }
    else if (front == rear)
    {
        //If both front and rear are pointing at same place then delete elemet
        //After intialize both them as -1
        deleted_elem = queue[front];
        front = rear = -1;
    }
    else
    {
        deleted_elem = queue[front]; //In Dequeue function deletion is done from front end
        front++;                     //After every deletion of element the front is incremented

        printf("Item deleted : %d\n", deleted_elem);
    }
}

void Display()
{
    int i;
    if (front == -1 && rear == -1) //CHecking whether the queue is empty or not
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("\nThe elements in queue are:\n ");
        for (i = front; i <= rear; i++)
        { //Displaying the element starting from front till the rear end
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}