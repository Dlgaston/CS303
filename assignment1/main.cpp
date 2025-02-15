#include <iostream>
#include  "DGVector.h"

using namespace std;

int main() {
    DGVector<int> dg(4);

    for (int i = 0; i < 4; i++) {
        dg[i] = i;
    }
        cout<<"STARTING PART 1 ================================"<<endl;
    dg.print();
    cout<<"Index of 3: "<< dg.indexOf(3)<<endl;
    cout<<"Index of 4: "<< dg.indexOf(4)<<endl;
 try {
        cout<<"STARTING PART 2 ================================"<<endl;
     dg.print();
     pair<int,int> result = dg.replace(56, 1);
     cout<<"Result: "<<result.first<<" "<<result.second<<endl;
     dg.print();
     //Failure out of bounds
     pair<int,int> failedResult = dg.replace(32, 6);
     cout<<"Result: "<<failedResult.first<<" "<<failedResult.second<<endl;
     dg.print();
    }catch (out_of_range& e) {
        cout<<e.what()<<endl;
    }

    // No try catch, because you can't get an index out of bounds on a pushback
    cout<<"STARTING PART 3 ================================"<<endl;
    dg.print();
    dg.push_back(101);
    dg.print();

    try {
        cout<<"STARTING PART 4 ================================"<<endl;
        dg.print();
        dg.remove(4);
        dg.print();
        dg.remove(4);
    }catch (out_of_range& e) {
        cout<<e.what()<<endl;
    }

    dg.insert(1234,2);
    dg.print();
    return 0;
}
