#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N;
vector<pair<int, int>> cnt;

void fibo(int n){
    for(int i=0; i<=n; i++){
        if(i==0) cnt[i].first=1;
        else if(i==1) cnt[i].second=1;
        else {
            cnt[i].first = cnt[i-1].first + cnt[i-2].first;
            cnt[i].second = cnt[i-1].second + cnt[i-2].second;
        }
    }
}

int main(){
    cin>>T;
    while(T--){
        cin>>N;
        cnt.resize(N+1, {0,0});
        fibo(N);
        cout<<cnt[N].first<<' '<<cnt[N].second<<'\n';
    }
}