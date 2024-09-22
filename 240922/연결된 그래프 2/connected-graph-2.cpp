#include <iostream>
#include <vector>

using namespace std;

bool check;
int n, m, dist = 0;
vector<int> ans;
vector<bool> visited;
vector<vector<int>> map;

void DFS(int cnt, int now) {
    if(cnt >= dist) {
        check = true;
        if(cnt > dist) {
            ans.clear();
            dist = cnt;
        }
    }

    for(int i=0; i<map[now].size(); i++) {
        int next = map[now][i];

        if(!visited[next]) {
            visited[next] = true;
            DFS(cnt+1, next);
            visited[next] = false;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    int s, e;
    map = vector<vector<int>>(n+1);
    for(int i=0; i<n; i++) {
        cin >> s >> e;

        map[s].push_back(e);
    }

    for(int i=1; i<=n; i++) {
        visited = vector<bool>(n+1, false);
        visited[i] = true;

        check = false;
        DFS(0, i);
        if(check) {
            ans.push_back(i);
        }
    }

    for(auto& a : ans) cout << a << " ";

    return 0;
}