#include <iostream>
using namespace std;

class Stack
{
private:
    int *array;

    int index;
    int capacity;
    //write your code here. Add additional private variables if necessary

public:
    // Constructor
    Stack()
    {
        array = new int[1]; 
        //write your code here. Initialize additional private variables if necessary
        index=-1;
        capacity=1;
    }
    Stack(int initialCapacity)
    {
        array = new int[initialCapacity]; // Allocate initial memory
        //write your code here. Initialize additional private variables if necessary
        index=-1;
        capacity=initialCapacity;
    }

    // Destructor
    ~Stack()
    {
        delete[] array; // Free dynamically allocated memory
    }

    // Helper function to resize the array when full
    void resize(int newCapacity)
    {
        int *newArray = new int[newCapacity]; // Allocate new array
        
        //write your code here. Copy the elements from the old array to the new array
        for(int i=0;i<=index;i++) newArray[i]=array[i];

        delete[] array; // Free old memory

        array=newArray;
        capacity=newCapacity;
        
        //write your code here. Update the capacity and array pointers
    }

    // Push an element onto the stack
    void push(int x)
    {
        if((index+1) >= capacity) 
        {
            // capacity=capacity*2;
            // int  *temp=(int *)realloc(array,capacity);
            // array=temp;
            resize(capacity*2);

        }

        //write your code here. Check if the array is full and resize if necessary.
        array[++index]=x;
        //push the element onto the stack
    }

    // Remove and return the top element
    int pop()
    {
       if(index<0) {cout<<"stack is empty\n";return -1;}
       //write your code here. Check if the stack is empty and return -1 if it is.
       int a=array[index--];
       //pop the top element and return it
       if(index < capacity/4) 
       {
            // capacity=capacity/2;
            // int *temp=(int *)realloc(array,capacity);
            // array=temp;
            resize(capacity/2);
       }
       return a;
       
       //resize the array if necessary
    }

    // Return the top element without removing it
    int top()
    {
        if(index<0) {cout<<"stack is empty\n";return -1;}
        //write your code here. Check if the stack is empty and return -1 if it is.
        else 
        {
            return array[index];
        }
        //return the top element
    }

    // Return the number of elements in the stack
    int length()
    {
        //write your code here. Return the number of elements in the stack
        return (index+1);
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        //write your code here. Return true if the stack is empty, false otherwise
        if(index<0) return true;
        else return false;
    }

    // Clear the stack
    void clear()
    {
        //write your code here. Clear the stack. resize the array to 1
        delete [] array;
        array = new int[1];
        index=-1;
        capacity=1;
        
    }
};
