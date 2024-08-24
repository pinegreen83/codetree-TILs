#include <iostream>
using namespace std;

int n, ans = 0;

void backtrack(int now) {
    if(now >= n) {
        if(now == n) ans++;
        return;
    }

    for(int i=1; i<=3; i++) {
        backtrack(now+i);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    backtrack(0);
    cout << ans;

    return 0;
}