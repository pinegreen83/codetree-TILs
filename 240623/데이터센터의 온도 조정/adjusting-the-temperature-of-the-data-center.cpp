#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, c, g, h;
    cin >> n >> c >> g >> h;

    priority_queue<pair<int, int>> pq;
    for(int i=0; i<n; i++)
    {
        int ta, tb;
        cin >> ta >> tb;
        pq.push({-ta, 1});
        pq.push({-tb, -1});
    }

    int cnt = 0, maxcnt, ans = 0, left = 0;
    while(!pq.empty())
    {
        int ta = -pq.top().first;
        int tb = pq.top().second;
        cnt += tb;
        if(tb == 1)
        {
            int right = n - cnt - left;
            int work = (c * left) + (g * cnt) + (h * right);
            ans = max(ans, work);
        }
        else left += 1;
        pq.pop();
    }
    cout << ans;

    return 0;
}