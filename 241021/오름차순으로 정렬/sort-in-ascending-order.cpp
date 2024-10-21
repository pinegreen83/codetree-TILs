#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    int nums[n];
    for(int i=0; i<n; i++) cin >> nums[i];

    sort(nums, nums+n);
    for(int i=0; i<n; i++) cout << nums[i] << " ";

    return 0;
}