#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    vector<int> sums(n+1, 0);
    for(int i=1; i<=n; i++) {
        sums[i] = sums[i-1] + nums[i-1];
    }

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;

        cout << sums[b] - sums[a-1] << '\n';
    }

    return 0;
}