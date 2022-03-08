#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

int main()
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value for data:\n");
    int val;
    scanf("%d", &val);
    ptr->data = val;
    ptr->next = NULL;
    head = ptr;
    printf("%d ", head->data);
    printf("%p ", head->next);
    printf("%p ", head);

    return 0;
}