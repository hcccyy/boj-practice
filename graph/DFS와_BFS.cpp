#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, V;
vector<vector<int>> edges;
vector<bool> visited;

void DFS(int v){
    visited[v] = true;
    cout<<v<<' ';
    for(int i=0; i<edges[v].size(); i++){
        if(!visited[edges[v][i]]) 
            DFS(edges[v][i]);
    }
}  

void BFS(int v){
    queue<int> add;
    visited[v] = true;
    add.push(v);

    while(!add.empty()){
        int x = add.front();
        cout<<x<<' ';
        add.pop();

        for(int i=0; i<edges[x].size(); i++){
            if(!visited[edges[x][i]]){
                add.push(edges[x][i]);
                visited[edges[x][i]] = true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M>>V;
    edges.resize(N+1);
    visited.resize(N+1, false);

    for(int i=0; i<M; i++){
        int x, y;
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for(int i=1; i<=N; i++) sort(edges[i].begin(), edges[i].end());

    DFS(V);
    cout<<'\n';
    for(int i=1; i<=N; i++) visited[i] = false;
    BFS(V);
}