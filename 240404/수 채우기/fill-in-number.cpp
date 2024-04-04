#include <iostream>
#include <climits>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, ans = INT_MAX, cnt = 0;
    cin >> n;

    while(n > 5)
    {
        n -= 5;
        cnt++;
        if(n % 2 == 0) ans = min(ans, cnt + n / 2);
    }
    cout << ans;

    return 0;
}