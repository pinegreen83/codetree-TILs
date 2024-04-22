#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<int> parents(n+1), dp(n+1);
    for(int i=1; i<=n; i++) cin >> parents[i];
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        dp[a] = dp[parents[a]] + b;
    }
    for(int i=1; i<=n; i++) cout << dp[i] << " ";

    return 0;
}