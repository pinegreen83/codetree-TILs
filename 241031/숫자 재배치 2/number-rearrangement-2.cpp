#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    int nums[n];
    for(int i=0; i<n; i++) cin >> nums[i];
    for(int i=n-1; i>=0; i--) cout << nums[i] << " ";

    return 0;
}