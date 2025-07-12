#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int H[1010101];
int ans=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;
    for(int i=0; i<N; i++) cin>>H[i];
    sort(H, H+N);

    int le=0, ri=H[N-1];
    while(le<=ri){
        int mid = (le+ri)/2;

        long long sum=0;
        for(int i=0; i<N; i++) {
            if(H[i]-mid > 0) sum+=H[i]-mid;
        }

        if(sum >= M) {
            le = mid+1;
            ans = mid;
        }
        else ri = mid-1;
    }
    cout<<ans;
}