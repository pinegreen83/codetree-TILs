#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }

    int ans = 0;
    unordered_map<int, int> umap;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int now = nums[i] + nums[j];
            if(umap.find(k-now) != umap.end()) ans += umap[k-now];
        }
        if(umap.find(nums[i]) == umap.end()) umap[nums[i]] = 1;
        else umap[nums[i]]++;
    }
    cout << ans;

    return 0;
}