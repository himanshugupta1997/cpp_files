#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s,int data){ ///reversing of stack using "recursion" or 1 stack....
    ///Base Case
    if(s.empty()){
        s.push(data);
        return;
    }
    ///Otherwise ?
    int topEle = s.top();
    s.pop();
    insertAtBottom(s,data);
    s.push(topEle);

}
void insertAtBottom2(stack<int> &s,int data){   /// reverse of stack using 2 stack....

    stack<int> s2;
    while(!s.empty()){
        s2.push( s.top());
        s.pop();
    }
    s.push(data);

    while(!s2.empty()){
        s.push( s2.top());
        s2.pop();
    }
}



void reverseStack(stack<int> &s){
    ///Base Case
    if(s.empty()){
        return;
    }
    ///Otherwise ?
    int top = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,top);
}


int main(){
    stack<int> s;
    for(int i=1;i<=5;i++){
        s.push(i);
    }

    reverseStack(s);


    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
