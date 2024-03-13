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
        pq.push(a);
    }

    while(pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        if(a-b != 0) pq.push(a-b);
    }
    cout << pq.top();

    return 0;
}