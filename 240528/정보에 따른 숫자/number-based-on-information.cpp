#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, a, b;
    cin >> n >> a >> b;

    priority_queue<pair<int, string>> pq;
    pq.push(make_pair(-a, "Start"));
    pq.push(make_pair(-b, "End"));
    for(int i=0; i<n; i++)
    {
        string type;
        int num;
        cin >> type >> num;
        pq.push(make_pair(-num, type));
    }

    string now = pq.top().second, before;
    int nownum = -pq.top().first, beforenum, ans = 0;
    while(now != "Start")
    {
        now = pq.top().second;
        nownum = -pq.top().first;
        pq.pop();
    }
    bool check = false;
    pq.pop();
    while(now != "End")
    {
        before = now;
        beforenum = nownum;
        now = pq.top().second;
        nownum = -pq.top().first;
        int diff = nownum - beforenum - 1;
        // cout << before << " " << beforenum << " " << now << " " << nownum << " " << diff << "\n";
        // cout << "before ans : " << ans;
        if(now == "NS")
        {
            if(before == "S")
            {
                if(diff % 2 == 1) ans += (diff / 2) + 1;
                else ans += (diff / 2);
            }
            else check = false;
        }
        else if(now == "S")
        {
            if(before == "NS")
            {
                if(diff % 2 == 1) ans += (diff / 2) + 2;
                else ans += (diff / 2) + 1;
                check = true;
            }
            else if(before == "S")
            {
                ans += diff + 1;
            }
            else
            {
                ans += diff + 2;
                check = true;
            }
        }
        else
        {
            if(before == "S")
            {
                ans += diff + 1;
            }
        }
        pq.pop();
        // cout << " after ans : " << ans << "\n";
    }

    if(!pq.empty())
    {
        string next = pq.top().second;
        if(next == "S")
        {
            int nextnum = -pq.top().first;
            int nowbeforediff = nownum - beforenum;
            int nextnowdiff = nextnum - nownum;
            if(nextnowdiff >= nowbeforediff) ans++;
        }
    }
    cout << ans;

    return 0;
}