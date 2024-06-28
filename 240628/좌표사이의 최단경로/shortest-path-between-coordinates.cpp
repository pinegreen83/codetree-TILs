#include <iostream>
#include <cmath>

using namespace std;

int a, b, diff, dir, ans = 0;
int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int cnt, int x, int y)
{
    if(y > x) return;
    if(cnt == diff)
    {
        if(x == b && y == b) ans++;
        return;
    }
    for(int i=0; i<2; i++)
    {
        dfs(cnt+1, x+dirs[dir+i][0], y+dirs[dir+i][1]);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;
    if(a-b > 0) dir = 2;
    else dir = 0;

    diff = abs(a-b) * 2;
    dfs(0, a, a);
    cout << ans;

    return 0;
}