
#include <iostream>
#include "dgSingleLinkList.h"
#include "dgVectorStack.h"

int main() {
    dgSingleLinkList<int> dg;

    cout<<"LOADING LINKED LIST WITH PUSH BACK\n"
          "+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    for (int i=1; i<=10; i++) {
        dg.push_back(i);
    }
    dg.print();
    cout<<"Size:" << dg.size()<<endl;

    cout<<"USING EMPTY TO DELOAD LIST\n"
      "+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    dg.empty();
    dg.print();
    cout<<"Size:" << dg.size()<<endl;

    cout<<"LOADING LINKED LIST WITH PUSH FRONT\n"
      "+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    for (int i=1; i<=15; i++) {
        dg.push_front(i);
    }
    dg.print();
    cout<<"Size:" << dg.size()<<endl;

    cout<<"REMOVING INDEX 0, 3, and 5\n"
  "+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<dg.remove(0)<<endl;
    dg.print();
    cout<<dg.remove(3)<<endl;
    dg.print();
    cout<<dg.remove(5)<<endl;
    dg.print();
    cout<<dg.remove(32)<<endl;
    dg.print();

    cout<<"INSERTING ITEM IN INDEX 0, 3, and outside range\n"
  "+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  dg.insert(0,100);
  dg.print();
  dg.insert(3,999);
  dg.print();
  dg.insert(25,10000);
  dg.print();
  cout<<"FINDING ITEM 10 in list\n"
"+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<dg.find(10)<<endl;

  cout<<"Printing Front and Back\n"
"+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<dg.front()<<endl;
  cout<<dg.back()<<endl;


  dgVectorStack stack;
  cout<<"CHECKING IF STACK IS EMPTY\n"
    "+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

  if (stack.isEmpty()) {
    cout<<"Stack is empty\n";
  }
  cout<<"LOADING STACK VECTOR WITH PUSH BACK\n"
    "+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  for (int i = 0; i < 10; i++) {
    stack.push(i);
  }
  stack.print();

  cout<<"REMOVING TOP ELEMENT IN STACK\n"
  "+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  stack.pop_top();
  stack.print();

  cout<<"PEEKING TOP ELEMENT IN STACK\n"
"+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<stack.peek()<<endl;


  cout<<"GETTING AVERAGE OF ELEMENTS IN STACK\n"
"+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<stack.find_avg()<<endl;
}
