#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }

    Node(int value, Node *nextNode)
    {
        data = value;
        next = nextNode;
    }
};

class Queue
{
private:
    Node *peekNode; // Points to the front of the queue
    Node *tail;
    int currentSize;

public:
    // Constructor
    Queue()
    {
        peekNode = nullptr;
        tail=nullptr;
        currentSize = 0;
    }

    // Enqueue an element onto the queue
    void enqueue(int x)
    {
       Node *temp=new Node(x,nullptr);
       
       if(currentSize==0) 
       {
            peekNode=temp;
            tail=temp;
       }
       else 
       {
            tail->next=temp;
            tail=temp;
       }
       currentSize++;

       // write your code here. Create a new node with the value x and enqueue it onto the queue
       // update the peekNode and currentSize
    }

    // Remove and return the peek element
    int dequeue()
    {
        if(currentSize==0) return -1;
        else
        {
            Node *temp=peekNode;
            int a=peekNode->data;
            peekNode=peekNode->next;
            delete temp;
            currentSize--;
            return a;
            
        }
        // write your code here. Check if the queueu is empty and return -1 if it is.
        // dequeue the peek element and return it
        // update the peekNode and currentSize
        // delete the node that was dequeued
    }

    // Return the peek element without removing it
    int peek()
    {
        if(currentSize==0) return -1;
        else return peekNode->data;
        // write your code here. Check if the queueu is empty and return -1 if it is.
        // return the peek element
    }

    // Return the number of elements in the queueu
    int length()
    {
        return currentSize;
        // write your code here. Return the number of elements in the queueu
    }

    // Check if the queueu is empty
    bool isEmpty()
    {
        if(currentSize) return false;
        else return true;
        // write your code here. Return true if the queueu is empty, false otherwise
    }

    // Clear the queueu
    void clear()
    {
        while (!isEmpty())
        {
            dequeue(); // Continuously dequeue elements until the queueu is empty
        }
    }

    // Destructor
    ~Queue()
    {
        clear();
    }
};
