#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cin >> map[i][j];
    }

    vector<vector<int>> dp1(n, vector<int>(m, 0));
    vector<vector<int>> dp2(n, vector<int>(m, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j] == 1) {
                int cnt = 1;
                for(int k=j+1; k<m; k++) {
                    if(map[i][k] == 1) cnt++;
                    else break;
                }
                dp1[i][j] = cnt;
            }

            if(map[j][i] == 1) {
                int cnt = 1;
                for(int k=j+1; k<n; k++) {
                    if(map[k][i] == 1) cnt++;
                    else break;
                }
                dp2[j][i] = cnt;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(dp1[i][j] >= dp2[i][j]) {
                ans = max(ans, dp2[i][j] * dp2[i][j]);
            }
            else if(dp1[i][j] == dp2[i][j]) {
                ans = max(ans, dp1[i][j] * dp2[i][j]);
            }
            else if(dp1[i][j] <= dp2[i][j]) {
                ans = max(ans, dp1[i][j] * dp1[i][j]);
            }
        }
    }
    cout << ans;

    return 0;
}