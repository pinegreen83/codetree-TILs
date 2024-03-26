#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, q;
    cin >> n >> q;
    vector<int> nums(n+1);
    for(int i=1; i<=n; i++) cin >> nums[i];

    vector<int> leftmax(n+1);
    leftmax[1] = nums[1];
    for(int i=2; i<=n; i++)
    {
        if(nums[i] > leftmax[i-1]) leftmax[i] = nums[i];
        else leftmax[i] = leftmax[i-1];
    }

    vector<int> rightmax(n+1);
    rightmax[n] = nums[n];
    for(int i=n-1; i>=1; i--)
    {
        if(nums[i] > rightmax[i+1]) rightmax[i] = nums[i];
        else rightmax[i] = rightmax[i+1];
    }

    while(q--)
    {
        int a, b;
        cin >> a >> b;
        if(leftmax[a-1] > rightmax[b+1]) cout << leftmax[a-1] << "\n";
        else cout << rightmax[b+1] << "\n";
    }

    return 0;
}