#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long X, Y, Z;
int ans=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>X>>Y;
    Z=Y*100/X;
    
    if(Z>=99) {
        cout<<-1;
        return 0;
    }

    long long le=1, ri=10e9;
    while(le<=ri){
        long long mid = le+(ri-le)/2;

        long long win = (Y+mid)*100/(X+mid);

        if(win > Z) ri=mid-1;
        else le=mid+1;
    }ans=le;
    
    cout<<ans;
}