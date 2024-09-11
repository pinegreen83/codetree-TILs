#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, s, e;
    cin >> n >> m;

    vector<vector<int>> edges(n);
    for(int i=0; i<m; i++) {
        cin >> s >> e;

        edges[s].push_back(e);
        edges[e].push_back(s);
    }

    int ans = 0, cnt, now;
    bool check = false;
    for(int i=0; i<n; i++) {
        if(check) {
            ans = 1;
            break;
        }
        bool visited[n] = {};
        queue<pair<int, int>> q;
        q.push({i, 1});
        visited[i] = true;
        while(!q.empty()) {
            now = q.front().first;
            cnt = q.front().second;
            q.pop();

            if(cnt == 5) {
                check = true;
                break;
            }

            for(int j=0; j<edges[now].size(); j++) {
                if(!visited[edges[now][j]]) {
                    visited[edges[now][j]]  = true;
                    q.push({edges[now][j], cnt+1});
                }
            }
        }
    }
    cout << ans;

    return 0;
}