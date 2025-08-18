#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> com;
vector<bool> visited;
int ans=0;

int dfs(int v){
    visited[v]=true;
    for(int i=0; i<com[v].size(); i++){
        if(!visited[com[v][i]]) {
            dfs(com[v][i]);
            ans++;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //dfs
    cin>>N>>M;
    com.resize(N+1);
    for(int i=0; i<M; i++){
        int x, y;
        cin>>x>>y;
        com[x].push_back(y);
        com[y].push_back(x);
    }
    visited.resize(N+1, false);

    int n = dfs(1);
    cout<<n;
}