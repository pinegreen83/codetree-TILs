#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> nums(n+1);
    nums[0] = 0;
    nums[1] = 1;
    for(int i=2; i<=n; i++)
    {
        nums[i] = (nums[i-2] + nums[i-1]) % 1'000'000'007;
    }
    cout << nums[n];

    return 0;
}