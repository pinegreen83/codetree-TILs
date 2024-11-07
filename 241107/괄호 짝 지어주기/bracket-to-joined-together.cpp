#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string now;
    cin >> now;

    int cnt = 0, ans = 0;
    for(auto c : now) {
        if(c == '(') cnt++;
        else cnt--;

        if(cnt < 0) {
            ans++;
            cnt = 1;
        }
    }
    ans += cnt / 2;
    cout << ans;

    return 0;
}