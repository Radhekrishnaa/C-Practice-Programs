#include <stdio.h>
#include <stdlib.h>
 
// Structure of a linked list node
struct node {
    int info;
    struct node* next;
};
 
// Pointer to last node in the list
struct node* last = NULL;
 
// Function to add a new node at the
// end of the list
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
        temp->info = data;
        temp->next = temp;
        last = temp;
    }
 
    // Else the new node will be the
    // last node and will contain
    // the reference of head node
    else {
        temp->info = data;
        temp->next = last->next;
        last->next = temp;
        last = temp;
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
        do {
            printf("\nData = %d",
                   temp->info);
            temp = temp->next;
        } while (temp != last->next);
    }
}
 
// Driver Code
int main()
{
    // Function Call
    addatlast();
    addatlast();
    addatlast();
 
    // Print list
    viewList();
 
    return 0;
}
 