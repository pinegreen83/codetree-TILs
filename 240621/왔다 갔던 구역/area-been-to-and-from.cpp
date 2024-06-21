#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    priority_queue<pair<int, int>> pq;
    int start = 0, next;
    for(int i=0; i<n; i++)
    {
        int m;
        char d;
        cin >> m >> d;

        if(d == 'R') next = start + m;
        else next = start - m;

        if(start < next)
        {
            pq.push(make_pair(-start, 1));
            pq.push(make_pair(-next, -1));
        }
        else
        {
            pq.push(make_pair(-start, -1));
            pq.push(make_pair(-next, 1));
        }
        start = next;
    }

    int point, cnt = 0, ans = 0;
    while(!pq.empty())
    {
        int s = pq.top().first, c = pq.top().second;
        pq.pop();
        if(c == 1)
        {
            cnt++;
            if(cnt == 2) point = -s;
        }
        else
        {
            if(cnt == 2) ans += (-s - point);
            cnt--;
        }
    }
    cout << ans;

    return 0;
}