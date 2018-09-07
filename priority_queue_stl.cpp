#include<iostream>
#include<queue>
#include<functional>
#include<cstring>
using namespace std;

class myCompare{
public:
    bool operator() (int a,int b){
        return a>b;
    }

};

class Person{
public:
    int money;
    char name[20];

    Person(char *n,int m){
    money =m ;
    strcpy(name,n);
    }
    void print(){
        cout<<"Name : "<<name<<endl;
        cout<<"money : "<<money<<endl;
    }


};

class PersonCompare{
public:
      bool operator()(Person &a,Person &b){
            return a.money > b.money;
      }

};

int main(){

    int a[] = {1,5,4,3,2,7};
    //priority_queue<int> p_max;
    priority_queue<int,vector<int>,myCompare > pq;


    for(int i=0;i<6;i++){
        pq.push(a[i]);
    }

    while(!pq.empty()){
        cout<< pq.top()<<" ";
        pq.pop();
    }

    Person p1("XYZ",100);
    Person p2("ABC",200);
    Person p3("PQR",150);

    priority_queue<Person,vector<Person>,PersonCompare> pp;
    pp.push(p1);
    pp.push(p2);
    pp.push(p3);

    while(!pp.empty()){
        Person p = pp.top();
        p.print();
        pp.pop();

    }


return 0;
}
