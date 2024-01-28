#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    int answer = 0;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<bool>> visited(n, vector<bool>(m));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> map[i][j];
        }
    }

    queue<vector<int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    while(!q.empty())
    {
        vector<int> temp = q.front();
        q.pop();
        if(temp[0] == n-1 && temp[1] == m-1)
        {
            answer = 1;
            break;
        }
        for(int i=0; i<4; i++)
        {
            int dirx = temp[0] + dir[i][0];
            int diry = temp[1] + dir[i][1];
            if(0 <= dirx && dirx < n && 0 <= diry && diry < m)
            {
                if(!visited[dirx][diry] && map[dirx][diry])
                {
                    visited[dirx][diry] = 1;
                    q.push({dirx, diry});
                }
            }
        }
    }

    cout << answer;

    return 0;
}