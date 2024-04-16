#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
vector<int> parents;
vector<vector<int>> child;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    parents = vector<int>(n+1);
    child = vector<vector<int>>(n+1);
    for(int i=1; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        parents[b] = a;
        child[a].push_back(b);
    }

    int ans = 0;
    for(int i=2; i<=n; i++)
    {
        if(child[i].size() > 0) continue;
        int cnt = 0, now = i;
        while(parents[now])
        {
            cnt++;
            now = parents[now];
        }
        ans += cnt;
    }
    cout << ans%2;

    return 0;
}