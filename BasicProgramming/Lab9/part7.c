#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_NODES 3
typedef struct node
{
    float weight;
    float height;
    struct node *next;
} node;
void getInformation(node *head);
void printInformation(node *head);
node *CreateNode()
{
    node *the_node;
    // Allocating memory
    the_node = (node *)malloc(sizeof(node));
    the_node->next = NULL;
    return the_node;
}
int main()
{
    node *head;
    head = CreateNode();
    getInformation(head);
    printInformation(head);
    free(head);
    return 0;
}
void getInformation(node *head){
    node *temp;
    temp = head;
    for (int i = 0; i < NUM_OF_NODES; i++)
    {
        temp->next = CreateNode();
        temp = temp->next;
        printf("Please enter weight for participant %d: \n", i + 1);
        scanf("%f", &temp->weight);
        printf("Please enter height for participant %d: \n", i + 1);
        scanf("%f", &temp->height);
    }
}
void printInformation(node *head){
    node *temp;
    temp = head;
    for (int i = 0; i < NUM_OF_NODES; i++)
    {
        temp = temp->next;
        printf("participant % d’s information :\n", i + 1);
        printf("weight : % f\n", temp->weight);
        printf("height : % f\n", temp->height);
    }
}