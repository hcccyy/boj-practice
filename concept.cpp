#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];
int arr2[10];

void merge(int l, int r){
    int mid = (l+r)/2;

    int i=l, j=mid+1, k=l;
    while(i<=mid && j<=r){
         if(arr[i] <= arr[j]) 
            arr2[k++] = arr[i++];
        else
            arr2[k++] = arr[j++];
    }

    int tmp = i > mid ? j : i;
    while(k<=r) arr2[k++] = arr[tmp++];

    for(int i=l; i<=r; i++) arr[i] = arr2[i];
}

void divide(int l, int r){
    int m;
    if(l < r){
        m = (l+r)/2;
        divide(l, m);
        divide(m+1, r);
        merge(l, r);
    }
}

int main(){
    int a;
    for(int i=0 ;i<10; i++){
        cin>>a;
        arr[i] = a;
    }

    divide(0, 9);
    for(int i=0; i<10; i++) cout<<arr2[i]<<' ';
}