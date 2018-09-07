#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void printQ(queue<int> q){    ///here i am not using "&q" because if i do so then i am passing actual queue to parameter rather if i use only "q" it means i am passing copy of queue.
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

}


int main(){

    queue<int> q;
    stack<int> s;

    for(int i=1;i<=5;i++){
        q.push(i);
    }
    ///Empty the q into s
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    ///Empty the s into q
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    ///Print the q
    printQ(q);

return 0;
}
