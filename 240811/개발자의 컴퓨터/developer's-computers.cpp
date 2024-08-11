#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    priority_queue<tuple<int,int,int>> pq;
    int use = 0, notuse = 0, s, t, b;
    for(int i=0; i<n; i++) {
        cin >> s >> t >> b;
        pq.push(make_tuple(-s, 1, b));
        pq.push(make_tuple(-t, -1, b));
    }

    while(!pq.empty()) {
        int t, type, b;
        tie(t, type, b) = pq.top();
        pq.pop();

        if(type == 1) {
            use += b;
            if(notuse <= b) notuse = 0;
            else notuse -= b;
        }
        else {
            use -= b;
            notuse += b;
        }
    }
    cout << use + notuse;

    return 0;
}