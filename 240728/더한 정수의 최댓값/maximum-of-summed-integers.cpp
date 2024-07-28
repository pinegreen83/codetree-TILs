#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    
    long long sum = 0;
    vector<int> nums(n+1);
    for(int i=1; i<=n; i++) 
    {
        cin >> nums[i];
        sum += nums[i];
    }

    int comp1 = nums[1] + nums[2];
    int comp2 = nums[n-1] + nums[n];

    if(comp1 > comp2) cout << (sum - comp2) * 2;
    else cout << (sum - comp1) * 2;

    return 0;
}