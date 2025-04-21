
#include "DGQueue.h"
#include "../assignment1/DGVector.h"


using namespace std;

int main(){
    DGQueue<int> q;
    DGVector<int> v;
    for (int i=0;i<10;i++) {
        q.push(i);
        v.push_back(i);
    }
    cout<<"LOADING AND DISPLAYING QUEUE: ";
    q.display();
    cout<<"LOADING QUEUE AGAIN AND SWAPPING FIRST AND LAST: ";
    for (int i=0;i<10;i++) {
        q.push(i);
    }
    q.moveFrontToRear();
    q.display();

    cout<<"INSERTING ITEM AT INDEX 8 TO SHOW LAST INDEX IN VECTOR: ";
    v.replace(4,8);
    cout<<to_string(DGVector<int>::findLastIndexOfItem(v,4))<<endl;

    cout<<"ATTEMPTING TO FIND ELEMENT NOT IN LIST - RETURNS -1: ";
    cout<<to_string(DGVector<int>::findLastIndexOfItem(v,82))<<endl;

    cout<<"USING INSERTION SORT TO SORT QUEUE: "<<endl;
    DGQueue<int> q2;
    for (int i=10; i>0; i--) {
        q.push(i);
        q2.push(i);
    }
    cout<<"Q1: ";
    q.display();
    cout<<"Q2: ";
    q2.insertionSort();
    q2.display();
}