#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, L;
vector<int> pos;

int main(){
    cin>>N>>L;
    for(int i=0; i<N; i++) {
        int x;
        cin>>x;
        pos.push_back(x);
    }
    sort(pos.begin(), pos.end());

    int ans = 1, incr = 1;
    int i=0;
    while(i+incr < pos.size()){
        if(pos[i]+L > pos[i+incr]){
            incr++;
            continue;
        }
        ans++;
        i+=incr;
        incr=1;
    }
    cout<<ans<<'\n';
}