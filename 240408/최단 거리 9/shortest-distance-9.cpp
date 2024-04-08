#include <iostream>
#include <vector>
#include <queue>
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
        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }

    int start, end;
    cin >> start >> end;

    vector<int> nodes(n+1, INT_MAX);
    vector<int> path(n+1);
    priority_queue<pair<int, int>> pq;
    nodes[start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty())
    {
        int minval = pq.top().first;
        int minidx = pq.top().second;
        pq.pop();

        if(-minval != nodes[minidx]) continue;

        for(int i=0; i<edges[minidx].size(); i++)
        {
            int idx = edges[minidx][i].first;
            int val = edges[minidx][i].second;

            if(nodes[idx] > -minval+val)
            {
                nodes[idx] = -minval+val;
                path[idx] = minidx;
                pq.push(make_pair(-nodes[idx], idx));
            }
        }
    }
    cout << nodes[end] << "\n";
    vector<int> endpath;
    endpath.push_back(end);
    while(path[end] != 0)
    {
        endpath.push_back(path[end]);
        end = path[end];
    }
    for(int i=endpath.size()-1; i>=0; i--) cout << endpath[i] << " ";

    return 0;
}