#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    priority_queue<pair<int, int>> pq;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;

        pq.push({-a, 1});
        pq.push({-b, -1});
    }

    int ans = 0, check = 0;
    while(!pq.empty()) {
        if(pq.top().second == 1) {
            check++;
            ans = max(ans, check);
        }
        else check--;
        pq.pop();
    }
    cout << ans;

    return 0;
}