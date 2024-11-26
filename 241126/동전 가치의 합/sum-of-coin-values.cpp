#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    vector<int> coins(n);
    vector<int> costs(m+1, 0);
    for(int i=0; i<n; i++) {
        cin >> coins[i];
    }

    costs[0] = 1;
    for(int j=0; j<n; j++) {
        for(int i=coins[j]; i<=m; i++) {
            costs[i] = (costs[i] + costs[i-coins[j]]) % 1000000007;
        }
    }
    cout << (costs[m] == 0 ? -1 : costs[m]);

    return 0;
}