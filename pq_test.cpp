#include<iostream>
#include "priority_queue.h"
using namespace std;


int main(){

    PriorityQueue pq;
    pq.push(5);
     pq.push(7);
     pq.push(1);
      pq.push(3);
      pq.push(8);


      cout<< pq.getMin()<<endl;


      while(!pq.isEmpty()){

        cout<< pq.getMin()<<" ";
        pq.removeMin();
      }


return 0;
}
