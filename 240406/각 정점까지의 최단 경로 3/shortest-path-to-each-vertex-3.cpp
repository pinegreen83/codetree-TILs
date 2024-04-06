#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n+1, vector<int>(n+1));
    for(int i=0; i<m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a][b] = c;
    }
    
    vector<int> graph(n+1, INT_MAX);
    vector<bool> visited(n+1, false);
    graph[1] = 0;
    for(int i=1; i<=n; i++)
    {
        int minidx = 0;
        for(int j=1; j<=n; j++)
        {
            if(visited[j]) continue;

            if(graph[minidx] > graph[j]) minidx = j;
        }

        visited[minidx] = true;

        for(int j=1; j<=n; j++)
        {
            if(edges[minidx][j])
            {
                if(graph[j] != INT_MAX)
                {
                    graph[j] = min(graph[j], graph[minidx] + edges[minidx][j]);
                }
                else graph[j] = graph[minidx] + edges[minidx][j];
            }
        }
    }
    for(int i=2; i<=n; i++) cout << (graph[i]==INT_MAX ? -1 : graph[i]) << "\n";

    return 0;
}