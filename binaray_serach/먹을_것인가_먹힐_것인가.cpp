#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[1010101], B[1010101];

int main(){
    int T;
    cin>>T;

    while(T--){
        int N, M;
        cin>>N>>M;
        for(int i=0; i<N; i++) cin>>A[i];
        for(int i=0; i<M; i++) cin>>B[i];
        sort(A, A+N); 
        sort(B, B+M);

        int ans=0;
        for(int i=0; i<N; i++){
            int le=0, ri=M-1, mid;
            while(le<=ri){
                mid = le+(ri-le)/2;
                if(B[mid] < A[i]) le=mid+1;
                else ri=mid-1;
            }
            ans+=le;
        }
        cout<<ans<<'\n';
    }
}