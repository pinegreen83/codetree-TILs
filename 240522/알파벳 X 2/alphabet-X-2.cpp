#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string alp;
    cin >> alp;

    priority_queue<pair<int, int>> pq;
    vector<int> check(26);
    for(int i=0; i<alp.size(); i++)
    {
        char now = alp[i];
        if(check[now-'A']) continue;
        for(int j=i+1; j<alp.size(); j++)
        {
            if(now == alp[j])
            {
                check[now-'A'] = 1;
                pq.push(make_pair(-i, j));
                // pq.push(make_pair(-i, 1));
                // pq.push(make_pair(-j, -1));
                break;
            }
        }
    }

    int cnt = 1, ans = 0, s = -pq.top().first, e = pq.top().second;
    pq.pop();
    while(!pq.empty())
    {
        if(-pq.top().first < e && e < pq.top().second) cnt++;
        else 
        {
            ans = max(ans, cnt);
            cnt = 1;
        }
        pq.pop();
    }
    cout << (ans * (ans - 1) / 2);

    return 0;
}