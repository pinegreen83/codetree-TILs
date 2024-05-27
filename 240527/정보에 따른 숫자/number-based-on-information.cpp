#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, a, b;
    cin >> n >> a >> b;

    priority_queue<pair<int, string>> pq;
    for(int i=0; i<n; i++)
    {
        string type;
        int num;
        cin >> type >> num;
        pq.push(make_pair(-num, type));
    }

    string now = pq.top().second, before;
    int nownum = -pq.top().first, beforenum, ans = 0;
    pq.pop();
    while(!pq.empty())
    {
        before = now;
        beforenum = nownum;
        now = pq.top().second;
        nownum = -pq.top().first;
        if(before == "NS" || now == "NS")
        {
            int diff = nownum - beforenum - 1;
            if(diff % 2 == 1) ans += diff / 2 + 2;
            else ans += diff / 2 + 1;
        }
        else if(before == "S" && now == "S")
        {
            int diff = nownum - beforenum;
            ans += diff;
        }
        pq.pop();
    }
    cout << ans;

    return 0;
}