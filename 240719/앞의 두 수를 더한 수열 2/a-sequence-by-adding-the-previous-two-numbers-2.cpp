#include <iostream>

#define MAX_N 90

using namespace std;

long long nums[MAX_N+1];

int main() {
    // 여기에 코드를 작성해주세요.
    nums[1] = 1;
    nums[2] = 1;
    int n;
    cin >> n;

    for(int i=3; i<=n; i++) nums[i] = nums[i-2] + nums[i-1];
    cout << nums[n];

    return 0;
}