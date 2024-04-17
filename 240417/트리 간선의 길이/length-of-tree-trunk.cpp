#include <iostream>
#include <vector>
#define MAX_N 10000

using namespace std;

int start, ans = 0;
vector<bool> visited;
vector<pair<int, int>> edges[MAX_N+1];

void FindMax(int now, int dist)
{
    for(int i=0; i<edges[now].size(); i++)
    {
        int next = edges[now][i].first;
        int val = edges[now][i].second;
        if(visited[next]) continue;
        visited[next] = true;
        if(dist + val > ans)
        {
            ans = dist+val;
            start = next;
        }
        FindMax(next, dist+val);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }

    start = 1;
    visited = vector<bool>(MAX_N + 1);
    visited[start] = true;
    FindMax(start, 0);

    visited = vector<bool>(MAX_N + 1);
    visited[start] = true;
    FindMax(start, 0);
    cout << ans;

    return 0;
}