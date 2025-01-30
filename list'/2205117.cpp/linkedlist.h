#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    // add *next and *prev here

    struct Node *prev;
    struct Node *next;
} Node;


typedef struct
{
    // add Node* head, tail, current_position and other necessary fields here
    Node *head;
    Node *tail;
    Node *current;
    int cur_pos;
    int size;
    
} LinkedList;


void init_linkedlist(LinkedList *list)              //done
{
    printf("implement init_linkedlist\n");
    // initialize head, tail with null
    list->head=NULL;
    list->tail=NULL;
    list->current=NULL;
    list->size=0;
}


void clear(LinkedList *list)                //done
{
    printf("Implement clear\n");
    // traverse the list and free each node
    Node *temp;
    list->size=0;
    
    while(list->head!=NULL)
    {
        temp=list->head;
        list->head=list->head->next;
        free(temp);
        
    }
    // set head and tail to null
    list->head=NULL;
    list->tail=NULL;
    list->current=NULL;
}


int get_size(LinkedList *list)              //done
{
    printf("The list size is %d\n",list->size);
    return list->size;
    return -1;
}


void append(LinkedList *list, int value)            //done
{
    printf("Appended %d\n",value);
    // create a new node and set its value
    list->size++;
    //printf("size %d\n",list->size);
    if(list->head==NULL){
        Node *temp=(Node *)malloc(sizeof(Node));
        temp->data=value;
        temp->next=NULL; 
        temp->prev=NULL;       
        list->head=temp;
        list->current=temp;
        list->tail=temp;
        //list->size++;
        list->cur_pos=0;

    }
    
    else {
        Node *temp=(Node *)malloc(sizeof(Node));
        temp->data=value;
        temp->prev=list->tail;
        temp->next=NULL;
        list->tail->next=temp;
        list->tail=temp;
        //list->size++;
        
    }

    // consider the case when the list is empty and when it isnt
}


void insert(LinkedList *list, int value)        //done
{
    printf("Inserted %d\n",value);
    // create a new node and set its value
    list->size++;
    //printf("size %d\n",list->size);
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->data=value;
    temp->next=NULL;
    temp->prev=NULL;
    
    if(list->head==NULL)
    {
        Node *temp=(Node *)malloc(sizeof(Node));
        temp->data=value;
        temp->prev=NULL;
        temp->next=NULL;
        list->head=temp;
        list->current=temp;
        list->tail=temp;
        //list->size++;
        list->cur_pos=0;
    }
    

    else if(list->current==list->head)         
    {
        list->head->prev=temp;
        temp->next=list->head;
        //list->size++;
        list->head=temp;
        list->current=temp;
    }
    // place it at the current position (check order of operations)
    else 
    {
        list->current->prev->next=temp;
        temp->prev=list->current->prev;
        temp->next=list->current;
        list->current->prev=temp;
        //list->size++;

    }
    // consider the case when the list is empty and when it isnt
}


int remove_at_current(LinkedList *list)         //done
{
    printf("Removed %d\n",list->current->data);
    list->size--;
    // consider the case when current code is at the begining or at the end
    if(list->cur_pos==0) 
    {
        Node *temp=list->head;
        list->head=list->head->next;
        list->current=list->head;
        free(temp);
        //list->size--;
    }

    else if(list->current!=list->tail)
    {
        Node *temp=list->current;
        list->current->prev->next=list->current->next;
        list->current->next->prev=list->current->prev;
        //list->size--;
        list->current=list->current->next;
        free(temp);
    }
    else 
    {
        Node *temp=list->tail;
        list->current=list->current->prev;
        list->tail=list->tail->prev;
        list->tail->next=NULL;
        free(temp);
        //list->size--;


    }
    return -1;
}


int find(LinkedList *list, int value)       //done
{
    //printf("Implement find\n");
    // traverse the list and return the position of the value
    int i=0;
    Node *temp=(Node *)malloc(sizeof(Node));
    temp=list->head;
    while(temp!=NULL) 
    {
        if(temp->data==value)            
        {
            printf("found %d at %d\n",value,i);
            return i;
        }
        else {temp=temp->next;i++;}
    }
    printf("did not find %d in the list\n",value);
    return -1;
}


void move_to_start(LinkedList *list)            //done
{
    
    //if(list->cur_pos==0) printf("Already at start\n");
    
        printf("Moved to start\n");

        list->current=list->head;
        
        list->cur_pos=0;
    
}


void move_to_end(LinkedList *list)          //done
{
    
    //if(list->cur_pos==list->size) printf("Already at end\n");
    
        printf("Moved to end\n");
        list->current=list->tail;
        list->cur_pos=list->size-1;
    
    
}


void prev(LinkedList *list)         //done
{
    if(list->cur_pos==0) printf("Already at start\n");
    else {
        printf("Moved to previous node\n");
        list->current=list->current->prev;
        list->cur_pos--;
    }
}


void next(LinkedList *list)         //done
{
    if(list->cur_pos==list->size-1) printf("Already at end\n");
    else {
        printf("Moved to next node\n");
        list->current=list->current->next;
        list->cur_pos++;
    }
}


void move_to_position(LinkedList *list, int position)       //done
{
    printf("moved current position from %d to %d\n",list->cur_pos,position);
    // traverse the list and stop at the given position

    list->current=list->head;
    int i=0;
    while(i<position)
    {
        list->current=list->current->next;
        i++;
    }
    list->cur_pos=position;

}


int get_current_position(LinkedList *list)          //done
{
    //printf("Implement get_current_position\n");
    // traverse the list and stop when you are at the current position

    Node *temp=list->head;
    int i=0;
    while(temp!=list->current)
    {
        temp=temp->next;
        i++;
    }
    printf("the position is %d\n",list->cur_pos);
    return i;
    free(temp);
    // return the position (integer)
    return -1;
}


int get_current_element(LinkedList *list)       //done
{
    //printf("Implement get_current_element\n");
    // return the value at the current position
    printf("The current element is %d\n",list->current->data);
    return list->current->data;
    return -1;
}


void print_list(LinkedList *list)           //done
{
    printf("Printing List\n< ");

    int i=0;
    Node *temp=(Node *)malloc(sizeof(Node));
    
    temp=list->head;
    while(temp!=NULL) 
    {
        if(i==list->cur_pos) printf("|");
        printf("%d ",temp->data);
        i++;
        temp=temp->next;
    }
    if(list->cur_pos==list->size) printf("|");
    printf(">\n");
    free(temp);
}


void free_list(LinkedList *list)        //done
{
    printf("Implement free_list\n");
    // free each node in the list
    
    
    Node *temp;
    while(list->head!=NULL)
    {
        temp=list->head;
        list->head=list->head->next;
        free(temp);
        

       
        
    }
    free(list->tail);
    free(list->current);
    list->size=0;
    list->cur_pos=0;
}
