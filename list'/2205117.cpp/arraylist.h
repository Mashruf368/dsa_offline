#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int * array;
    // Add more fields here
    int capacity;
    int size;
    int cur_pos;
    
} ArrayList;


void init_arraylist(ArrayList *list, int capacity)              //done
{
    printf("Memory allocated of memory %d\n",capacity);
    // dynamically allocate space for the array
    list->array=(int *)malloc(capacity*(sizeof(int)));
    list->capacity=capacity;
    list->cur_pos=0;
    list->size=0;
    // initialize the size, capacity, and current position
}


void clear(ArrayList *list)                                         //done
{
    printf("Array cleared\n");
    // clear the list but do not free the array
    list->size=0;
    list->cur_pos=0;
    list->capacity=1;
    // modify the size, capacity, and current position
    
}

int get_size(ArrayList *list)                                       //done
{
    printf("Getting size of array : %d\n",list->size);
    return list->size;
    return -1;
}


void resize(ArrayList *list, int new_capacity)                  //done
{
    printf("Array resized to new capacity %d\n",new_capacity);
    // allocate space for new array with new_capacity
    // print log message

    int *new_arr=(int *)realloc(list->array,new_capacity*(sizeof(int)));

    list->array=new_arr;

    printf("the array is resized\n");
}


void append(ArrayList *list, int value)                             //done
{
    printf("Appended %d\n",value);
    // call resize if necessary
    
    // printf("size %d\n",list->size);
    // printf("size %d\n",list->capacity);
    if( list->size < list->capacity )
    {
        list->array[list->size]=value;
        //list->size++;
        //list->cur_pos++;
        
    }
    else 
    {
        list->capacity=list->capacity*2;
        int *new_arr=(int *)realloc(list->array,list->capacity*sizeof(int));
        printf("List capacity has been increased from %d to %d\n",list->capacity,list->capacity*2);

        list->array=new_arr;
        list->array[ list->size]=value;
        //list->size++;
        //list->cur_pos++;
    }
    list->size++;
    // add value to the end of the list

}


void insert(ArrayList *list, int value)                             //done
{
    printf("Inserted %d\n",value);
    // call resize if necessary
    if(list->size >= list->capacity)
    {
        list->capacity = list->capacity*2;
        int *new_arr=(int *)realloc(list->array,list->capacity*sizeof(int));
        list->array=new_arr;
        //printf("List capacity has been increased from %d to %d\n",list->capacity,list->capacity*2);

        
    }

    // shift the elements to the right to make space
    for(int i=list->size; i > list->cur_pos ; i--)
    {
        list->array[i] = list->array[i-1];
    } 

    // add value at the current position
    list->array[list->cur_pos]=value;
    list->size++;
    //printf("size %d\n",list->size);
    // printf("size %d\n",list->capacity);
}


int remove_at_current(ArrayList *list)                              //done
{
    printf("Removing from current position %d\n",list->cur_pos);
    //return -1;

    int ans=list->array[list->cur_pos];

    for(int i=list->cur_pos;i<list->size-1;i++) 
        list->array[i]=list->array[i+1];

    list->size--;
    if(list->size < list->capacity/4) 
    {
        list->capacity=list->capacity/2;
        int *new_arr=(int *)realloc(list->array,list->capacity*(sizeof(int)));
        list->array=new_arr;

        printf("List capacity has been reduced from %d to %d\n",list->capacity*2,list->capacity);
    }
    // printf("size %d\n",list->size);
    // printf("size %d\n",list->capacity);
    return ans;

    // save the value of the current element in a variable
    // shift the elements to the left to fill the gap
    // change the size, and current position as necessary
    // call resize if necessary
    // return the saved value
}

int find(ArrayList *list, int value)                                //done
{
    //printf("Implement find\n");
    //return -1;

    for(int i=0;i<list->size;i++)  
    {
        if(list->array[i]==value){
        printf("%d found in the list at position %d\n",value,i);
        return i;
        }
    }
    // traverse the list and return the position of the value
    
    printf("Element not found\n");
    return -1;
    // return -1 if the value is not found
}


void move_to_start(ArrayList *list)                             //doneee
{
    printf("Moved to start\n");


    list->cur_pos=0;
    if(list->size == 0) printf("list is empty\n");
    // consider the cases when the list is empty
}


void move_to_end(ArrayList *list)                               //done
{
    printf("Moved to end\n");

    if(list->size==0) printf("list is empty\n");
    list->cur_pos=list->size-1;
    
    // consider the cases when the list is empty
}


void prev(ArrayList *list)                                      //done
{
    if(list->cur_pos==0) printf("Operation not possible\n");
    else{
    
        printf("Moved to previous position %d\n",list->cur_pos-1);

        if(list->cur_pos>0) list->cur_pos--;
    }
    // no change if the current position is at the start
}


void next(ArrayList *list)                                  //done
{
    
    if(list->cur_pos==list->size-1) printf("Operation not possible\n");
    else{
        printf("Moved to next position %d\n",list->cur_pos+1);

        if( list->cur_pos < list->size-1 ) list->cur_pos++;
    }
    // no change if the current position is at the end
}


void move_to_position(ArrayList *list, int position)            //donee
{
    printf("Moved to position %d\n",position);

    list->cur_pos=position;
    
}


int get_current_position(ArrayList *list)               //done
{
    printf("Getting current position %d\n",list->cur_pos);


    return list->cur_pos;
    return -1;
}


int get_current_element(ArrayList *list)            //donee
{
    printf("Getting current element : %d\n",list->array[list->cur_pos]);

    return list->array[list->cur_pos];
    return -1;
}


void print_list(ArrayList *list)
{
    printf("Printing List\n< ");

    

    for(int i=0;i<list->size;i++) 
    {
        
        if(i==list->cur_pos) printf("|");

        printf("%d ",list->array[i]);

    }
    if(list->cur_pos==list->size) printf("|");
    printf(">\n");
}


void free_list(ArrayList *list)
{
    printf("list freed \n");
    // free the array before terminating the program
    free(list->array);
}


