#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, a, sum, minnum;
    cin >> n;
    vector<int> nums(n);
    priority_queue<int> pq;

    for(int i=0; i<n; i++) cin >> nums[i];

    minnum = nums[n-1];
    pq.push(nums[n-1]);
    sum += nums[n-1];
    minnum = min(minnum, nums[n-2]);
    pq.push(nums[n-2]);
    sum += nums[n-2];

    float avg = 0;
    for(int i=n-3; i>=0; i--)
    {
        float temp = (float) (sum - minnum) / (n-i-2);
        avg = max(avg, temp);
        sum += nums[i];
        minnum = min(minnum, nums[i]);
    }
    cout << fixed;
    cout.precision(2);
    cout << avg;
    
    return 0;
}