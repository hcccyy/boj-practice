#include <iostream>
#include <algorithm>
using namespace std;

int N, k;
int arr[1010101];
int arr2[1010101];

void merge(int l, int r){
    int m = (l+r)/2;
    int i=l, j=m+1, k=l;

    while(i<=m && j<=r){
        if(arr[i] <= arr[j])
            arr2[k++] = arr[i++];
        else
            arr2[k++] = arr[j++];
    }
    int tmp = i > m ? j : i;
    while(k<=r) arr2[k++] = arr[tmp++];

    for(int i=l; i<=r; i++)
        arr[i] = arr2[i];
}

void divide(int l, int r){
    if (l<r){
        int m = (l+r)/2;
        divide(l, m);
        divide(m+1, r);
        merge(l, r);
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

    int m=N/k;
    for(int i=0; i<N; i+=m)
        divide(i, i+m-1);

    for(int i=0; i<N; i++) cout<<arr[i]<<' ';
}