#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

int N, M;
int A[100001], B[100001];

bool go(int num, int m, int arr[]){
    int start=0, end=m-1;

    while(start <= end){
        int dist = end-start;
        int mid_idx = start+dist/2;
        int mid = arr[mid_idx];

        if(num == mid) {
            cout<<"1"<<endl;
            return true;
        }
        else if(num < mid) end = mid_idx-1;
        else start = mid_idx+1;
    }
    cout<<"0"<<endl;
    return false;
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++) cin>>A[i];
    sort(A, A+N);   //포인터로 받음

    cin>>M;
    for(int i=0; i<M; i++) cin>>B[i];

    for(int i=0; i<M; i++) {
        go(B[i], M, A);
    }

}