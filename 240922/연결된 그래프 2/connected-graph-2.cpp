#include <iostream>
#include <vector>

using namespace std;

bool check;
int n, m, cnt;
vector<int> counts;
vector<bool> visited;
vector<vector<int>> map;

void DFS(int now) {
    for(int i=0; i<map[now].size(); i++) {
        int next = map[now][i];

        if(!visited[next]) {
            visited[next] = true;
            cnt++;
            DFS(next);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    int s, e;
    map = vector<vector<int>>(n+1);
    for(int i=0; i<m; i++) {
        cin >> s >> e;

        map[s].push_back(e);
    }

    for(int i=1; i<=n; i++) {
        visited = vector<bool>(n+1, false);
        visited[i] = true;

        cnt = 0;
        DFS(i);
        counts.push_back(cnt);
    }

    int dist = 0;
    vector<int> ans;
    for(int i=0; i<n; i++) {
        if(dist < counts[i]) {
            dist = counts[i];
            ans.clear();
            ans.push_back(i+1);
        }
        else if(dist == counts[i]) ans.push_back(i+1);
    }

    for(auto& a : ans) cout << a << " ";

    return 0;
}