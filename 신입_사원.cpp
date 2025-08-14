#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N;
vector<pair<int, int>> score;

int main(){
    cin>>T;

    while(T--){
        cin>>N;
        for(int i=0; i<N; i++){
            int x, y;
            cin>>x>>y;
            score.push_back({x, y});
        }
        sort(score.begin(), score.end());

        int cnt=1;
        int min = score[0].second;
        for(int i=1; i<N; i++){
            if(score[i].second < min){
                cnt++;
                min = score[i].second;
            }
        }

        cout<<cnt<<"\n";
        score.clear();
    }
}