#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> nums(n+1, 1), primes;
    for(int i=2; i*i<=n; i++)
    {
        if(!nums[i]) continue;
        for(int j=i+i; j<=n; j+=i)
        {
            nums[j] = 0;
        }
    }

    for(int i=2; i<=n; i++)
    {
        if(nums[i]) primes.push_back(i);
    }

    vector<int> dp(n+1);
    dp[0] = 1;
    for(int prime : primes)
    {
        for(int i=prime; i<=n; i++)
        {
            dp[i] = (dp[i] + dp[i-prime]) % 1000000007;
        }
    }
    cout << dp[n];


    return 0;
}