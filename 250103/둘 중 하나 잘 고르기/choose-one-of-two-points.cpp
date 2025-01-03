#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
int red[201];
int blue[201];

int main() {
    cin >> N;

    for (int i = 0; i < 2 * N; i++) {
        cin >> red[i] >> blue[i];
    }

    // Write your code here!
    vector<vector<int>> dp(2 * N + 1, vector<int>(2 * N + 1, INT_MIN));
    dp[0][0] = 0;

    for(int i=1; i<=2 * N; i++) {
        for(int j=0; j<=i; j++) {
            if(j > 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + red[i-1]);
            }

            if(i - j > 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j] + blue[i-1]);
            }
        }
    }

    cout << dp[2 * N][N];

    return 0;
}
