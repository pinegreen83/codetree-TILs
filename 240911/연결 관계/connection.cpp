#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool dfs(const vector<vector<int>>& edges, vector<bool>& visited, int now, int dep) {
    if(dep == 4) {
        return true;
    }

    visited[now] = true;

    for(int next : edges[now]) {
        if(!visited[next]) {
            if(dfs(edges, visited, next, dep+1)) {
                return true;
            }
        }
    }

    visited[now] = false;
    return false;
}

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

    int ans = 0;
    for(int i=0; i<n; i++) {
        vector<bool> visited(n, false);
        if(dfs(edges, visited, i, 0)) {
            ans = 1;
            break;
        }
    }
    cout << ans;

    return 0;
}