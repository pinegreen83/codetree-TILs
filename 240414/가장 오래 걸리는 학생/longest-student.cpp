#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges[n+1];
    for(int i=0; i<m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }

    vector<int> nodes(n+1, 1e9);
    nodes[n] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, n));
    while(!pq.empty())
    {
        int val, idx;
        val = -pq.top().first;
        idx = pq.top().second;
        pq.pop();

        if(val != nodes[idx]) continue;

        for(int i=0; i<edges[idx].size(); i++)
        {
            int nidx, nval;
            nidx = edges[idx][i].first;
            nval = edges[idx][i].second;
            if(nodes[nidx] > val + nval)
            {
                nodes[nidx] = val + nval;
                pq.push(make_pair(-nodes[nidx], nidx));
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        ans = max(ans, nodes[i]);
    }
    cout << ans;


    return 0;
}