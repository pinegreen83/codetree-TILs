#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> visit;
vector<vector<int>> map;
vector<vector<int>> dirs = {{1, 0}, {0, 1}};

void DFS(int x, int y)
{
    for(int i=0; i<2; i++)
    {
        int dirx = x + dirs[i][0];
        int diry = y + dirs[i][1];
        if(0 <= dirx && dirx < n && 0 <= diry && diry < m)
        {
            if(!visit[dirx][diry] && map[dirx][diry])
            {
                visit[dirx][diry] = 1;
                DFS(dirx, diry);
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    visit = vector<vector<int>>(n, vector<int>(m));

    int snake;
    for(int i=1; i<=n; i++)
    {
        vector<int> temp;
        for(int j=1; j<=m; j++)
        {
            cin >> snake;
            temp.push_back(snake);
        }
        map.push_back(temp);
    }

    visit[0][0] = 1;
    DFS(0, 0);

    cout << visit[n-1][m-1];

    return 0;
}