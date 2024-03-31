#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    long s, ans = 0;
    cin >> s;

    long left = 1, right = sqrt(2 * s)+1;
    while (left <= right)
    {
        long mid = (left + right) / 2;
        if((mid * (mid+1) / 2) <= s)
        {
            left = mid + 1;
            ans = max(ans, mid);
        }
        else right = mid - 1;
    }
    cout << ans;

    return 0;
}