#include <iostream>
#include <unordered_map>

#define MAX_NUM 100000

using namespace std;
int n, k;
int nums[MAX_NUM];
unordered_map<int, int> umap;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> k;
    int a, ans = 0;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
        if(umap.find(nums[i]) == umap.end()) umap[nums[i]] = 1;
        else umap[nums[i]]++;
    }

    for(int i=0; i<n; i++)
    {
        int diff = k-nums[i];
        if(diff == nums[i]) ans += umap[diff]-1;
        else
        {
            if(umap.find(diff) != umap.end()) ans += umap[diff];
        }
    }
    cout << ans/2;

    return 0;
}