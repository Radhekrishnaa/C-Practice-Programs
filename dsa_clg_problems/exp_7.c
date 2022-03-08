/* 
==========================================================================================
   Subject= DS Lab     Practical No_4  Course code: CSL 301
   Roll NO- 21         Name- Radhekrishna Mishra
   Practical No :7
   AIM: Write a program that uses functions to perform the following operations on circular linked List
         (i)Creation (ii) Insertion (iii) Deletion (iv) Traversal.
==========================================================================================
*/

//===============***Program for performing the operation on circular linked list***========================


#include <stdio.h>
#include <stdlib.h>
 
//============= Structure of a linked list node=================
struct node {
    int data;  //for value storing
    struct node* next;
};
 
// Pointer to last node in the list
struct node* last = NULL;
 
//===============***FUNCTIONS***======================

void insertAtFront(); //Function for insertion at the beginning
void addatlast();  //Function for insertion at the end
void insertafter();  //Function for insertion at specific location
void deletefirst();  //Function for deletion of first node
void deletelast();  //Function for deletion of last node
void deleteAtIndex();  //Function for deletion of specific index node
void viewList(); //Function for displaying the node

//================***FUNCTION***=====================

//================***MAIN FUNCTION***=================
int main()
{
    int choice=0;
    do
    {
         printf("\n===============***MENU:***===============\n");
         printf("\t1.For insertion at front\n");
         printf("\t2.For insertion at the end\n");
         printf("\t3.For insertion at specific location\n");
         printf("\t4.For deletion of first node\n");
         printf("\t5.For deletion of node from last\n");
         printf("\t6.For deletion of specific item\n");
         printf("\t7.For displaying the nodes\n");
         printf("\t8.For exiting .\n");
         printf("\nEnter your choice : ");
         scanf("%d",&choice);
         switch (choice)
         {//for selection of choice for performing the function
         case 1:
                insertAtFront();
             break;
        case 2:
                addatlast();
                break;
        case 3:
                insertafter();
                break;
        case 4:
                deletefirst();
                break;
        case 5:
                deletelast();
                break;
        case 6:
                deleteAtIndex();
                break;
        case 7:
                viewList();
                break;

        case 8:
              exit(0);
              break;
         default:
         printf("\n\tError!! :plz enter proper option\n");
             break;
         }
    } while (choice!=8);
    

     

    
    
 
    return 0;
}

// Function to insert a node in the
// starting of the list
void insertAtFront()
{
    // Stores the number to be inserted
    int data;
 
    // Initialize a new node
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
 
    // Input data
    printf("\nEnter data to be "
           "inserted: \n");
    scanf("%d", &data);
 
    // If the new node is the only
    // node in the list
    if (last == NULL) {
        temp->data = data;
        temp->next = temp;
        last = temp;
    }
 
    // Else last node contains the
    // reference of the new node and
    // new node contains the reference
    // of the previous first node
    else {
        temp->data = data;
        temp->next = last->next;
 
        // last node now has reference
        // of the new node temp
        last->next = temp;
    }
}
void addatlast()
{
    // Stores number to be inserted
    int data;
 
    // Initialize a new node
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
 
    // Input data
    printf("\nEnter data to be "
           "inserted : \n");
    scanf("%d", &data);
 
    // If the new node is the
    // only node in the list
    if (last == NULL) {
        temp->data = data;
        temp->next = temp;
        last = temp;
    }
 
    // Else the new node will be the
    // last node and will contain
    // the reference of head node
    else {
        temp->data = data;
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

// Function to insert after any
// specified element
void insertafter()
{
    // Stores data and element after
    // which new node is to be inserted
    int data, value;
 
    // Initialize a new node
    struct node *temp, *n;
 
    // Input data
    printf("\nEnter number after which"
           " you want to enter number: \n");
    scanf("%d", &value);
    temp = last->next;
 
    do {
 
        // Element after which node is
        // to be inserted is found
        if (temp->data == value) {
            n = (struct node*)malloc(sizeof(struct node));
 
            // Input Data
            printf("\nEnter data to be"
                   " inserted : \n");
            scanf("%d", &data);
            n->data = data;
            n->next = temp->next;
            temp->next = n;
 
            // If temp is the last node
            // so now n will become the
            // last node
            if (temp == last)
                last = n;
            break;
        }
        else
            temp = temp->next;
    } while (temp != last->next);
}

// Function to delete the first
// element of the list
void deletefirst()
{
    struct node* temp;
 
    // If list is empty
    if (last == NULL)
        printf("\nList is empty.\n");
 
    // Else last node now contains
    // reference of the second node
    // in the list because the
    // list is circular
    else {
        temp = last->next;
        last->next = temp->next;
        free(temp);
    }
}

// Function to delete the last node
// in the list
void deletelast()
{
    struct node* temp;
 
    // If list is empty
    if (last == NULL)
        printf("\nList is empty.\n");
 
    temp = last->next;
 
    // Traverse the list till
    // the second last node
    while (temp->next != last)
        temp = temp->next;
 
    // Second last node now contains
    // the reference of the first
    // node in the list
    temp->next = last->next;
    last = temp;
}

// Function to delete an element
// at a specified index in the list
void deleteAtIndex()
{
    // Stores the index at which
    // the element is to be deleted
    int pos, i = 1;
    struct node *temp, *position;
    temp = last->next;
 
    // If list is empty
    if (last == NULL)
        printf("\nList is empty.\n");
 
    // Else
    else {
 
        // Input Data
        printf("\nEnter index : ");
        scanf("%d", &pos);
 
        // Traverse till the node to
        // be deleted is reached
        while (i <= pos - 1) {
            temp = temp->next;
            i++;
        }
 
        // After the loop ends, temp
        // points at a node just before
        // the node to be deleted
 
        // Reassigning links
        position = temp->next;
        temp->next = position->next;
 
        free(position);
    }
}
 
// Function to print the list
void viewList()
{
    // If list is empty
    if (last == NULL)
        printf("\nList is empty\n");
 
    // Else print the list
    else {
        struct node* temp;
        temp = last->next;
 
        // While first node is not
        // reached again, print,
        // since the list is circular
        do {
            printf("\nData = %d", temp->data);
            temp = temp->next;
        } while (temp != last->next);
    }
}