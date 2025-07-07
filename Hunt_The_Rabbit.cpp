#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

int x;

bool go(int x){
    int start = 1;
    int end = 50; 

    while(true){
        int dist = end - start;
        auto mid = start+dist/2;
        
        if(mid == x) {
            cout<<mid << endl;
            return true;
        }
        else if(x<mid) {
            cout<<mid << " ";
            end = mid-1;
        }
        else {
            cout<<mid << " ";
            start = mid+1;
        }

        if (end == 1) return false;
    }
}

int main(){
    while(true){
        cin>>x;
        if(x==0) break;
        go(x);
    }

    return 0;
}