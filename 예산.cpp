#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int A[1010101];

int main(){
    int sum=0;

    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>A[i];
        sum+=A[i];
    }
    sort(A, A+N);
    cin>>M;

    if(sum <= M) {
        cout<<A[N-1]<<'\n';
        return 0;
    }

    int le=A[0], ri=A[N-1], ans;
    while(le<=ri){
        int mid = le+(ri-le)/2;
        
        sum=0;
        for(int i=0; i<N; i++) {
            if(A[i] > mid) sum += mid;
            else sum += A[i];
        }

        if(sum <= M) {
            le = mid+1;
            ans = mid;
        }else ri = mid-1;
    }
    cout<<ans<<'\n';
}