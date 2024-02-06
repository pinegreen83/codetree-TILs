#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> nums = {1, 2, 5};

    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 1;
    dp[5] = 1;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(i-nums[j] >= 0)
            {
                dp[i] += dp[i-nums[j]] % 10007;
            }
        }
    }

    cout << dp[n] % 10007;

    return 0;
}