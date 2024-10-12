#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, start;
vector<bool> visited;
vector<vector<int>> edges;

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int now = q.front();
        cout << now << " ";
        q.pop();

        for(auto& edge : edges[now]) {
            if(!visited[edge]) {
                visited[edge] = true;
                q.push(edge);
            }
        }
    }
}

void DFS(int now) {
    cout << now << " ";
    visited[now] = true;

    for(auto& edge : edges[now]) {
        if(!visited[edge]) {
            DFS(edge);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> start;

    edges = vector<vector<int>>(n+1);
    for(int i=0; i<m; i++) {
        int s, e;
        cin >> s >> e;
        edges[s].push_back(e);
        edges[e].push_back(s);
    }

    for(auto& edge : edges) {
        sort(edge.begin(), edge.end());
    }

    visited = vector<bool>(n+1, false);
    DFS(start);
    cout << "\n";
    visited = vector<bool>(n+1, false);
    BFS(start);

    return 0;
}