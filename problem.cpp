#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

class Student{ 
public:
    pair<int, int> name;
    bool vaccinated;
};
vector<Student> st = {
    {{1, 3}, true},
    {{2, 2}, false}, 
    {{3, 3}, true}
};

bool comparator(Student& a, Student& b){
    return a.name.first < b.name.first;
}

bool binary_search(int N, vector<Student>& st){
    sort(st.begin(), st.end(), comparator);

    auto start = st.begin();
    auto end = st.end();

    while(true){
        auto len = distance(start, end);
        auto mid = start + floor(len / 2);

        if(mid->name.first == N) {
            if (mid->vaccinated == true) return false;
            else return true;
        }
        else if (N < mid->name.first) end = mid;
        else start = mid;

        if(len == 1) return true;
    }
}

void print(){
    for(Student& i : st){
        cout<<"("<<i.name.first<<" "<<i.name.second<<") ";
        if(binary_search(i.name.first, st)) cout<<"학생은 예방 접종이 필요합니다."<<endl;
        else cout<<"학생은 예방 접종이 필요없습니다." <<endl;
    }
}

int main(){
    print();

    return 0;
}