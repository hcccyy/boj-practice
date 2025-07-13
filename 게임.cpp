#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int X, Y, Z;
int ans=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>X>>Y;
    Z=((double)Y/X*100);
    
    int le=0, ri=(Y!=0) ? Y: X;
    while(le<=ri){
        int mid = (le+ri)/2;

        int aX=X+mid, aY=Y+mid;
        int win = ((double)aY/aX*100);

        if(win > Z) ri=mid-1;
        else le=mid+1;
    }ans=le;
    
    if(le>X) ans=-1; 
    cout<<ans;
}