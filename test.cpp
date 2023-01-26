#include <iostream>
#include <string>

#define ARRSIZE 10
struct Item {
    std::string val[ARRSIZE];
    /**
     * first and last indicate the occupied/used 
     * elements of the array where first is an
     * inclusive index and last is an exclusive
     * index (i.e. first=0, last=0 indicates none
     * of the elements of the array are used and
     * first=0, last=ARRSIZE indicates the array
     * is fully occupied
     */
    size_t first, last;
    Item *prev;
    Item *next;

    /**
     * Default constructor
     */
    Item(){
      first = last = 0;
      prev = next = NULL;
    }
  };


int main(){
  Item* head = new Item; 
  head->val[0] = 1; 
  cout << head->val[0] << endl;
  delete head; 
  return 0;
}