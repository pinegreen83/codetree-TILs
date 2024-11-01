#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, cnt = 0;

void Backtrack(const vector<int>& want, const vector<int>& maxBill, vector<bool>& visited, int idx) {
    if(idx == n) {
        cnt++;
        return;
    }

    for(int i=0; i<n; i++) {
        if(visited[i]) continue;

        if(want[idx] <= maxBill[i]) {
            visited[i] = true;
            Backtrack(want, maxBill, visited, idx+1);
            visited[i] = false;

            break;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    vector<int> want(n);
    vector<int> maxBill(n);

    for(int i=0; i<n; i++) cin >> want[i];
    for(int i=0; i<n; i++) cin >> maxBill[i];

    sort(want.begin(), want.end());
    sort(maxBill.begin(), maxBill.end());

    vector<bool> visited(n, false);
    Backtrack(want, maxBill, visited, 0);
    cout << cnt;

    return 0;
}