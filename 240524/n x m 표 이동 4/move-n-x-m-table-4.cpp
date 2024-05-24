#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<int>> map(n+1, vector<int>(m+1));
    priority_queue<pair<int, int>> pq;
    for(int i=0; i<a; i++)
    {
        int r, c;
        cin >> r >> c;
        pq.push(make_pair(-r, -c));
    }
    pq.push(make_pair(-n, -m));
    for(int i=0; i<b; i++)
    {
        int r, c;
        cin >> r >> c;
        map[r][c] = -1;
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1));
    int s = 1, e = 1;
    dp[1][1] = 1;
    while(!pq.empty())
    {
        int r = -pq.top().first;
        int c = -pq.top().second;
        for(int i=s; i<=r; i++)
        {
            for(int j=e; j<=c; j++)
            {
                if(i == s && j == e) continue;
                if(map[i][j] == -1) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        pq.pop();
        s = r;
        e = c;
    }

    cout << dp[n][m];

    return 0;
}