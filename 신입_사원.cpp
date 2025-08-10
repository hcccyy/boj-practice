#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N;
vector<pair<int, int>> score;
vector<pair<int, int>> ans;
vector<pair<int, int>> keep_ele;

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
        
            int min=10000000, min_1st=0;
            //최솟값 찾기 아 내부에서 최솟값 계속 찾기
            //ans 벡터에다가 넣고 지우면 되겠다
            for(int j=0; j<N; j++) {
                if(min > score[j].second) {
                    min=score[j].second;
                    min_1st = j;
                }
            }keep_ele.push_back(score[min_1st]);

            //일단 처음 최솟값 대비 ans에 넣어
            for(int j=0; j<N; j++){
                if (j<min_1st && score[j].second > min)
                    ans.push_back(score[j]);
                else if(j>min_1st && score[j].second<min)
                    ans.push_back(score[j]);
            }

            while(!ans.empty()){
                min=10000000;
                for(int j=0; j<ans.size(); j++) {
                    if(min > ans[j].second) {
                        min=ans[j].second;
                        min_1st = j;
                    }
                }
                keep_ele.push_back(ans[min_1st]);
                ans.erase(ans.begin()+min_1st);
                
                int j=0;
                while (j<ans.size()){
                    if (j<min_1st-1 && ans[j].second<min){ 
                        ans.erase(ans.begin()+j);
                        j=0;
                    }
                    else if(j>min_1st-1 && ans[j].second>min){
                        ans.erase(ans.begin()+j);
                        j=0;
                    }
                    else j++;
                }
            }
        

        cout<<keep_ele.size()<<"\n";
        ans.clear();
        score.clear();
        keep_ele.clear();
    }
}