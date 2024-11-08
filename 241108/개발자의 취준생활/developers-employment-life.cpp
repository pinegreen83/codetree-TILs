#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> dev, com;
vector<bool> visited;
int ans = 0;

void Backtrack(int idx) {
    if(idx == n) {
        ans++;
        return;
    }

    for(int i=0; i<n; i++) {
        if(!visited[i] && dev[idx] <= com[i]) {
            visited[i] = true;
            Backtrack(idx+1);
            visited[i] = false;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    dev = vector<int>(n);
    com = vector<int>(n);
    visited = vector<bool>(n);

    for(int i=0; i<n; i++) cin >> dev[i];
    for(int i=0; i<n; i++) cin >> com[i];

    Backtrack(0);
    cout << ans;

    return 0;
}