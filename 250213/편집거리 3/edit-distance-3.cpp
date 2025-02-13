#include <iostream>
#include <vector>

using namespace std;

string A, B;

int main() {
    cin >> A;
    cin >> B;

    // Write your code here!
    int n = A.size(), m = B.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << ((n - dp[n][m]) + (m - dp[n][m]));

    return 0;
}
