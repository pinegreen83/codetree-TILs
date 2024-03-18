#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int sum = 0;
    for(int i=0; i<k; i++)
    {
        sum += nums[i];
    }

    int answer = sum;
    for(int i=0; i<n-k; i++)
    {
        sum -= nums[i];
        sum += nums[i+k];
        answer = max(answer, sum);
    }
    cout << answer;

    return 0;
}