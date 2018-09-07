#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

int main(){
   // unordered_map<string,int> m;
    map<string,int> m;

    ///Insert
    m["mango"] = 90;
    m["guava"] = 120;

    m["pear"] = 120;
    m.insert(make_pair("apple",100));
   // m["apple"]=150;
    ///Find
    cout<<m["apple"]<<endl;

    ///Search or Find
    if( m.count("apple")>0){
        cout<<"Apple exists: "<<m["apple"];
    }

    auto it = m.find("apple");
    if(it!=m.end()){
        cout<<endl<<"Found "<<"-->";
        cout<< it->first <<":";
        cout<< it->second <<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
   //m.erase("mango");
    for(auto it = m.begin();it!=m.end();it++){
            cout<< it->first <<" ";
            cout<< it->second <<" ";
            cout<<endl;
    }


    cout<<"******";
    cout<<m["apple"];

}
