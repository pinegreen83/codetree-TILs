#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, answer;
vector<vector<int>> map;
vector<vector<int>> dp;

void move(int x, int y)
{
    for(int i=x+1; i<n; i++)
    {
        for(int j=y+1; j<m; j++)
        {
            if(map[x][y] < map[i][j])
            {
                dp[i][j] = max(dp[i][j], dp[x][y]+1);
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    answer = 0;

    map = vector<vector<int>>(n, vector<int>(m));
    dp = vector<vector<int>>(n, vector<int>(m, -1));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> map[i][j];
        }
    }

    dp[0][0] = 1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(dp[i][j] != -1) move(i, j);
            answer = max(answer, dp[i][j]);
        }
    }

    cout << answer;

    return 0;
}