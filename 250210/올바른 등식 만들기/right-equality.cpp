#include <iostream>
#include <vector>

using namespace std;

int N, M;
int nums[100];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    // Write your code here!
    vector<vector<long long>> dp(N, vector<long long>(41, 0));
    dp[0][nums[0] + 20] += 1;
    dp[0][-nums[0] + 20] += 1;

    for(int i=1; i<N; i++) {
        for(int j=-20; j<=20; j++) {
            if(dp[i-1][j+20] > 0) {
                int pnow = j + nums[i];
                if(pnow >= -20 && pnow <= 20) {
                    dp[i][pnow + 20] += dp[i-1][j + 20];
                }

                int mnow = j - nums[i];
                if(mnow >= -20 && mnow <= 20) {
                    dp[i][mnow + 20] += dp[i-1][j + 20];
                }
            }
        }
    }
    cout << dp[N-1][M+20];

    return 0;
}
