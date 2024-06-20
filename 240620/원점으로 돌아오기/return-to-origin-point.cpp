#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, ans = 0;
vector<vector<int>> map;
vector<bool> visited;

void backtrack(int cnt, int x, int y, int dirx, int diry)
{
    if(cnt == n)
    {
        if(x == 0 || y == 0) 
        {
            int dx = 0 - x;
            int dy = 0 - y;
            dx = dx != 0 ? dx/abs(dx) : 0;
            dy = dy != 0 ? dy/abs(dy) : 0;
            if(dx != dirx || dy != diry) ans++;
        }
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            if(x == map[i][0] || y == map[i][1]) 
            {
                int dx = map[i][0] - x;
                int dy = map[i][1] - y;
                dx = dx != 0 ? dx/abs(dx) : 0;
                dy = dy != 0 ? dy/abs(dy) : 0;
                if(dx != dirx || dy != diry)
                {
                    visited[i] = true;
                    backtrack(cnt+1, map[i][0], map[i][1], dx, dy);
                    visited[i] = false;
                }
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;
    map = vector<vector<int>>(n, vector<int>(2));
    for(int i=0; i<n; i++)
    {
        cin >> map[i][0] >> map[i][1];
    }
    visited = vector<bool>(n);
    backtrack(0, 0, 0, 0, 0);
    cout << ans;

    return 0;
}