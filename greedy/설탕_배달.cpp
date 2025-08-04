#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> v;

int main() {
    cin >> N;

    //5, 3의 배수 or 어케 계산을 할 수 있는거지? 아 일단 늘리고 다시 하나? 안되면?
    //큰 숫자 개수를 줄이는 방식으로.
    int cnt5 = N / 5, cnt3 = N / 3;
    int calc = N;
    do {
        if (cnt5 < 0) cnt5 = 0;
        calc -= 5*(cnt5);
        cnt3 = calc / 3;
        calc %= 3;

        if (calc == 0) {
            v.push_back(cnt5 + cnt3);
            calc = N;
        }
        else {
            v.push_back(-1);
            calc = N;
        }
    } while (cnt5--);

    int min = 101010;
    for (int res : v) {
        if (res < min && res != -1) min = res;
    }
    if (min == 101010) min = -1;

    cout << min << '\n';
}