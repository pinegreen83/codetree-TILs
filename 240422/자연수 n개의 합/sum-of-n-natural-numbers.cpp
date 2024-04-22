#include <iostream>
#include <vector>

using namespace std;

long long s;
bool Numsum(long long mid)
{
    long long num = (mid*(mid+1)) / 2;
    return num <= s;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> s;

    long long left = 1, right = 1e9, ans = 0;
    while(left <= right)
    {
        long long mid = (left + right) / 2;
        if(!Numsum(mid)) right = mid - 1;
        else 
        {
            left = mid + 1;
            ans = max(ans, mid);
        }
    }
    cout << ans;

    return 0;
}