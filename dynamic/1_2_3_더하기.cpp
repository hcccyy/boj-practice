#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N;
vector<int> dp;

void go(int n){
    //dp[i] = dp[i-1]+dp[i-2]+dp[i-3]
    for(int i=1; i<=n; i++){
        if(i==1) dp[i] = 1;
        else if(i==2) dp[i] = 2;
        else if(i==3) dp[i] = 4;
        else dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    cout<<dp[n]<<'\n';
}

int main(){
    cin>>T;
    while(T--){
        cin>>N;
        dp.resize(N+1);
        go(N);
    }
}