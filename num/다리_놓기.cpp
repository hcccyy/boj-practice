#include <iostream>
#include <algorithm>
using namespace std;

//next: 10164//this: 1010
long long comb(int n, int k){
    long long res = 1;
    if(n==k || k==0) return res;
    for(int i=1; i<=k; i++){
        res *= (n-i+1);
        res /= i;
    }
    return res;
}

int N, M;
int main(){
    int T;
    cin>>T;

    while(T--){
        cin>>N>>M;
        //MCN
        if(M==N || N==0) cout<<1<<'\n';
        else cout<<comb(M, N)<<'\n';
    }
}