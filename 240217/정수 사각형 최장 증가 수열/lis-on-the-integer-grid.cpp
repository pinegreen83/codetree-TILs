#include <iostream>
#include <vector>

using namespace std;

int n, answer;
vector<vector<int>> map;
vector<vector<int>> dp;
vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool IsRange(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < n;
}

void dfs(int x, int y)
{
    dp[x][y] = 1;
    int maxmove = 0;
    for(int i=0; i<4; i++)
    {
        int dirx = x + dirs[i][0];
        int diry = y + dirs[i][1];
        if(IsRange(dirx, diry) && map[x][y] < map[dirx][diry])
        {
            if(!dp[dirx][diry]) dfs(dirx, diry);
            if(dp[dirx][diry] > maxmove) maxmove = dp[dirx][diry];
        }
    }
    dp[x][y] += maxmove;
    if(dp[x][y] > answer) answer = dp[x][y];
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    answer = 0;
    map = vector<vector<int>>(n, vector<int>(n));
    dp = vector<vector<int>>(n, vector<int>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!dp[i][j])
            {
                dfs(i, j);
            }
        }
    }

    cout << answer;

    return 0;
}