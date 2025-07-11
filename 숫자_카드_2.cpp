#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, card[1010101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;
    for(int i=0; i<N; i++) cin>>card[i];
    sort(card, card+N);
    
    cin>>M;
    while(M--){
        int x;
        cin>>x;

        int le=0, ri=N, ub=N, lb=0;
        while( le <= ri ){
            int mid = (le+ri)/2;
            
            if(x < card[mid]){
                ri = mid-1;
                ub = mid;
            }
            else le = mid+1;
        }

        le=0; ri=N;
        while(le<=ri){
            int mid = (le+ri)/2;

            if(x <= card[mid]){
                ri = mid-1;
                lb = mid;
            }
            else le = mid+1;
        }
        cout<<ub-lb<<' ';
    }
}