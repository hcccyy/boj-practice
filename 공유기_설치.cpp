#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, C, x[1010101];

int main(){
    cin>>N>>C;
    for(int i=0; i<N; i++) cin>>x[i];
    sort(x, x+N);

    //가장 인접한 공유기 사이의 거리가 최대가 되도록
    //공유기는 뭐라해야하지 공식을. 사이 칸 개수: N/C 아닌데
    //아 최대거리.가 범위안이어야 
    //이게 왜 이분탐색이지? 아 mid개수 증가시키면서?
    int le=x[0], ri=x[N-1];
    while(le<=ri){
        int mid = le+(ri-le)/2;

        
    }
}
