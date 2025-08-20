#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int M, N;
vector<vector<int>> box;

int bfs(){
    queue<pair<int, int>> q;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) {
            if(box[i][j] == 1)
                q.push({i, j});
        }
    }

    while(!q.empty()){
        int x1 = q.front().first;
        int x2 = q.front().second;
        q.pop();
        
        //상 하 좌 우
        if(x1-1 >= 0 && box[x1-1][x2]==0) {
            box[x1-1][x2] = box[x1][x2] + 1;
            q.push({x1-1, x2});
        }
        if(x1+1 < N && box[x1+1][x2]==0) {
            box[x1+1][x2] = box[x1][x2] + 1;
            q.push({x1+1, x2});
        }
        if(x2-1 >= 0 && box[x1][x2-1]==0) {
            box[x1][x2-1] = box[x1][x2] + 1;
            q.push({x1, x2-1});
        }
        if(x2+1 < M && box[x1][x2+1]==0) {
            box[x1][x2+1] = box[x1][x2] + 1;
            q.push({x1, x2+1});
        }   
    }

    int day = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) {
            if (box[i][j] == 0) return -1;
            day = max(day, box[i][j]);
        }
    }
    return day-1;
}  

int main(){
    cin>>M>>N;
    box.resize(N);

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int x;
            cin>>x;
            box[i].push_back(x);
        }
    }
    
    cout<<bfs()<<'\n';

}