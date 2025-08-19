#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> edges;
vector<bool> visited;

void dfs(int v){
    visited[v] = true;

    for(int i: edges[v]){
        if(!visited[i]) dfs(i);
    }
}

int main(){
    cin>>N>>M;
    edges.resize(N+1);
    visited.resize(N+1, false);
    
    for(int i=0; i<M; i++){
        int x, y;
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    
    int ans=0;
    for(int i=1; i<edges.size(); i++){
        if(!visited[i]) {
            dfs(i);
            ans++;
        }
    }
    cout<<ans;
}