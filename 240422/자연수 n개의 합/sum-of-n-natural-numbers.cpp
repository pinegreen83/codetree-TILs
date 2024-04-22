#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    long long s;
    cin >> s;

    long long left = 1, right = 1e9, ans = 1e9;
    while(left <= right)
    {
        long long mid = (left + right) / 2;
        if(mid*(mid+1) / 2 >= s) 
        {
            right = mid - 1;
            ans = min(ans, mid);
        }
        else left = mid + 1;
    }
    cout << ans;

    return 0;
}