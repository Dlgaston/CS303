#include <iostream>
#include <vector>
#include <numeric>

#ifndef DGVECTORSTACK_H
#define DGVECTORSTACK_H
using namespace std;

class dgVectorStack{
  private:
    vector<int> stack;
    public:
      dgVectorStack(){}
      dgVectorStack(int size){
        stack.reserve(size);
      }
      ~dgVectorStack(){}
      bool isEmpty(){
        return stack.empty();
      }
      void push(int num){
        stack.push_back(num);
      }
      // Checks if vector is empty pops the top if not empty.
      void pop_top(){
        if (!isEmpty()) {
          stack.pop_back();
        } else {
          cout << "Stack is empty, cannot pop!" << endl;
        }
      }
      // Gets the top element of the stack
      int peek() {
        if (!isEmpty()) {
          return stack.back();
        } else {
          cout << "Stack is empty!" << endl;
          return -1;
        }
       }
       // Uses numeric library to get the sum of the vector and then returns the average
      double find_avg(){
        if (isEmpty()) {
          cout << "Stack is empty, no average to calculate!" << endl;
          return 0.0;
        } else {
          // Calculate the sum and divide by the number of elements
          int sum = accumulate(stack.begin(), stack.end(), 0);
          return static_cast<double>(sum) / stack.size();
        }
      }
      void print(){
        if(isEmpty()){
          cout<<"Stack is empty!"<<endl;
          return;
        }
        cout<<"[";
        for(int i = 0; i < stack.size(); i++){
          cout<<stack[i]<<",";
        }
        cout<<"]"<<endl;
        }
};
#endif //DGVECTORSTACK_H
