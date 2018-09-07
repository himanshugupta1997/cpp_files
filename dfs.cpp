#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *adjList;
public:

    Graph(int v){
        V = v;
        adjList = new list<int>[V];
    }
    void addEdge(int u,int v,bool bidir=true){
        if(bidir){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else{
            adjList[u].push_back(v);
        }
    }
    void bfs(int src){
        bool *visited = new bool[V];
        for(int i=0;i<V;i++){
            visited[i] = false;
        }

        queue<int> q;
        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            int f = q.front();
            q.pop();
            cout<< f <<" ";

            for(auto it=adjList[f].begin();it!=adjList[f].end();it++){
                    if( visited[*it]==false){
                        q.push(*it);
                        visited[*it] = true;
                    }
            }

        }
    }
        void bfsShortestPath(int src,int dest){
            int *dist = new int[V];
            int *parent = new int[V];
            for(int i=0;i<V;i++){
                dist[i] = -1;
                parent[i] = -1;
            }

            queue<int> q;
            q.push(src);
            dist[src] = 0;

            while(!q.empty()){
                int f = q.front();
                q.pop();

                for(auto it = adjList[f].begin();it!=adjList[f].end();it++){
                    if(dist[*it]==-1){
                        dist[*it] = dist[f] + 1;
                        parent[*it] = f;
                        q.push(*it);
                    }
                }


            }

            cout<<"Shortest dist between src and dest is "<<dist[dest]<<endl;
            int node = dest;
            while(node!=-1){
                cout<< node <<"<--";
                node = parent[node];

            }

        }
        void dfsHelper(int src,bool *visited){

                cout<< src <<" ";
                visited[src] = true;

                for(auto it=adjList[src].begin();it!=adjList[src].end();it++){
                        if(visited[*it]==false){
                            dfsHelper(*it,visited);
                        }

                }

        }

        void dfs(int src){
            bool* visited  = new bool[V];

            for(int i=0;i<V;i++){
                visited[i] = false;
            }

            //dfsHelper(src,visited);
            for(int i=0;i<V;i++){
                    if(!visited[src]){
                        dfsHelper(i,visited);///agar mai yahan src,visited likhta to jo  elment connected nhi hai like 7,6 in this case vo print nhi hote.

                    cout<<endl;
                    }
            }
        }



    void printAdjList(){

        for(int i=0;i<V;i++){
                cout<<i<<" -->";
            for(auto it = adjList[i].begin();it!=adjList[i].end();it++){
                    cout<< *it <<"," ;
            }
            cout<<endl;
        }
    }



};


int main(){
    Graph g(8);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(4,5);
    g.addEdge(7,6);

    g.printAdjList();
    //g.bfs(0);

    //int src,dest;
    //cin>>src>>dest;

   // g.bfsShortestPath(src,dest);
    g.dfs(3);///yahan par mai arguement kuch bhi doon printing start hamesha 0 se hi hogi kyunki upar maine function call me src pass nhi kiya balki i pass kiya hai which is initially 0;
/*
int board[50] = {0};
board[2]= 13;
board[5] = 2;
board[9] = 18;
board[18] = 11;
board[17] = -13;
board[20] = -14;
board[24] = -8;
board[25] = 10;
board[32] = -2;
board[34] = -22;


    Graph g(50);

    for(int u=0;u<36;u++){

        if(board[u]==0){
            for(int jump = 1;jump<=6;jump++){
                int v = u + jump;
                v += board[v];
                g.addEdge(u,v,false);

            }
        }


    }
    g.bfsShortestPath(0,36);
*/
return 0;
}
