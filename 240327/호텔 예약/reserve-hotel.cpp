#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> hotel(n);
    vector<tuple<int, int, int>> reser;
    for(int i=0; i<n; i++)
    {
        int s, e;
        cin >> s >> e;
        reser.push_back(make_tuple(s, 1, i));
        reser.push_back(make_tuple(e, -1, i));
    }

    sort(reser.begin(), reser.end());
    int now = 0;
    priority_queue<int> pq;
    for(int i=0; i<n*2; i++)
    {
        int a, b, c;
        tie(a, b, c) = reser[i];
        if(b == 1)
        {
            if(pq.empty()) hotel[c] = now++;
            else
            {
                hotel[c] = -pq.top();
                pq.pop();
            }
        }
        else pq.push(-hotel[c]);
    }
    cout << now;

    return 0;
}