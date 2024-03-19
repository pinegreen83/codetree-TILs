#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int N, K, B;
    cin >> N >> K >> B;
    vector<int> nums(N+1);
    for(int i=0; i<B; i++)
    {
        int a;
        cin >> a;
        nums[a] = 1;
    }
    vector<int> dp(N+1);
    for(int i=1; i<=N; i++)
    {
        dp[i] = dp[i-1] + nums[i];
    }
    
    int ans = 100000;
    for(int i=K; i<=N; i++) ans = min(ans, dp[i] - dp[i-K]);
    cout << ans;

    return 0;
}