#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    long long s;
    cin >> s;

    long long left = 1, right = sqrt(s)*2 + 1, ans = 0;
    while(left <= right)
    {
        long long mid = (left + right) / 2;
        if(mid*(mid+1) / 2 > s) right = mid - 1;
        else 
        {
            left = mid + 1;
            ans = max(ans, mid);
        }
    }
    cout << ans;

    return 0;
}