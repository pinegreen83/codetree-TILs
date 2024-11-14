#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<int> nums;
long long dp[11][11][11][11][11][6][6];

long long dfs(int last1, int last2) {
    bool fin = true;
    for(int i=0; i<n; i++) {
        if(nums[i] > 0) {
            fin = false;
            break;
        }
    }
    if(fin) return 1;

    if(dp[nums[0]][nums[1]][nums[2]][nums[3]][nums[4]][last1][last2] != -1) {
        return dp[nums[0]][nums[1]][nums[2]][nums[3]][nums[4]][last1][last2];
    }

    long long cnt = 0;
    for(int i=0; i<n; i++) {
        if(nums[i] > 0 && i != last1 && i != last2) {
            nums[i]--;
            cnt += dfs(i, last1);
            nums[i]++;
        }
    }

    return dp[nums[0]][nums[1]][nums[2]][nums[3]][nums[4]][last1][last2] = cnt;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    nums = vector<int>(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    memset(dp, -1, sizeof(dp));

    cout << dfs(n, n);

    return 0;
}