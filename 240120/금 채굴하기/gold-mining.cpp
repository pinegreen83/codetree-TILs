#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n;
int m;
vector<vector<int>> map;
vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<int> bfs(int x, int y, int k)
{
    int answer = 0;
    queue<vector<int>> q;
    vector<vector<int>> visited(n, vector<int>(n));
    visited[x][y] = 1;
    q.push({x, y, 0});
    while(!q.empty())
    {
        int qx = q.front()[0];
        int qy = q.front()[1];
        int cnt = q.front()[2];
        q.pop();
        if(map[qx][qy]) answer += m;
        for(int i=0; i<4; i++)
        {
            int dx = qx + dirs[i][0];
            int dy = qy + dirs[i][1];
            if(0 <= dx and dx < n and 0 <= dy and dy < n)
            {
                if(cnt < k and !visited[dx][dy])
                {
                    q.push({dx, dy, cnt+1});
                    visited[dx][dy] = 1;
                }
            }
        }
    }
    return {answer - (k*k + (k+1) * (k+1)), answer/m};
}

int main() {
    // 여기에 코드를 작성해주세요.
    int answer = 0;
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        for(int j=0; j<n; j++)
        {
            int a;
            cin >> a;
            temp.push_back(a);
        }
        map.push_back(temp);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                vector<int> bfsans = bfs(i, j, k);
                if(bfsans[0] > 0)
                {
                    answer = max(answer, bfsans[1]);
                }
            }
        }
    }

    cout << answer;

    return 0;
}