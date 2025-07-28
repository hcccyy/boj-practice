#include <iostream>
#include <algorithm>
using namespace std;

int N, k;
int arr[1010101];
int arr2[1010101];

void mergeSort(){
    for(int sz=1; sz<N; sz*=2){
        for(int i=0; i<N; i+=2*sz){
            int l=i;
            int m = min(i+sz, N);
            int r = min(i+2*sz, N);

            int p=l, q=m, t=l;
            while(p<m && q<r){
                if(arr[p] <= arr[q]) arr2[t++] = arr[p++];
                else arr2[t++] = arr[q++];
            }
            int tmp = p >= m ? q : p;
            while(t<r) arr2[t++] = arr[tmp++];
            for(int j=l; j<r; j++) 
                arr[j] = arr2[j];
        }

        if(sz == N/k) break;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>N;
    int x;
    for(int i=0; i<N; i++) {
        cin>>x;
        arr[i] = x;
    }
    cin>>k;

    mergeSort();

    for(int i=0; i<N; i++) cout<<arr[i]<<' ';
}