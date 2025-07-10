#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

int N, M;
int A[100001];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;
    for(int i=0; i<N; i++) cin>>A[i];
    sort(A, A+N);   //포인터로 받음

    cin>>M;
    while(M--){
        bool found = false;
        int x;
        cin>>x;

        int start=0, end=N-1;
        int mid_idx;
        while(start <= end){
            mid_idx = (start+end)/2;

            if(x == A[mid_idx]) {
                found = true;
                break;
            }
            else if(x < A[mid_idx]) end = mid_idx-1;
            else start = mid_idx+1;
        }
        cout<<(found ? "1\n" : "0\n");
    }
}