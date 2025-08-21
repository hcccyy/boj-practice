#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<vector<char>> paint;
vector<vector<bool>> visited;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void color(int x, int y, char c){
    visited[x][y] = true;
    int nx, ny;
    for(int i=0; i<4; i++){
        nx = dx[i] + x;
        ny = dy[i] + y;
        if(nx>=0 && nx<N && ny>=0 && ny<N){
            if(!visited[nx][ny] && c == paint[nx][ny]) 
                color(nx, ny, c);
        }
    }
}

void nonColor(int x, int y, char c){
    visited[x][y] = true;
    int nx, ny;

    for(int i=0; i<4; i++){
        nx = dx[i] + x;
        ny = dy[i] + y;
        
        if(nx>=0 && nx<N && ny>=0 && ny<N){
            if(!visited[nx][ny]){
                if((c=='R' || c=='G') && (paint[nx][ny]=='R' || paint[nx][ny]=='G'))
                    nonColor(nx, ny, c);
                else if(c == paint[nx][ny])
                    nonColor(nx, ny, c);
            }
        }
    }
}

int main(){
    cin>>N;
    paint.resize(N, vector<char>(N));
    visited.resize(N, vector<bool>(N, false));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) cin>>paint[i][j];
    }
    
    int cnt=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) {
            if(!visited[i][j]) {
                color(i, j, paint[i][j]);
                cnt++; 
            }
        }
    }
    cout<<cnt<<' ';
    //reset
    cnt=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) visited[i][j]=false;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) {
            if(!visited[i][j]) {
                nonColor(i, j, paint[i][j]);
                cnt++; 
            }
        }
    }
    cout<<cnt;
}