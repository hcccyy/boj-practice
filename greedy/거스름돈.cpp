#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int x;
    cin>>x;
    
    x = 1000-x;
    int cnt=0;
    
    while(x){
        if(x/500) {
            cnt++;
            x-=500;
        }
        else if(x/100) {
            cnt++;
            x-=100;
        }
        else if(x/50){
            cnt++;
            x-=50;
        }
        else if(x/10){
            cnt++;
            x-=10;
        }
        else if(x/5){
            cnt++;
            x-=5;
        }
        else {
            cnt++;
            x-=1;
        }
    }
    cout<<cnt<<'\n';    
}