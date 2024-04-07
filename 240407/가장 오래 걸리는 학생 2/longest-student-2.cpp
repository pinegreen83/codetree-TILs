#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

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
        edges[b].push_back(make_pair(a, c));
    }

    vector<int> nodes(n+1, INT_MAX);
    priority_queue<pair<int, int>> pq;
    nodes[n] = 0;
    pq.push(make_pair(0, n));
    while(!pq.empty())
    {
        int minval, minidx;
        tie(minval, minidx) = pq.top();
        pq.pop();

        if(-minval != nodes[minidx]) continue;

        for(int i=0; i<edges[minidx].size(); i++)
        {
            int idx, val;
            tie(idx, val) = edges[minidx][i];

            if(nodes[idx] > -minval+val)
            {
                nodes[idx] = -minval+val;
                pq.push(make_pair(-nodes[idx], idx));
            }
        }
    }
    int maxnum = 0;
    for(int i=1; i<=n; i++) maxnum = max(maxnum, nodes[i]);
    cout << maxnum;

    return 0;
}