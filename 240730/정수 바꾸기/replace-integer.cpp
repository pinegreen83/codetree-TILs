#include <iostream>
using namespace std;

int b, ans = 10000000;

void dfs(int now, int cnt)
{
    if(now >= b)
    {
        if(now == b) ans = min(ans, cnt);
        return;
    }
    int nowOne = now * 10 + 1;
    int nowTwo = now * 2;
    dfs(nowOne, cnt+1);
    dfs(nowTwo, cnt+1);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int a;
    cin >> a >> b;

    dfs(a, 0);
    cout << ans;

    return 0;
}