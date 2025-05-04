#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int b=100;
vector<int>adjlist[b];
bool visited[b];
queue<int>q;
void bfsre(){
    if(q.empty())
    return;
    int v=q.front();
    q.pop();
    cout<<v<<" ";
    for(int i=0;i<adjlist[v].size();i++){
        int d=adjlist[v][i];
        if(!visited[d]){
            visited[d]=true;
            q.push(d);

        }
        
    }
    bfsre();
}
int main(){
    int n,e;
    cout<<"Enter a number of vertices:";
    cin>>n;
    cout<<"Enter a number of edges:";
    cin>>e;
    cout<<"Enter a pair of vertices:";
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    int start;
    cout<<"Enter starting vertex:";
    cin>>start;
    visited[start]=true;
    q.push(start);
    
    cout<<"BFS traversal:";
    bfsre();
    return 0;
}