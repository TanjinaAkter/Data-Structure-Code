#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node
{
  int data;
  struct Node *next;
};

/* Given a reference (pointer to pointer) to the head of a list and
   an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));   /*  allocate node */
    new_node->data  = new_data;     /* put in the data  */
    new_node->next = (*head_ref);    /* Make next of new node as head */
    (*head_ref)    = new_node;       /* Make next of new node as head */
}
  void insertAfter(struct Node* prev_node, int new_data)     /* Given a node prev_node, insert a new node after the given
                                                            prev_node */
{
    if (prev_node == NULL)      /* check if the given prev_node is NULL */
    {
      printf("the given previous node cannot be NULL");
      return;
    }
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));     /* allocate new node */

    new_node->data  = new_data;           /* put in the data  */


    new_node->next = prev_node->next;     /* Make next of new node as next of prev_node */

    prev_node->next = new_node;           /* move the next of prev_node as new_node */
}

void append(struct Node** head_ref, int new_data)       /* Given a reference (pointer to pointer) to the head
                                                          of a list and an int, appends a new node at the end  */
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));    /* allocate node */
    struct Node *last = *head_ref;
    new_node->data  = new_data;        /* put in the data  */
    new_node->next = NULL;             /* This new node is going to be the last node, so make next of
                                         it as NULL*/
    if (*head_ref == NULL)             /* If the Linked List is empty, then make the new node as head */
    {
       *head_ref = new_node;
       return;
    }
    while (last->next != NULL)         /* Else traverse till the last node */
        last = last->next;


    last->next = new_node;             /* Change the next of last node */
    return;
}
    void printList(struct Node *node)   // This function prints contents of linked list starting from head
  {
    while (node != NULL)
  {
    printf(" %d ", node->data);
     node = node->next;
  }
}
int main()
{

  struct Node* head = NULL;     /* Start with the empty list */


  append(&head, 6);                // Insert 6.  So linked list becomes 6->NULL
  push(&head, 7);                 // Insert 7 at the beginning. So linked list becomes 7->6->NULL
  push(&head, 1);                // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
  append(&head, 4);              // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
  insertAfter(head->next, 8);    // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
  printf("\n Created Linked list is: ");
  printList(head);

  return 0;
}

