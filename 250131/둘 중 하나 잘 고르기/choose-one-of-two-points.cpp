#include <iostream>

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
    int dp[101][101] = {0};

    for(int r=0; r<2 * N; r++) {
        for(int i=N; i>=0; i--) {
            for(int j=N; j>=0; j--) {
                if(i > 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j] + red[r]);
                }
                if(j > 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j-1] + blue[r]);
                }
            }
        }
    }
    cout << dp[N][N];

    return 0;
}
