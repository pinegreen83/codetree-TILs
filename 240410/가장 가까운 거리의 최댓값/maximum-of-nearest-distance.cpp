#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> starts(3);
    cin >> starts[0] >> starts[1] >> starts[2];
    vector<pair<int, int>> edges[n+1];
    for(int i=0; i<m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }

    vector<vector<int>> nodes(3, vector<int>(n+1, INT_MAX));
    for(int i=0; i<3; i++)
    {
        int now = starts[i];
        priority_queue<pair<int, int>> pq;
        nodes[i][now] = 0;
        pq.push(make_pair(0, now));
        while(!pq.empty())
        {
            int dist = -pq.top().first;
            int temp = pq.top().second;
            pq.pop();

            if(dist != nodes[i][temp]) continue;

            for(int j=0; j<edges[temp].size(); j++)
            {
                int next = edges[temp][j].first;
                int val = edges[temp][j].second;
                if(nodes[i][next] > dist + val)
                {
                    nodes[i][next] = dist + val;
                    pq.push(make_pair(-nodes[i][next], next));
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        int temp = INT_MAX;
        for(int j=0; j<3; j++)
        {
            temp = min(temp, nodes[j][i]);
        }
        ans = max(temp, ans);
    }
    cout << ans;


    return 0;
}