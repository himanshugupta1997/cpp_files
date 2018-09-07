#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    map< string, list<pair<string,int> > > m;
public:

    Graph(int v){
        V = v;
        //l = new list<<int,int> >[V];
    }
    void addEdge(string src,string dest,int wt){
        m[src].push_back( make_pair(dest,wt) );
        m[dest].push_back( make_pair(src,wt) );

    }
    void print(){
        for(auto it = m.begin();it!=m.end();it++){
            cout<<"City "<< it->first<<" -->";

            auto j = it->second.begin();
            while(j!=it->second.end()){
                    cout<<j->first<<" , "<<j->second<<endl;
                    j++;
            }
            cout<<endl;

        }
    }
};

int main(){
    Graph g(4);
    g.addEdge("Kohat","Rohini",5);

    g.addEdge("Kohat","Dwarka",2);
    g.addEdge("Rohini","Pitampura",5);
    g.addEdge("Dwarka","Rohini",1);

    g.print();


}

