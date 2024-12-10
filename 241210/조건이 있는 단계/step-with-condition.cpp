#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<int> level(n+1, 0);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        level[b]++;
    }

    vector<int> ans(n+1, 0);
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(level[i] == 0) {
            ans[i] = 1;
            q.push(i);
        }
    }

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(int next : graph[now]) {
            level[next]--;
            if(level[next] == 0) {
                q.push(next);
                ans[next] = ans[now] + 1;
            }
        }
    }

    for(int i=1; i<=n; i++) cout << ans[i] << " ";

    return 0;
}