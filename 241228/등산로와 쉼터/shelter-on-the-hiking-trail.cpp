#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    vector<int> rests(n+1);
    for(int i=1; i<=n; i++) cin >> rests[i];

    vector<int> levels(n+1, 0);
    vector<vector<int>> edges(n+1);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;

        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<int> ans(n+1, 1);
    vector<pair<int, int>> nodes;
    for(int i=1; i<=n; i++) {
        nodes.emplace_back(rests[i], i);
    }
    sort(nodes.rbegin(), nodes.rend());

    for(const auto& node : nodes) {
        int now = node.second;

        for(int next : edges[now]) {
            if(rests[now] > rests[next]) {
                ans[next] = max(ans[next], ans[now] + 1);
            }
        }
    }

    for(int i=1; i<=n; i++) cout << ans[i] << "\n";

    return 0;
}