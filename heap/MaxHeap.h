#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <fstream>
#include <stdexcept>

#define MAX_CAPACITY 100  //Defines the maximum capacity of the heap

void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}

class MaxHeap
{
private:
    int heap[MAX_CAPACITY];  //Array to store heap elements
    int size;                //Current number of elements in the heap

    //Sifts up the node at index i to maintain heap property
    void siftUp(int i)
    {
        /**Write your code here**/
        for(int j=(i-1)/2;i>0;i=j,j=(i-1)/2)
        {
            if(heap[j] < heap[i]) swap(heap[j],heap[i]);

            else break;
        }
    }

    //Sifts down the node at index i to maintain heap property
    void siftDown(int i)
    {
        /**Write your code here**/
        int l=-1;
        if(2*i+1 < size) l=2*i+1;
        if(2*i+2 < size )
        {
            if(heap[2*i+2] > heap[l]) l=2*i+2;
        }
        if(l>=0 && l<size){
            if(heap[l] > heap[i]) swap (heap[i],heap[l]);
            siftDown(l);
        }
    }

public:
    //Constructor initializes an empty heap
    MaxHeap() : size(0) {}

    //Inserts a new element x into the heap
    void insert(int x)
    {
        if (size == MAX_CAPACITY)
        {
            throw std::length_error("insert() called, but the heap is full.");
        }

        /**Write your code here**/
        heap[size]=x;
        siftUp(size);
        size++;

    }

    //Returns the maximum element without removing it
    int findMax()
    {
        if (size == 0)
        {
            throw std::runtime_error("findMax() called, but the heap is empty.");
        }

        /**Write your code here**/
        return heap[0];

    }

    //Removes and returns the maximum element from the heap
    int extractMax()
    {
        if (size == 0)
        {
            throw std::runtime_error("extractMax() called, but the heap is empty.");
        }

        /**Write your code here**/
        int a=heap[0];
        heap[0]=heap[size-1];
        size--;
        siftDown(0);
        
        return a;

    }


    //Returns the number of elements in the heap
    int getSize()
    {
        /**Write your code here**/
        return size;
    }

    //Checks if the heap is empty. Returns true if the heap is empty, false otherwise.
    bool isEmpty()
    {
        /**Write your code here**/
        return size==0;
    }

    //Increases the value of the element at index i to new_value
    void increaseKey(int i, int newValue)
    {
        if (i < 0 || i >= size || heap[i] >= newValue)
        {
            throw std::invalid_argument("increaseKey() called with invalid index or invalid new value.");
        }

        /**Write your code here**/
        int a=heap[i];
        heap[i]=newValue;
        siftUp(i);
        


    }


    //Deletes the element at index i
    void deleteKey(int i)
    {
        /**Write your code here**/
        if (i < 0 || i >= size)
        {
            throw std::invalid_argument("deleteKey() called with invalid index.");
        }
        heap[i]=heap[size-1];
        size--;
        int j=(i-1)/2;
        if(heap[i] > heap[j]) siftUp(i);
        else siftDown(i);

        
    }

    //Prints the heap's content to the output file
    void printHeap(std::ofstream &outfile)
    {
        /**Write your code here**/
        for(int i=0;i<size;i++) outfile<<heap[i]<<" ";

        outfile<<"\n";

    }

    //Checkes whether the Max Heap property is preserved or not. Returns true if the Max Heap property is valid and returns false otherwise.
    bool isValidMaxHeap()
    {
        /**Write your code here**/
        for(int i=0;i<size;i++)
        {
            int j=2*i+1;
            int k=2*i+2;
            if(j<size) if(heap[j] > heap[i] ) return false;
            if(k<size) if(heap[k] > heap[i] ) return false;
        }
        return true;
    }
};

#endif //MAXHEAP_H


/*
1 50
8
9
1 30
8
9
1 20
8
9
3
2
8
9
4
5
6 0
8
9
*/

// void siftDown(int i)
//     {
//         int l = 2*i;
//         int r = 2*i+1;
//         int smallest = i;
//         if(l<=size && A[l] < A[i])
//             smallest = l;
//         else smallest = i;
//         if(r<=size && A[r] < A[smallest])
//             smallest = r;
//         if(smallest!=i)
//         {
//             swap(A[i],A[smallest]);
//             siftDown(smallest);
//         }
//     }


