#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    int cnt = 0, now = n, ten, temp;
    while(true) {
        if(cnt != 0)
        {
            if(now == n) break;
        }
        cnt++;
        ten = now % 10;
        temp = (now / 10) + (now % 10);
        now = (ten * 10) + (temp % 10);
    }
    cout << cnt;

    return 0;
}