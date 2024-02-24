#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n, k, u, d, answer, comp;
vector<vector<int>> map;
vector<vector<bool>> visit;
vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<pair<int, int>> comb;

void Initialize()
{
    comp = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            visit[i][j] = false;
        }
    }
}

bool isin(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < n;
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visit[x][y] = true;
    comp++;
    while(!q.empty())
    {
        int nx = q.front().first;
        int ny = q.front().second;
        int now = map[nx][ny];
        q.pop();
        for(int i=0; i<4; i++)
        {
            int dx = nx + dirs[i][0];
            int dy = ny + dirs[i][1];
            if(isin(dx, dy))
            {
                int diff = abs(now - map[dx][dy]);
                if(!visit[dx][dy] && u <= diff && diff <= d)
                {
                    q.push(make_pair(dx, dy));
                    visit[dx][dy] = true;
                    comp++;
                }
            }
        }
    }
}

void dfs(int cnt)
{
    if(cnt == k)
    {
        Initialize();

        for(auto c : comb)
        {
            bfs(c.first, c.second);
        }

        answer = max(answer, comp);
        return;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            comb.push_back(make_pair(i, j));
            dfs(cnt+1);
            comb.pop_back();
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    answer = 0;
    cin >> n >> k >> u >> d;
    map = vector<vector<int>>(n, vector<int>(n));
    visit = vector<vector<bool>>(n, vector<bool>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> map[i][j];
        }
    }

    dfs(0);

    cout << answer;

    return 0;
}