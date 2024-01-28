#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<int>> visited(n, vector<int>(m));
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> shorts(n, vector<int>(m, 1000));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> map[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    shorts[0][0] = 0;
    while(!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int dirx = temp.first + dirs[i][0];
            int diry = temp.second + dirs[i][1];
            if(0 <= dirx && dirx < n && 0 <= diry && diry < m)
            {
                if(!visited[dirx][diry] && map[dirx][diry])
                {
                    shorts[dirx][diry] = min(shorts[dirx][diry], shorts[temp.first][temp.second]+1);
                    visited[dirx][diry] = 1;
                    q.push({dirx, diry});
                }
            }
        }
    }

    cout << shorts[n-1][m-1];

    return 0;
}