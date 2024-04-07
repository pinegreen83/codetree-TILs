#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> edges[n+1];
    for(int i=0; i<m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }

    vector<int> nodes(n+1, INT_MAX);
    nodes[k] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, k));
    while(!pq.empty())
    {
        int minval = -pq.top().first;
        int minidx = pq.top().second;
        pq.pop();

        if(nodes[minidx] != minval) continue;

        for(int i=0; i<edges[minidx].size(); i++)
        {
            int idx = edges[minidx][i].first;
            int val = edges[minidx][i].second;

            if(nodes[idx] > minval + val)
            {
                nodes[idx] = minval + val;
                pq.push(make_pair(-nodes[idx], idx));
            }
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        cout << (nodes[i] == INT_MAX ? -1 : nodes[i]) << "\n";
    }

    return 0;
}