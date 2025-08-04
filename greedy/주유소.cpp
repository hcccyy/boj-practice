#include <iostream>
#include <algorithm>
#include <vector>
#include <typeinfo>
using namespace std;

#define LL long long
int N;
vector<int> price, dist;

int main(){
    cin>>N;
    for(int i=0; i<N-1; i++) {
        LL x;
        cin>>x;
        dist.push_back(x);
    }
    for(int i=0; i<N; i++) {
        LL x;
        cin>>x;
        price.push_back(x);
    }

    LL totalP = 0;
    int minPrice = price[0];
    totalP += 1LL * minPrice*dist[0];
    
    for(auto i=1; i<price.size(); i++){
        if(price[i] < minPrice) minPrice = price[i];

        totalP += 1LL * minPrice*dist[i];
    }      
    cout<<totalP<<'\n';
}