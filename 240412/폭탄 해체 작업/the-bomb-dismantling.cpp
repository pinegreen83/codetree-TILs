#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    priority_queue<pair<int, int>> pq;
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        pq.push(make_pair(-b, a));
    }

    int time = 0, ans = 0;
    while(!pq.empty())
    {
        if(time < -pq.top().first)
        {
            int now = -pq.top().first;
            int val = pq.top().second;
            pq.pop();
            if(val < pq.top().second)
            {
                ans += pq.top().second;
                pq.pop();
            }
            else ans += val;
        }
        time++;
        while(time == -pq.top().first) pq.pop();
    }
    cout << ans;

    return 0;
}