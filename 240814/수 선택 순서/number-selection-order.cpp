#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, x, now;
    cin >> n >> x;

    priority_queue<int> pq;
    queue<pair<int, int>> nums;
    for(int i=0; i<n; i++)
    {
        cin >> now;
        pq.push(now);
        nums.push({i, now});
    }

    int cnt = 0;
    while(!nums.empty())
    {
        int idx = nums.front().first;
        int num = nums.front().second;
        nums.pop();
        if(num == pq.top())
        {
            cnt++;
            if(idx == x)
            {
                cout << cnt;
                break;
            }
            pq.pop();
        }
        else nums.push({idx, num});
    }

    return 0;
}