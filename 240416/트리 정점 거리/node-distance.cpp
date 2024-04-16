#include <iostream>
#include <vector>

#define MAX_N 1000

using namespace std;

vector<bool> visited;
vector<pair<int, int>> edges[MAX_N + 1];

void FindDist(int start, int end, int dist)
{
    if(start == end) 
    {
        cout << dist << "\n";
        return;
    }
    for(int i=0; i<edges[start].size(); i++)
    {
        int now = edges[start][i].first;
        int val = edges[start][i].second;
        if(!visited[now])
        {
            visited[now] = true;
            FindDist(now, end, dist+val);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    for(int i=1; i<n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }

    for(int i=0; i<m; i++)
    {
        int s, e;
        cin >> s >> e;
        visited = vector<bool>(n+1);
        visited[s] = true;
        FindDist(s, e, 0);
    }

    return 0;
}