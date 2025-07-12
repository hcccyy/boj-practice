#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

bool binaray_search(int N, vector<int>& S){
    auto first = S.begin();
    auto last = S.end();

    while(true){
        auto len = distance(first, last);
        auto mid_idx = first + floor(len / 2);

        if(*mid_idx == N) return true;
        else if(*mid_idx > N) last = mid_idx-1;
        else first = mid_idx+1;

        if(len == 1) return false;
    }
}

void test(){
    auto N = 2;
    vector<int> S{1, 3, 2, 4, 5, 7, 9, 8, 6};
    sort(S.begin(), S.end());

    if(binaray_search(N, S)) cout<< "found" << endl;
    else cout<<"not found" <<endl;
}

int main(){

    test();
    return 0;
}