#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    priority_queue<tuple<int, int, int>> pq;

    for(int i=0; i<n; i++)
    {
        int x, y;
        cin >> x >> y;
        pq.push(make_tuple(-1*x*y, -x, -y));
    }

    for(int i=0; i<m; i++)
    {
        tuple<int, int, int> temp = pq.top();
        pq.pop();
        int a, b, c;
        tie(a, b, c) = temp;
        b -= 2;
        c -= 2;
        pq.push(make_tuple(-1*b*c, b, c));
    }

    tuple<int, int, int> temp = pq.top();
    int a, b, c;
    tie(a, b, c) = temp;
    cout << -b << " " << -c << endl;

    return 0;
}