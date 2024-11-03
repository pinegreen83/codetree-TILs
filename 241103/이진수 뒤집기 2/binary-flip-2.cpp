#include <iostream>
using namespace std;

void flip(string& now, int idx);
int count(string goal, string test);

int n;

int main() {
    // 여기에 코드를 작성해주세요.
    string a, b;
    cin >> n >> a >> b;

    int start1 = count(b, a);
    flip(a, 0);

    int start2 = count(b, a) + 1;

    if(start1 == 1e9 && start2 == 1e9) cout << -1;
    cout << (start1 < start2 ? start1 : start2);

    return 0;
}

void flip(string& now, int idx) {
    if(idx-1 >= 0) now[idx-1] = (now[idx-1] == '1' ? '0' : '1');
    if(idx+1 < n) now[idx+1] = (now[idx+1] == '1' ? '0' : '1');
    now[idx] = (now[idx] == '1' ? '0' : '1');
}

int count(string goal, string test) {
    int cnt = 0;
    for(int i=1; i<n; i++) {
        if(goal[i-1] == test[i-1]) continue;

        cnt++;
        flip(test, i);
    }

    if(goal[n-1] != test[n-1]) return 1e9;
    return cnt;
}