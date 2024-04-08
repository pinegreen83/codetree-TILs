#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> maps(n+1, vector<int>(n+1));
    for(int i=0; i<m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(maps[a][b] != 0)
        {
            maps[a][b] = min(maps[a][b], c);
        }
        else maps[a][b] = c;
        if(maps[b][a] != 0)
        {
            maps[b][a] = min(maps[b][a], c);
        }
        else maps[b][a] = c;
    }

    int start, end;
    cin >> start >> end;
    vector<int> nodes(n+1, 1e9);
    vector<bool> visited(n+1);
    nodes[start] = 0;
    for(int i=1; i<=n; i++)
    {
        int minidx = 0;
        for(int j=1; j<=n; j++)
        {
            if(visited[j]) continue;

            if(nodes[minidx] > nodes[j])
            {
                minidx = j;
            }
        }

        visited[minidx] = true;

        for(int j=1; j<=n; j++)
        {
            if(maps[minidx][j] == 0) continue;

            if(nodes[j] > nodes[minidx] + maps[minidx][j]) nodes[j] = nodes[minidx] + maps[minidx][j];
        }
    }
    cout << nodes[end];

    return 0;
}