#include <iostream>
#include <vector>

using namespace std;

int n, m, dist = 0;
vector<int> ans;
vector<bool> visited;
vector<vector<int>> map;

int DFS(int cnt, int now) {
    for(int i=0; i<map[now].size(); i++) {
        int next = map[now][i];

        if(!visited[next]) {
            visited[next] = true;
            return DFS(cnt+1, next);
        }
    }
    
    return cnt;
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
        
        int now = DFS(0, i);
        if(now > dist) {
            dist = now;
            ans.clear();
            ans.push_back(i);
        }
        else if(now == dist) ans.push_back(i);
    }

    for(auto& a : ans) cout << a << " ";

    return 0;
}