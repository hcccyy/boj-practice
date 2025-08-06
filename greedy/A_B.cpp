#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
    int ans=1, A;
    string  B;
    cin>>A>>B;

    while(A != stoi(B)){
        int idx = B.size()-1;
        char last = B.at(idx);

        if(last == '1') {
            B.erase(idx, 1);
            ans++;
        }
        else if(stoi(B)%2){
            ans = -1;
            break;
        }
        else {
            B = to_string(stoi(B)/2);
            ans++;
        }

        if(A > stoi(B)){
            ans = -1;
            break;
        }
    }
    cout<<ans<<'\n';
}