/* 
==========================================================================================
   Subject= DS Lab     Practical No_4  Course code: CSL 301
   Roll NO- 21         Name- Radhekrishna Mishra
   Practical No :05
   AIM:Write a program that uses functions to perform the following operations on Singly Linked List
         (i)Creation (ii) Insertion (iii) Deletion (iv) Traversal.
==========================================================================================
*/
#include <stdio.h>
#include <stdlib.h>

//===========================STRUCTURE OF NODE====================
struct node //structure for storing the data
{
    int data;          //data for storing
    struct node *next; //for storing the address
};
struct node *head;

//==========================***FUNCTIONS***=============================
void insert_begin();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

//======================***MAIN FUNCTION***==============================
void main()
{
    int choice = 0;
    while (choice != 9)
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n 5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9.Exit\n ");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        { //for selection of choice for performing the function
        case 1:
            insert_begin();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            randominsert();
            break;
        case 4:
            begin_delete();
            break;
        case 5:
            last_delete();
            break;
        case 6:
            random_delete();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}

//======================FUNCTION================================

//======FUNCTION - for insertion at beginning

void insert_begin()
{
    struct node *ptr; // creating the pointer for storing the and adding value
    int item;
    ptr = (struct node *)malloc(sizeof(struct node *)); //for dynamically allocating the memory
    if (ptr == NULL)                                    //for checking if it is full or not
    {
        printf("\nOVERFLOW: insertion not allowed");
    }
    else
    {
        printf("\nEnter value\n");
        scanf("%d", &item);
        ptr->data = item; // for storing the data
        ptr->next = head; // for storing the address of next element
        head = ptr;
        printf("\nNode inserted!!");
    }
}
//FUNCTION - for insertion at the end

void lastinsert()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node)); //for dynamically allocating the memory
    if (ptr == NULL)                                  //for checking if it is full or not
    {
        printf("\nOVERFLOW: insertion is not allowed");
    }
    else
    {
        printf("\nEnter value?\n");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL) // for checking and running till the last element
        {
            ptr->next = NULL;
            head = ptr;
            printf("\nNode inserted!!");
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("\nNode inserted!!");
        }
    }
}
//FUNCTION- for insertion at user defined location

void randominsert()
{
    int i, loc, item;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) //for checking if it is full
    {
        printf("\nOVERFLOW: insertion is not allowed");
    }
    else
    {
        printf("\nEnter element value");
        scanf("%d", &item);
        ptr->data = item;                                               //for adding the element
        printf("\nEnter the location after which you want to insert "); //for asking the location of specified node
        scanf("\n%d", &loc);
        temp = head;
        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\ncan't insert\n");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("\nNode inserted!!");
    }
}
///FUNCTION - for deletion from the beginning

void begin_delete()
{
    struct node *ptr;
    if (head == NULL) //for checking if it's empty
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr); //deleting the element
        printf("\nNode deleted from the begining ...\n");
    }
}
//FUNCTION - for deletion from the end

void last_delete()
{
    struct node *ptr, *ptr1;
    if (head == NULL) //for checking if it's empty
    {
        printf("\nlist is empty");
    }
    else if (head->next == NULL) //moving till the last node
    {
        head = NULL;
        free(head); //deleting the element
        printf("\nOnly node of the list deleted ...\n");
    }

    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr); //deleting the element
        printf("\nDeleted Node from the last ...\n");
    }
}
//FUNCTION- for deletion at user defined location

void random_delete()
{
    struct node *ptr, *ptr1;
    int loc, i;
    printf("\n Enter the location of the node after which you want to perform deletion \n");
    scanf("%d", &loc);
    ptr = head;
    for (i = 0; i < loc; i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;

        if (ptr == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    ptr1->next = ptr->next;
    free(ptr); //deleting the element
    printf("\nDeleted node %d ", loc + 1);
}
//FUNCTION -for searching if the node is there

void search()
{
    struct node *ptr;
    int item, i = 0, flag;
    ptr = head;
    if (ptr == NULL) //checking the if the linked list is empty
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search?\n");
        scanf("%d", &item);
        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                printf("item found at location %d ", i + 1);
                flag = 0;
            }
            else
            {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            printf("Item not found\n");
        }
    }
}
//FUNCTION - for displaying
void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("\nprinting values . . . . .\n");
        while (ptr != NULL)
        {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
    }
}