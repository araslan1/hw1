#ifndef SPLIT_H
#define SPLIT_H


struct Node 
{
  int value;
  Node* next;
  Node* prev; 

  /**
   * Initializing constructor
   */
  Node(){
    value = 0; 
    next = nullptr; 
  }

  Node(int v, Node* n)
  {
    value = v;
    next = n;
  }
};

void split(Node*& in, Node*& odds, Node*& evens);

#endif
