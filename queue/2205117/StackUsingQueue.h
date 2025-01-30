#include <iostream>
using namespace std;

#include "QueueLinkedList.h"



class Stack
{
private:
    
    Queue q1;//write your code here. Add additional private variables if necessary

public:
    // Constructor
    Stack()
    {
        //write your code here. Initialize additional private variables if necessary
    }
    Stack(int initialCapacity)
    {
        //write your code here. Initialize additional private variables if necessary
    }

    // Destructor
    ~Stack()
    {
    }

    
    // Push an element onto the stack
    void push(int x)
    {
        //write your code here.
        //push the element onto the stack
        q1.enqueue(x);
        int s=q1.length();
        for(int i=1;i<s;i++)
        {
            int temp=q1.dequeue();
            q1.enqueue(temp);
        }

        
    }

    // Remove and return the top element
    int pop()
    {
       //write your code here. Check if the stack is empty and return -1 if it is.
       if(q1.isEmpty()) return -1;
       else 
        return q1.dequeue();


    }

    // Return the top element without removing it
    int top()
    {
        //write your code here. Check if the stack is empty and return -1 if it is.
        //return the top element
        return q1.peek();
    }

    // Return the number of elements in the stack
    int length()
    {
        //write your code here. Return the number of elements in the stack
        return q1.length();
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        //write your code here. Return true if the stack is empty, false otherwise
        return q1.isEmpty();
    }

    // Clear the stack
    void clear()
    {
        //write your code here. Clear the stack.
        q1.clear();
        
    }
};
