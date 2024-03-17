#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, a;
    cin >> n;
    priority_queue<int> pq;

    for(int i=1; i<=n; i++)
    {
        cin >> a;
        pq.push(-a);
        if(i < 3) cout << -1 << endl;
        else
        {
            int f, s, t;
            f = pq.top();
            pq.pop();
            s = pq.top();
            pq.pop();
            t = pq.top();
            pq.pop();

            cout << f * s * t * -1 << endl;
            pq.push(f);
            pq.push(s);
            pq.push(t);
        }
    }

    return 0;
}