#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<long long> prefixSum(n+1);
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i-1] + nums[i-1];
    }

    long long maxSum = -100000000;
    for (int i = k + 1; i <= n; i++) {
        for (int j = 0; j <= i - k; j++) {
            maxSum = max(maxSum, prefixSum[i] - prefixSum[j]);
        }
    }
    cout << maxSum << endl;

    return 0;
}