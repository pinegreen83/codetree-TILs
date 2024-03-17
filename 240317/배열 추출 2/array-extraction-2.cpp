#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    priority_queue<pair<int, int>> pq;
    int n, a;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> a;
        if(a == 0) 
        {
            if(pq.empty())
            {
                cout << 0 << endl;
            }
            else
            {
                cout << -pq.top().second << endl;
                pq.pop();
            }
        }
        else
        {
            if(a > 0) pq.push(make_pair(-a, -a));
            else pq.push(make_pair(a, -a));
        }
    }

    return 0;
}