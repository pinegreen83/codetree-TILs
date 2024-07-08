#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    
    priority_queue<int> pq;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        pq.push(-a);
    }

    while(!pq.empty())
    {
        int now = -pq.top();
        if(now <= m) m++;
        else break;

        pq.pop();
    }
    cout << m;

    return 0;
}