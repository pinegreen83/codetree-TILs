#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    int answer = 0;
    cin >> n >> k;
    vector<vector<int>> map(n+1, vector<int>(n+1));
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int blocks = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> map[i][j];
            if(!map[i][j]) blocks++;
        }
    }

    for(int i=0; i<k; i++)
    {
        int x, y;
        cin >> x >> y;
        if(answer == blocks) continue;
        vector<vector<int>> visited(n+1, vector<int>(n+1));
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = 1;
        while(!q.empty())
        {
            pair<int, int> temp = q.front();
            q.pop();
            if(!map[temp.first][temp.second])
            {
                map[temp.first][temp.second] = 2;
                answer++;
            }
            for(int j=0; j<4; j++)
            {
                int dirx = temp.first + dirs[j][0];
                int diry = temp.second + dirs[j][1];
                if(1 <= dirx && dirx <= n && 1 <= diry && diry <= n)
                {
                    if(!visited[dirx][diry] && map[dirx][diry] != 1)
                    {
                        visited[dirx][diry] = 1;
                        q.push({dirx, diry});
                    }
                }
            }
        }
    }

    cout << answer;

    return 0;
}