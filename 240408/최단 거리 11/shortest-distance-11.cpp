#include <iostream>
#include <vector>
#include <climits>

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
        maps[a][b] = c;
        maps[b][a] = c;
    }

    int start, end;
    cin >> start >> end;
    vector<int> nodes(n+1, INT_MAX);
    vector<bool> visited(n+1);
    nodes[end] = 0;
    for(int i=1; i<=n; i++)
    {
        int minidx = 0;
        for(int j=1; j<=n; j++)
        {
            if(visited[j]) continue;

            if(nodes[minidx] > nodes[j]) minidx = j; 
        }

        visited[minidx] = true;

        for(int j=1; j<=n; j++)
        {
            if(maps[minidx][j] == 0) continue;

            if(nodes[j] > nodes[minidx] + maps[minidx][j])
            {
                nodes[j] = nodes[minidx] + maps[minidx][j];
            }
        }
    }

    cout << nodes[start] << "\n";
    cout << start << " ";
    while(start != end)
    {
        for(int i=1; i<=n; i++)
        {
            if(maps[i][start] == 0) continue;

            if(nodes[i]+maps[i][start] == nodes[start]) 
            {
                start = i;
                break;
            }
        }
        cout << start << " ";
    }

    return 0;
}