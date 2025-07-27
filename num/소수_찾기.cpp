#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;
    int ans=0;

    while(N--){
        bool flag=false;
        int x;
        cin>>x;

        if(x==1) continue;
        for(int i=2; i<x; i++){
            if(!(x%i)){
                flag = true;
                break;
            }
        }
        if(!flag) ans++;
    } 
    cout<<ans;
}