//Jack Keys || CompSci303 || Assignment #3

#ifndef QUEUE_H
#define QUEUE_H

#include <list>

template<typename dataType>
class Queue
{

  private:
  
    std::list<dataType> data; //doubly linked list to hold data
  
  public:
  
    // pre  -- takes a value of type dataType, toInsert
    // post -- pushes toInsert onto the back of the queue
    void enqueue(dataType toInsert) {this->data.push_back(toInsert);}
    
    // pre  -- takes no arguments
    // post -- removes and returns the value at the front of the queue
    dataType dequeue() 
    {
      dataType temp = this->data.front();
      this->data.pop_front();
      return temp;
    }
    
    // pre  -- takes no arguments
    // post -- returns the value at the front of the queue without removing it
    dataType peek() {return this->data.front();}
    
    // pre  -- takes no arguments
    // post -- returns true if the queue is empty; else false
    bool isEmpty() {return this->data.empty();}
    
    // pre  -- takes no arguments
    // post -- returns the number of elements in the queue
    int getSize() {return this->data.size();}

};

#endif