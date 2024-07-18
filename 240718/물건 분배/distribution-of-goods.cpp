#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;

    priority_queue<int> pq;
    for(int i=0; i<k; i++)
    {
        int a, b;
        cin >> a >> b;
        pq.push(a * b);
    }

    int ans = 0;
    while(!pq.empty())
    {
        n -= pq.top();
        ans++;
        pq.pop();
        if(n <= 0) break;
    }
    cout << ans;

    return 0;
}