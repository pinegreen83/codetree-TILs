#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, sum = 0;
    cin >> n;

    vector<int> nums(n);
    for(int i=0; i<n; i++) 
    {
        cin >> nums[i];
        sum += nums[i];
    }

    long long cost = 0;
    for(int i=0; i<n-1; i++)
    {
        sum -= nums[i];
        cost += nums[i] * sum;
    }
    cout << cost;

    return 0;
}