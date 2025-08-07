#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){
    string equa;
    vector<int> parts;
    vector<int> calc;
    cin>>equa;

    int num;
    stringstream ss(equa);
    while( ss >> num ) parts.push_back(num);

    int sum=0, i=0;
    while(i < parts.size()){
        if(parts[i]<0){
            sum += parts[i++];
            while(i < parts.size()){
                if(parts[i]<0) break;
                else sum -= parts[i++];
            }
            calc.push_back(sum);
            sum=0;
        }
        else calc.push_back(parts[i++]);
    }

    int ans=0;
    for(auto i: calc) ans += i;
    cout<<ans;
}