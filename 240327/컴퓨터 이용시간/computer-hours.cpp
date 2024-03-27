#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> places(n);
    vector<tuple<int, int, int>> computer;
    for(int i=0; i<n; i++)
    {
        int p, q;
        cin >> p >> q;
        computer.push_back(make_tuple(p, 1, i));
        computer.push_back(make_tuple(q, -1, i));
    }

    sort(computer.begin(), computer.end());
    priority_queue<int> pq;
    int now = 1;
    for(int i=0; i<n*2; i++)
    {
        int a, b, c;
        tie(a, b, c) = computer[i];
        if(b == 1)
        {
            if(pq.empty()) places[c] = now++;
            else
            {
                places[c] = -pq.top();
                pq.pop();
            }
        }
        else pq.push(-places[c]);
    }
    for(auto i : places) cout << i << " ";

    return 0;
}