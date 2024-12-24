#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int a, b;
    cin >> a >> b;

    cout << fixed;
    cout.precision(1);
    cout << ((float) (nums[a-1] + nums[b-1]) / 2);

    return 0;
}