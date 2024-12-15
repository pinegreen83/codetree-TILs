#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> ans;
vector<vector<int>> graph;

bool backtrack(int now) {
    if(now > n) return true;

    for(int i=1; i<=4; i++) {
        bool valid = true;

        for(int next : graph[now]) {
            if(ans[next] == i) {
                valid = false;
                break;
            }
        }

        if(valid) {
            ans[now] = i;
            if(backtrack(now+1)) return true;
            ans[now] = 0;
        }
    }

    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    ans = vector<int>(n+1);
    graph = vector<vector<int>>(n+1);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].emplace_back(b);
        graph[b].emplace_back(a);    
    }

    backtrack(1);
    for(int i=1; i<=n; i++) cout << ans[i];

    return 0;
}