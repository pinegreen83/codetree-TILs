#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, a;
    cin >> n >> m;
    priority_queue<int> pq;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        pq.push(a);
    }

    for(int i=0; i<m; i++)
    {
        int now = pq.top();
        pq.pop();
        pq.push(now-1);
    }
    cout << pq.top();

    return 0;
}