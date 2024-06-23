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
        pq.pop();

        cnt += tb;
        if(tb == -1) left += 1;

        int right = n - cnt - left;
        int work = (h * left) + (g * cnt) + (c * right);
        ans = max(ans, work);
    }
    cout << ans;

    return 0;
}