#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, a;
    cin >> n;
    priority_queue<int> pq;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        if(a == 0) 
        {
            if(pq.empty()) cout << 0 << endl;
            else
            {
                cout << -1 * pq.top() << endl;
                pq.pop();
            }
        }
        else pq.push(-1 * a);
    }
    return 0;
}