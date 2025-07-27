#include <iostream>
#include <algorithm>
using namespace std;

int recursiveSum(int n){
    if (n==1) return n;
    else return recursiveSum(n-1) + n;
}

int fastSum(int x){
    if (x==1) return x;
    else{
        if(!(x%2)) 
            return fastSum(x/2) * 2 + (x/2)*(x/2);
        else 
            return fastSum((x-1) / 2) * 2 + ((x-1) / 2) * ((x-1) / 2) + x;
    }
}

int main(){
    int A;
    cin>>A;
    //cout<<recursiveSum(A);
    cout<<fastSum(A);

}