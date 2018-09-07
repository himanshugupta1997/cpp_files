  #include<iostream>
#include "queue.h"
using namespace std;


int main(){
    Queue q;

    for(int i=1;i<=5;i++){
        q.push(i);
    }
    q.pop();
    q.pop();

    q.push(6);
    q.push(7);

    while(!q.isEmpty()){
        cout<< q.getFront()<<" ";
        q.pop();
    }


return 0;
}


