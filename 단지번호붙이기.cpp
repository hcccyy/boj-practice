#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> map(N, vector<int>(N, 0));
vector<vector<bool>> visited(N, vector<bool>(N, false));
void dfs(int v1, int v2){
    visited[v1][v2] = true;
    for(int i=0; i<map[v1].size(); i++){
        if(!visited[v1][i] && map[v1][i]) dfs(v1, i);
    }
    for(int j=0; j<map[v1].size(); j++){
        if(!visited[j][v2] && map[j][v2]) dfs(j, v2);//rothflwy?
    }
}


int main(){
    cin>>N;
    
    string line;
    for(int i=0; i<N; i++){
        cin>>line;
        for(int j=0; j<line.length(); j++) {
            if(line[j]=='1') map[i].push_back(j);
        }
    }
    
    vector<int> house;

    cout<<house.size()<<'\n';
    for(int i=0; i<house.size(); i++) cout<<house[i]<<'\n';
}