#include <iostream>
#include <vector>

#define MAXNUM 100000

using namespace std;

int start = 1, ans = 0;
vector<bool> visited;
vector<pair<int, int>> edges[MAXNUM+1];

void FindMax(int now, int cnt)
{
    for(int i=0; i<edges[now].size(); i++)
    {
        int next = edges[now][i].first;
        int val = edges[now][i].second;
        if(!visited[next])
        {
            visited[next] = true;
            if(cnt+val > ans)
            {
                ans = cnt+val;
                start = next;
            }
            FindMax(next, cnt+val);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    for(int i=1; i<n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }

    visited = vector<bool>(n+1);
    visited[start] = true;
    FindMax(start, 0);

    visited = vector<bool>(n+1);
    visited[start] = true;
    FindMax(start, 0);
    cout << ans;

    return 0;
}