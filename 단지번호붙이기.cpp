#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> map;
vector<vector<bool>> visited;
vector<int> house;
int cnt=0;

int dfs(int v1, int v2){
    visited[v1][v2] = true;
    if(map[v1][v2]) cnt++;
    //상 하 좌 우
    if (v1-1 >= 0 && !visited[v1-1][v2] && map[v1-1][v2]) 
        dfs(v1-1, v2); 
    if (v1+1 < N && !visited[v1+1][v2] && map[v1+1][v2]) 
        dfs(v1+1, v2);
    if (v2-1 >= 0 && !visited[v1][v2-1] && map[v1][v2-1]) 
        dfs(v1, v2-1);
    if (v2+1 < N && !visited[v1][v2+1] && map[v1][v2+1]) 
        dfs(v1, v2+1);

    return cnt;
}


int main(){
    cin>>N;
    map.resize(N);
    visited.resize(N, vector<bool>(N, false));
    
    string line;
    for(int i=0; i<N; i++){
        cin>>line;
        for(int j=0; j<line.length(); j++){
            map[i].push_back(line[j]-'0');
        }
    }

    for(int i=0; i<map.size(); i++){
        for(int j=0; j<map[i].size(); j++){
            if(map[i][j] && !visited[i][j]) {
                int ans = dfs(i, j);
                house.push_back(ans);
                cnt=0;
            }
        }
    }
    cout<<house.size()<<'\n';
    for(int x: house) cout<<x<<'\n';
}