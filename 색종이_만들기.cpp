#include <iostream>
#include <algorithm>
using namespace std;
//2630
int N;
int arr[1010][1010];
int arr2[1010][1010];

void merge(int l, int r){
    int m = (l+r)/2;

    int i=l, j=m+1, k=l;
    //
    while(i<=m && j<=r){
        if(arr[i][j] == arr[i][j+1]){
            printf("same ");
        }else{
            printf("different ");
        }
    }
}

void divide(int l, int r){
    int m;
    //for(int i=0; i<N; i++){
        if (l<r){
            m = (l+r)/2;
            divide(l, m);
            divide(m+1, r);
            merge(l, r);
        }
    //}
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int x;
            cin>>x;
            arr[i][j] = x;
        }
    }
    //index기준
    divide(0, N);
}