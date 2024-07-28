#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    
    long long sum = 0;
    vector<int> nums(n);
    for(int i=0; i<n; i++) 
    {
        cin >> nums[i];
        sum += nums[i];
    }

    int comp1 = nums[0] + nums[1];
    int comp2 = nums[n-2] + nums[n-1];

    if(comp1 > comp2) cout << (sum - comp2) * 2;
    else cout << (sum - comp1) * 2;

    return 0;
}