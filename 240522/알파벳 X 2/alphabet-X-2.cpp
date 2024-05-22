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

    int ans = 0, qsize = pq.size();
    for(int i=0; i<qsize; i++)
    {
        int s = -pq.top().first, e = pq.top().second;
        pq.pop();
        priority_queue<pair<int, int>> temp;
        while(!pq.empty())
        {
            int a = -pq.top().first, b = pq.top().second;
            pq.pop();
            if(a < e && e < b) ans++;
            temp.push(make_pair(-a, b));
        }
        pq = temp;
    }
    cout << ans;

    return 0;
}