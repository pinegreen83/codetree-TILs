#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, ans = 0;
    cin >> n;

    while(n > 1)
    {
        if(n % 3 == 0) n /= 3;
        else if(n % 2 == 0) n /= 2;
        else n -= 1;
        ans++;
    }
    cout << ans;

    return 0;
}