#include<iostream>
#include<set>
using namespace std;


int main(){
    int a[] = {4,5,3,2,1,5,5};
    int n = sizeof(a)/sizeof(int);

    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }

    set<int>::iterator it;///or use auto it
    for(it = s.begin();it!=s.end();it++){
        cout<< *it <<endl;
    }



}
/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    map<int,int> m;
    int n, t, d ,a[100000];
    cin>>n;
    for(int i=1;i<=n;i++)
        {
           cin>>t>>d;
           m.insert(make_pair(t+d,i));
        }


    for(auto i=m.begin();i!=m.end();i++)
        {
            cout<<i->first<<" ";
    }

    return 0;
}
*/
