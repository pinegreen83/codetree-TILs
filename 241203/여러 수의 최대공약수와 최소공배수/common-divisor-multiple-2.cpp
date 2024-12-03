#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(int a, int b) {
    return (long long) a / gcd(a, b) * b;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int gcdRes = nums[0];
    long long lcmRes = nums[0];

    for(int i=1; i<n; i++) {
        gcdRes = gcd(gcdRes, nums[i]);
        lcmRes = lcm(lcmRes, nums[i]);
    }
    cout << gcdRes << " " << lcmRes;

    return 0;
}