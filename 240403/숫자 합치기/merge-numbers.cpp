#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    priority_queue<int> pq;
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        pq.push(-a);
    }

    int ans = 0;
    while(pq.size() > 1)
    {
        int fir = pq.top();
        pq.pop();
        int sec = pq.top();
        pq.pop();
        ans += (fir + sec) * -1;
        pq.push(fir + sec);
    }
    cout << ans;

    return 0;
}