#include <cstddef>
#include <stdexcept>
#include <string>
#include <iostream>
#include "ulliststr.h"
using namespace std; 

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

std::string* ULListStr::getValAtLoc(size_t loc) const{ 
    if (loc <= 0 || loc > size_){
      return NULL; 
    }else if (size_ == 0) {
      return NULL; 
    }else {
      Item* temp = head_; 
      int n = loc;
      int v = size_; 
      int counter = 0; 
      std::string* curr; 
      while (n != 0){
        n--; 
        curr = &(temp->val[(temp->first) + counter]); 
        counter++; 
        if (((temp->first) + counter) == temp->last){
          temp = temp->next; 
          counter = 0; 
        }
        if (n==1){
          curr = &(temp->val[(temp->first) + counter]); 
        }
      }
      //std::cout << *curr << endl;
      return curr; 
    }
    return NULL; 
}

void ULListStr::push_front(const std::string& val){
  if (size_ == 0){
    head_ = new Item; 
    tail_ = head_; 
    head_->last = 1; 
    head_->val[head_->first] = val; 
  }else if (head_->first != 0){
    int n = (head_->first) - 1;
    head_->val[n] = val; 
    head_->first = n; 
  }else {
    Item* temp = new Item; 
    temp->first = ARRSIZE-1; 
    temp->last = ARRSIZE; 
    temp->val[temp->first] = val;
    temp->next = head_; 
    head_->prev = temp; 
    head_ = temp; 
  }
  size_ += 1; 
}

void ULListStr::push_back(const std::string& val){
  if (size_ == 0){
    push_front(val);
  }else if (tail_->last == ARRSIZE){
    Item*temp = new Item; 
    temp->first = 0; 
    temp->last = 1; 
    temp->val[0] = val; 
    temp->prev = tail_; 
    tail_ = temp; 
    size_ += 1; 
  }else {
    int index = tail_->last; 
    tail_->val[index] = val; 
    tail_->last += 1; 
    size_ +=1; 
  }
}


void ULListStr::pop_back(){
  if(size_ == 0){
    return;
  }else if (tail_->last == 1){
    Item* temp = tail_; 
    (tail_->last)--; 
    tail_ = tail_->prev;
    delete temp;
  }else{
    //size_t index = (tail_->last)-1;
    tail_->last = (tail_->last) -1; 
  }
  size_ -= 1; 
}

void ULListStr::pop_front(){
  if (size_ == 0){
    return;
  }else if (head_->first == ARRSIZE-1){
    Item* temp = head_; 
    head_ = temp->next; 
    head_->prev = NULL;
    delete temp; 
  }else{
    size_t index = head_->first;
    head_->first = index + 1;
  }
  size_ -= 1; 
}

std::string const & ULListStr::back() const{
  //cout << tail_->val[(tail_->last)-1] << endl; 
  return tail_->val[(tail_->last)-1]; 
}

std::string const & ULListStr::front() const{
  //cout << head_->val[head_->first] << endl; 
  return head_->val[head_->first]; 
}



void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc+1);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc+1);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  //cout << *ptr << endl; 
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc+1);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  cout << *ptr << endl; 
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
