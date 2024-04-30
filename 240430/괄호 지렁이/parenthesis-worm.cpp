#include <iostream>
#include <vector>

using namespace std;

int n, ans = 0;
vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<bool>> visited;
vector<vector<char>> map;

void DFS(int x, int y, int left, int right)
{
    if(left == right) 
    {
        ans = max(ans, left+right);
        return;
    }
    for(int i=0; i<4; i++)
    {
        int dirx = x + dirs[i][0];
        int diry = y + dirs[i][1];
        if(0 <= dirx && dirx < n && 0 <= diry && diry < n)
        {
            if(!visited[dirx][diry])
            {
                if(map[dirx][diry] == '(' && right == 0) 
                {
                    visited[dirx][diry] = true;
                    DFS(dirx, diry, left+1, right);
                    visited[dirx][diry] = false;
                }
                else if(map[dirx][diry] == ')') 
                {
                    visited[dirx][diry] = true;
                    DFS(dirx, diry, left, right+1);
                    visited[dirx][diry] = false;
                }
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    map = vector<vector<char>>(n, vector<char>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++) cin >> map[i][j];
    }

    if(map[0][0] == '(')
    {
        visited = vector<vector<bool>>(n, vector<bool>(n));
        visited[0][0] = true;
        DFS(0, 0, 1, 0);
        cout << ans;
    }
    else cout << ans;

    return 0;
}