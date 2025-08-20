#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int M, N;
vector<vector<int>> box;
vector<vector<bool>> visited;

void dfs(int i, int j){
    visited[i][j] = true;
    if(!box[i][j]) box[i][j]=1;
    
    //상 하 좌 우
    if(i-1 >= 0 && !visited[i-1][j] && box[i-1][j] != -1)
        dfs(i-1, j);
    if(i+1 < N && !visited[i+1][j] && box[i+1][j] != -1)
        dfs(i+1, j);
    if(j-1 >= 0 && !visited[i][j-1] && box[i][j-1] != -1)
        dfs(i, j-1);
    if(j+1 < N && !visited[i][j+1] && box[i][j+1] != -1)
        dfs(i, j+1);

}

int main(){
    cin>>M>>N;
    box.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M));

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            cin >> box[i][j];
    }
    
    int day=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) {
            if(!visited[i][j] && box[i][j] == 1) {
                dfs(i, j);
                day++;
            }
        }
    }
    cout<<day<<'\n';
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            cout << box[i][j] << ' ';
        printf("\n");
    }
    //저장될때부터 모두 1이면 0출력
    //모두 익지 못하는 상황이면 -1출력
}