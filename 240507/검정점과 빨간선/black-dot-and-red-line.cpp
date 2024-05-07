#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> blacks(n);
    for(int i=0; i<n; i++) cin >> blacks[i];
    
    sort(blacks.begin(), blacks.end());

    vector<double> dp(n, 1'000'000'000);
    dp[0] = a;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            double r = (double) (blacks[i] - blacks[j]) / 2;
            double cost = a + b * r;
            if(j == 0) dp[i] = min(dp[i], cost);
            else dp[i] = min(dp[i], cost + dp[j-1]);
        }
    }
    printf("%.1f", dp[n-1]);

    return 0;
}