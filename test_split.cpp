/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include <iostream>
#include "split.h"
using namespace std; 


int main(int argc, char* argv[])
{
  // Node*a = new Node(1, nullptr);
  // Node*b = new Node(2,a);
  // Node*c = new Node(2, nullptr);
  Node*d = new Node(4, nullptr); 
  Node* temp = new Node(2, d);
  Node*evens = nullptr;
  Node*odds = nullptr; 
  split(temp, odds, evens); 
  cout << evens->next->value << endl; 
  //cout << evens->value << endl; 
  // cout << evens->next->value << endl; 
  // cout << evens->next->next->value << endl;
}

